/* File: pqchunklist.cc
 * Implementation of queue as a linked list, the objective is to use arrays in each cell to optimize efficiency
 * By Valtteri Ranta 8.6.2018
 * From CS106B, Julie Zelenski
 */

#include "pqueue.hh"
#include <iostream>
#include <sstream>

//A new queue is empty, and with no Cells, the head points to NULL
PQueue::PQueue() {
    head = NULL;
}

PQueue::~PQueue() {
    while (head != NULL) {
        Cell *next = head->next;
        delete head;
        head = next;
    }
}

bool  PQueue::isEmpty() {
    return (head == NULL);
}

int PQueue::size() {
    int count = 0;
    for (Cell *cur = head; cur != NULL; cur = cur->next) {
        count++;
    }
    return count;
}


void PQueue::enqueue(int newElem) {
    Cell *cur, *prev = new Cell;
    for (cur = head, prev = NULL; cur != NULL; prev = cur, cur = cur->next) {
        if (newElem > cur->values[0]) break;
    }
    // If prev points to NULL, list is either empty or new value is new max
    if (prev == NULL) {
        insertToNewCellAtHead(newElem);
    } else {
        insertToPreviousCell(newElem, prev);
    }
}

void PQueue::insertToNewCellAtHead(int newElem) {
    Cell *newCell = new Cell;
    newCell->values = new int[MaxBlockSize];
    newCell->values[0] = newElem;
    newCell->used = 1;

    // If the list is empty, the newcell is also the last, thus next is NULL
    if (head == NULL) {
        newCell->next = NULL;
    } else {
        newCell->next = head;
    }
    head = newCell;
    // Makes the chunklist use space more efficiently, but trades off some speed
    if (head->next != NULL && head->next->used < 2) {
        mergeCellsAtHead();
    }
}

void PQueue::mergeCellsAtHead() {
    for (int i = 0; i < head->next->used; i++) {
        head->values[head->used++] = head->next->values[i];
    }
    Cell *old = head->next;
    head->next = old->next;
    delete old;
}

void PQueue::insertToPreviousCell(int newElem, Cell *prev) {
    if (prev->used == MaxBlockSize) {
        Cell *splitCell = new Cell;
        splitCell->values = new int[MaxBlockSize];
        allocateSplitCell(prev, splitCell);
        // Splice the new cell in
        splitCell->next = prev->next;
        prev->next = splitCell;
        if (newElem <= splitCell->values[0]) {
            insertToCellArray(newElem, splitCell);
        } else {
            insertToCellArray(newElem, prev);
        }
    } else {
        insertToCellArray(newElem, prev);
    }
}

void PQueue::allocateSplitCell(Cell *original, Cell *splitted) {
    int pasteIndex = 0;
    int copyIndex = MaxBlockSize/2;
    while (copyIndex < MaxBlockSize) {
        splitted->values[pasteIndex++] = original->values[copyIndex++];
        original->used--;
        splitted->used++;
    }
}

void PQueue::insertToCellArray(int newElem, Cell *cell) {
    int index = 0;
    for (index; index < cell->used; index++) {
        if (newElem > cell->values[index]) {
            break;
        }
    }
    for (int j = cell->used; j > index; j--) {
        cell->values[j] = cell->values[j-1];
    }
    cell->values[index] = newElem;
    cell->used++;
}

int PQueue::dequeueMax() {
    if (isEmpty()) {
        std::cout << "Tried to dequeue from an empty queue!" << std::endl;
        return -1;
    }
    int max = head->values[0];
    head->used--;
    // In case of the dequeue emptying a cell, splice the cell off
    if (head->used == 0) {
        Cell *old = head;
        head = head->next;
        delete old;
    } else {
        for (int i = 0; i < head->used; i++) {
            head->values[i] = head->values[i+1];
        }
    }
    return max;
}

/* Implementation notes: bytesUsed
 * -------------------------------
 * The space needed is the sum of the object + the size of all the
 * allocated list cells.
 */
int PQueue::bytesUsed()
{
    int total = sizeof(*this);
    for (Cell *cur = head; cur != NULL; cur = cur->next)
        total += sizeof(*cur);
    return total;
}


std::string PQueue::implementationName()
{
    return "sorted unrolled linked list";
}

/*
 * Implementation notes: printDebuggingInfo
 * ----------------------------------------
 * The version for the singly-linked list prints the node structure
 * in order as a debugging aid to keeping track of the cell contents
 * and the pointers between them. It prints each cell in order
 */
void PQueue::printDebuggingInfo()
{
   int count = 0;
    std::cout << "------------------ START DEBUG INFO ------------------" << std::endl;
    for (Cell *cur = head; cur != NULL; cur = cur->next) {
       std::cout << "Cell #" << count << " (at address " << cur << ") val = " << printCellValues(cur)
             << " next = " << cur->next << std::endl;
       count++;
    }
    std::cout << "------------------ END DEBUG INFO ------------------" << std::endl;
}

std::string PQueue::printCellValues(Cell *cell) {
    std::stringstream values;
    values << "[ ";
    for (int i = 0; i < cell->used; i++) {
        values << cell->values[i] << " ";
    }
    values << "]";
    std::string arrayprint = values.str();
    return arrayprint;
}
