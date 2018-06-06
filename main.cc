/* Created by Valtteri Ranta, GitHub: waltherbeach on 5th of June 2018
 * Will implement a priority queue using a vector, a linked list, a chunklist, and a heap
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
