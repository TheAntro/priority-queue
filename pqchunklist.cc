/* File: pqchunklist.cc
 * Implementation of queue as a linked list, the objective is to use arrays in each cell to optimize efficiency
 * By Valtteri Ranta 8.6.2018
 * From CS106B, Julie Zelenski
 */

#include "pqueue.hh"
#include <iostream>

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

//TODO: Plenty of cleanup, possibly split into smaller functions
void PQueue::enqueue(int newElem) {
    Cell *cur, *prev, *newCell = new Cell;
    for (cur = head, prev = NULL; cur != NULL; prev = cur, cur = cur->next) {
        if (newElem > cur->values[0]) break;
    }
    // In case the list is empty, or the value is larger than previous max
    if (prev == NULL) {
        newCell->values = new int[MaxBlockSize];
        newCell->values[0] = newElem;
        newCell->used = 1;

        // If the list is empty, the newcell is also the last, thus next is NULL
        if (head == NULL) {
            newCell->next = NULL;
        // Else, there is already a first Cell, so set next to its next
        } else {
            newCell->next = head;
        }
        head = newCell;

    // In other cases, insertion into the array of a previous cell
        //TODO: Splitting cells when array is full
    } else {
        int index = 0;
        for (index; index < prev->used; index++) {
            if (newElem > prev->values[index]) {
                break;
            }
        }
        for (int j = prev->used; j > index; j--) {
            prev->values[j] = prev->values[j-1];
        }
        prev->values[index] = newElem;
        prev->used++;
    }
}

int PQueue::dequeueMax() {
    if (isEmpty()) {
        std::cout << "Tried to dequeue from an empty queue!" << std::endl;
        return -1;
    }
    int max = head->values[0];
    head->used--;
    // In case of the dequeue emptying a cell
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
    return "sorted linked list";
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
       std::cout << "Cell #" << count << " (at address " << cur << ") val = " << cur->values[0]
             << " next = " << cur->next << std::endl;
       count++;
    }
    std::cout << "------------------ END DEBUG INFO ------------------" << std::endl;
}
