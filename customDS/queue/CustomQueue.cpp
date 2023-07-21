#include "CustomQueue.h"

// Constructor
template <typename T>
CustomQueue<T>::CustomQueue() : CustomVector<T>()
{
    // The CustomVector constructor will be called automatically.
    // No need to define anything here as we have already defined the CustomVector constructor.
}

// Enqueue an element to the back of the queue
template <typename T>
void CustomQueue<T>::enqueue(const T &value)
{
    // We can use the push_back method from CustomVector to add elements to the back of the queue.
    this->push_back(value);
}

// Dequeue an element from the front of the queue
template <typename T>
void CustomQueue<T>::dequeue()
{
    // We can remove an element from the front of the queue by shifting all elements one position to the left.
    if (!this->empty())
    {
        for (std::size_t i = 0; i < this->size() - 1; i++)
        {
            this->data[i] = this->data[i + 1];
        }
        this->currentSize--;
    }
}

// Get the front element of the queue
template <typename T>
T CustomQueue<T>::front() const
{
    // The front element of the queue is at index 0.
    return this->data[0];
}

// Check if the queue is empty
template <typename T>
bool CustomQueue<T>::empty() const
{
    // We can check if the queue is empty by checking if its size is 0.
    return this->size() == 0;
}
