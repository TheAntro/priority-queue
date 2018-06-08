/* Created by Valtteri Ranta, GitHub: waltherbeach on 5th of June 2018
 * Will implement a priority queue using a vector, a linked list, a chunklist, and a heap
 * Will not facilitate performance measurements for the implementations
 */

#include "pqueuetest.hh"
#include <iostream>

int main()
{
    PQueue pq;
    pq.enqueue(1);
    pq.enqueue(5);
    pq.enqueue(3);
    pq.enqueue(6);
    for (int i = 0; i < 4; i++) {
        std::cout << pq.dequeueMax() << std::endl;
    }
    /*
    BasicPQueueTest();
    MorePQueueTest();
    PQueueSortTest();
    std::cout << "Thanks and have a nice day!" << std::endl;
    */
    return 0;
}
