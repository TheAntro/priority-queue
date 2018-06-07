/* File: pqueuechunklist.cc
 * Implements the class PQueue with a chunklist as the data structure
 * Created by Valtteri Ranta, 7.6.2018
 */

#include "pqueue.hh"
#include <iostream>

PQueue::PQueue() {

}

PQueue::~PQueue() {

}

bool PQueue::isEmpty() {
    return true;
}

int PQueue::size() {
    return 0;
}

void PQueue::enqueue(int newElem) {

}

int PQueue::dequeueMax() {
    return 0;
}

int PQueue::bytesUsed() {
    return 0;
}

std::string PQueue::implementationName() {
    return "sorted chunklist";
}

void PQueue::printDebuggingInfo()
{
   int count = 0;

    std::cout << "------------------ START DEBUG INFO ------------------" << std::endl;

    std::cout << "------------------ END DEBUG INFO ------------------" << std::endl;
}

