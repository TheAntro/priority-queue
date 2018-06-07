/*
 * File: pqvector.cc
 * ------------------
 * This file implements the priority queue class as a vector
 * of integers stored in no particular order.  This makes it easy
 * enqueue new elements, but hard to dequeue the max (have to search for it).
 *
 * Valtteri Ranta (github: waltherbeach), following Julie Zelenski, CS106
 */


#include "pqueue.hh"
#include <iostream>


PQueue::PQueue()
{
}


PQueue::~PQueue()
{
}


bool PQueue::isEmpty()
{
    return (entries.size() == 0);
}

int PQueue::size()
{
    return (entries.size());
}


/* Implementation notes: enqueue
 * -----------------------------
 * Since we're keeping the vector in no particular order, we just append this
 * new element to the end.  It's the easiest/fastest thing to do.
 */
void PQueue::enqueue(int newValue)
{
    entries.push_back(newValue);
}


/* Implementation notes: dequeueMax
 * --------------------------------
 * Since we're keeping the vector in no particular order, we have to search to
 * find the largest element.  Once found, we remove it from the vector and
 * return that value.
 */
int PQueue::dequeueMax()
{
    if (isEmpty()) {
        // Some hacked together Error-handling, as genlib not available from course CS106B
        std::cout << "Tried to dequeue max from an empty pqueue!" << std::endl;
        std::abort;
    }

    int maxIndex = 0;	// assume first element is largest until proven otherwise
    int maxValue = entries[0];
    for (int i = 1; i < entries.size(); i++) {
        if (entries[i] > maxValue) {
            maxValue = entries[i];
            maxIndex = i;
        }
    }
    entries.erase(entries.begin() + maxIndex);	// remove entry from vector (erase takes an iterator)
    return maxValue;
}

int PQueue::bytesUsed()
{
    return sizeof(*this) + sizeof(std::vector<int>) +  (sizeof(int) * entries.size());
}


std::string PQueue::implementationName()
{
    return "unsorted vector";
}

void PQueue::printDebuggingInfo()
{
    std::cout << "------------------ START DEBUG INFO ------------------" << std::endl;
    std::cout << "Pqueue contains " << entries.size() << " entries" << std::endl;
    for (int i = 0; i < entries.size(); i++)
        std::cout << entries[i] << " ";
    std::cout << std::endl;
    std::cout << "------------------ END DEBUG INFO ------------------" << std::endl;
}
/*
