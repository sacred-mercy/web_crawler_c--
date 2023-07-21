// CustomVector.cpp

#include "CustomVector.h"

// Constructor
template <typename T>
CustomVector<T>::CustomVector()
{
    data = new T[DEFAULT_CAPACITY];
    currentSize = 0;
    capacity = DEFAULT_CAPACITY;
}

// Destructor
template <typename T>
CustomVector<T>::~CustomVector()
{
    delete[] data;
}

// Add an element to the vector
template <typename T>
void CustomVector<T>::push_back(const T &value)
{
    if (currentSize == capacity)
    {
        resize(capacity * 2);
    }

    data[currentSize] = value;
    currentSize++;
}

// Get an element at a specific index
template <typename T>
T CustomVector<T>::get(std::size_t index) const
{
    return data[index];
}

// Get the size of the vector
template <typename T>
std::size_t CustomVector<T>::size() const
{
    return currentSize;
}

// Helper function to resize the vector
template <typename T>
void CustomVector<T>::resize(std::size_t newCapacity)
{
    T *newData = new T[newCapacity];

    // copying data from old memory to new memory
    for (std::size_t i = 0; i < currentSize; i++)
    {
        newData[i] = data[i];
    }

    delete[] data;
    data = newData;
    capacity = newCapacity;
}
