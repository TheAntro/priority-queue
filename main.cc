/* Created by Valtteri Ranta, GitHub: waltherbeach on 5th of June 2018, completed 10th of June 2018
 * Implements a priority queue using a vector, a linked list, a chunklist, and a heap
 * Current implementation uses a heap. Other implementations are included in the repository and need to be
 * added to the .pro file in place of pqheap.cc to take into use. Also: replace the private implementation
 * of pqueue.hh for the appropriate version
 *
 * Will not facilitate performance measurements for the implementations
 */

#include "pqueuetest.hh"
#include <iostream>

int main()
{
    BasicPQueueTest();
    MorePQueueTest();
    PQueueSortTest();
    std::cout << "Thanks and have a nice day!" << std::endl;
    return 0;
}
