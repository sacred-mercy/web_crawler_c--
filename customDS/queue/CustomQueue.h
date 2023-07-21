#ifndef CUSTOMQUEUE_H
#define CUSTOMQUEUE_H

#include "./../array/CustomVector.h"

template <typename T>
class CustomQueue : public CustomVector<T>
{
public:
    // Constructor
    CustomQueue();

    // Destructor (Note: You don't need to redefine the destructor if it doesn't have additional functionality.)

    // Enqueue an element to the back of the queue
    void enqueue(const T &value);

    // Dequeue an element from the front of the queue
    void dequeue();

    // Get the front element of the queue
    T front() const;

    // Check if the queue is empty
    bool empty() const;
};

#endif // CUSTOMQUEUE_H
