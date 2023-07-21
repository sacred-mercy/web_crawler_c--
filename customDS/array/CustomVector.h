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

private:
    static const std::size_t DEFAULT_CAPACITY = 10;

    T *data;
    std::size_t currentSize;
    std::size_t capacity;

    // Helper function to resize the vector
    void resize(std::size_t newCapacity);
};

#endif // CUSTOMVECTOR_H
