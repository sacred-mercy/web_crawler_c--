#ifndef CUSTOMVECTOR_H
#define CUSTOMVECTOR_H

#include <cstddef> // for std::size_t

template <typename T>
class CustomVector
{
public:
    // Constructor
    CustomVector();

    // Destructor
    ~CustomVector();

    // Add an element to the vector
    void push_back(const T &value);

    // Get an element at a specific index
    T get(std::size_t index) const;

    // Get the size of the vector
    std::size_t size() const;

    // Reserve memory for the vector
    void reserve(std::size_t newCapacity);

protected:
    static const std::size_t DEFAULT_CAPACITY = 10;

    T *data;
    std::size_t currentSize;
    std::size_t capacity;

    // Helper function to resize the vector
    void resize(std::size_t newCapacity);
};

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

// Reserve memory for the vector
template <typename T>
void CustomVector<T>::reserve(std::size_t newCapacity)
{
    if (newCapacity <= capacity)
    {
        return; // No need to reserve if the new capacity is less than or equal to the current capacity
    }

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

#endif // CUSTOMVECTOR_H
