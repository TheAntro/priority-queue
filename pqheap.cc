/*
 * file: pqheap.cc (Implements priority queue using the heap data structure.)
 * Valtteri Ranta, 10.6.2018
 */

#include "pqueue.hh"
#include <iostream>

PQueue::PQueue() {
    heap = new int[InitialArraySize];
    allocated = InitialArraySize;
    used = 0;
}

PQueue::~PQueue() {
    delete[] heap;
}

bool PQueue::isEmpty() {
    return (used == 0);
}

int PQueue::size() {
    return used;
}

void PQueue::enqueue(int newElem) {
    if (used == allocated) {
        doubleCapacity();
    }
    heap[used++] = newElem;
    insertToHeap((used-1), newElem);
    printDebuggingInfo();
}

// Insert to the last position in the heap, and work upwards from there to place to the correct spot
void PQueue::insertToHeap(int node, int newElem) {
    int parentNode = (node - 1)/2;
    if (heap[parentNode] >= newElem || node == 0) {
        //position correct, do nothing
    } else {
        swap(node, parentNode);
        insertToHeap(parentNode, newElem);
    }
}

int PQueue::dequeueMax() {
    if (isEmpty()) {
        std::cout << "Error: tried to dequeue from an empty queue" << std::endl;
        return -1;
    }
    int max = heap[0];
    swap(0, --used);
    maxHeapify(0);
    return max;
}

void PQueue::maxHeapify(int node) {
    int largest = node;
    int left = 2*node + 1;
    int right = 2*node + 2;
    if (heap[left] > heap[largest] && left < used) {
        largest = left;
    }
    if (heap[right] > heap[largest] && right < used) {
        largest = right;
    }
    if (largest == node) {
        // Correct position, do nothing
    } else {
        swap(largest, node);
        maxHeapify(largest);
    }
}

void PQueue::swap(int source, int destination) {
    int temp = heap[source];
    heap[source] = heap[destination];
    heap[destination] = temp;
}

void PQueue::doubleCapacity() {
    int *newHeap = new int[allocated * 2];
    for (int i = 0; i < used; i++) {
        newHeap[i] = heap[i];
    }
    int *old = heap;
    heap = newHeap;
    allocated *= 2;
    delete[] old;
}

/*
 * This function would not usually be included as part of the class,
 * but this is here as part of evaluating the tradeoffs betweem
 * implementations. Given a pqueue, this function counts up
 * and return the total amount of space used given its
 * current contents.
 */
int PQueue::bytesUsed() {
    return (sizeof(heap) + sizeof(allocated) + sizeof(used) + sizeof(InitialArraySize));
}

/*
 * Member function: implementationName
 * Usage: cout << pq.implementationName();
 * ---------------------------------------
 * This operation would not usually be included as part of the class
 * class, but is included to help with analyzing and reporting results.
 * This member function returns a string that describes the PQueue
 * implementation strategy ("sorted linked list", "vector", etc.).
 */
std::string PQueue::implementationName() {
    return "heap";
}

/*
 * Member function: printDebuggingInfo
 * Usage: pq.printDebuggingInfo();
 * -------------------------------
 * This operation would not usually be included as part of the class,
 * but is included to give you a hook to put any helpful debugging
 * print code (for example, something that prints the goopy details of
 * the internal structure). You don't need to implement this routine and can
 * ignore it entirely, but you may find it helpful to use as you are
 * doing development.
 */
void PQueue::printDebuggingInfo() {

}
