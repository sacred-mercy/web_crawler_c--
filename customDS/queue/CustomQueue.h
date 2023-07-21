#ifndef CUSTOMQUEUE_H
#define CUSTOMQUEUE_H

#include "./queue/CustomQueue.h"

template <typename T>
class CustomQueue
{
public:
    // Constructor
    CustomQueue();

    // Destructor
    ~CustomQueue();

    // Add an element to the back of the queue
    void enqueue(const T &value);

    // Remove and return the front element of the queue
    T dequeue();

    // Get the front element of the queue without removing it
    T front() const;

    // Check if the queue is empty
    bool empty() const;

    // Get the size of the queue
    std::size_t size() const;

private:
    CustomVector<T> data;
};

// Include the implementation in the header file
#include "CustomQueue.cpp"

#endif // CUSTOMQUEUE_H
