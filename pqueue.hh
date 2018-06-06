/*
 * Defines the interface for the priority queue class, following the
 * interface definition of Julie Zelenski on CS106B, Fall 2007
 */

#ifndef PQUEUE_HH
#define PQUEUE_HH

#include <vector>
#include <string>

/*
 * Class: PQueue
 * -------------
 * This is the class for a priority queue.  This is not
 * simple FIFO queue, it is a priority queue, where elements are
 * retrieved in order of priority, not just by longevity in queue.
 * The elements are integers and the integer is assumed to represent
 * the priority (larger integer is higher priority).
 */
class PQueue {
public:

    //Initializes the queue to have no elements
    PQueue();

    //Disable copying by deleting the copy constructor
    PQueue(const PQueue&) = delete;

    //Deallocates all storage associated with the queue
    ~PQueue();

    bool isEmpty();
    int size();
    void enqueue(int newElem);
    int dequeueMax();

   /*
    * This function would not usually be included as part of the class,
    * but this is here as part of evaluating the tradeoffs betweem
    * implementations. Given a pqueue, this function counts up
    * and return the total amount of space used given its
    * current contents.
    */
   int bytesUsed();

   /*
    * Member function: implementationName
    * Usage: cout << pq.implementationName();
    * ---------------------------------------
    * This operation would not usually be included as part of the class
    * class, but is included to help with analyzing and reporting results.
    * This member function returns a string that describes the PQueue
    * implementation strategy ("sorted linked list", "vector", etc.).
    */
   std::string implementationName();

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
   void printDebuggingInfo();

private:

   std::vector<int> entries;
};

#endif // PQUEUE_HH
