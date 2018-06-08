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

void PQueue::enqueue(int newElem) {
    Cell *cur, *prev, *newCell = new Cell;
    for (cur = head, prev = NULL; cur != NULL; prev = cur, cur = cur->next) {
        if (newElem > cur->value) break;
    }
    newCell->value = newElem;
    newCell->next = cur;
    if (prev) {
        prev->next = newCell;
    } else {
        head = newCell;
    }
}

int PQueue::dequeueMax() {
    if (isEmpty()) {
        std::cout << "Tried to dequeue from an empty queue!" << std::endl;
        return -1;
    }
    int max = head->value;
    Cell *toBeDeleted = head;
    head = head->next;
    delete toBeDeleted;
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
       std::cout << "Cell #" << count << " (at address " << cur << ") val = " << cur->value
             << " next = " << cur->next << std::endl;
       count++;
    }
    std::cout << "------------------ END DEBUG INFO ------------------" << std::endl;
}
