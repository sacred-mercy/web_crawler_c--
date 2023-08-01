// #include "CustomHashSet.h"

// // Constructor
// template <typename T>
// CustomHashSet<T>::CustomHashSet(std::size_t capacity) : capacity(capacity), size(0)
// {
//     table = new CustomLinkedList<T>[capacity];
// }

// // Destructor
// template <typename T>
// CustomHashSet<T>::~CustomHashSet()
// {
//     delete[] table;
// }

// // Hash function to generate an index from a CustomString value
// template <typename T>
// std::size_t CustomHashSet<T>::hash(const T &value) const
// {
//     std::size_t sum = 0;

//     std::cout << "Hashing: '" << value << "' ";
//     // create a hash algorithm by using the ASCII value of each character
//     for (std::size_t i = 0; i < value.length(); i++)
//     {
//         sum += value.at(i) * (i + 1) * 31;
//     }
//     return sum % capacity;
// }

// // Insert an element into the hash set
// template <typename T>
// void CustomHashSet<T>::insert(const T &value)
// {
//     std::size_t index = hash(value);
//     table[index].insert(value);
//     size++;

//     // Rehash if the load factor is greater than 70%
//     if (size > capacity * 0.7)
//     {
//         rehash();
//     }
// }

// // Check if an element exists in the hash set
// template <typename T>
// bool CustomHashSet<T>::contains(const T &value) const
// {
//     std::size_t index = hash(value);
//     std::cout << "Index: " << index << " ";
//     return table[index].contains(value);
// }

// // Get the number of elements in the hash set
// template <typename T>
// std::size_t CustomHashSet<T>::getSize() const
// {
//     return size;
// }

// // Rehash the hash set
// template <typename T>
// void CustomHashSet<T>::rehash()
// {
//     std::size_t newCapacity = capacity * 2;
//     CustomLinkedList<T> *newTable = new CustomLinkedList<T>[newCapacity];

//     int oldCapacity = capacity;

//     capacity = newCapacity; // Update the capacity for hash function

//     for (std::size_t i = 0; i < oldCapacity; i++)
//     {
//         Node<T> *current = table[i].head;
//         while (current != nullptr)
//         {
//             std::size_t index = hash(current->data);
//             newTable[index].insert(current->data);
//             current = current->next;
//         }
//     }

//     delete[] table;
//     table = newTable;
// }

// // Print the hash set
// template <typename T>
// void CustomHashSet<T>::print() const
// {
//     for (std::size_t i = 0; i < capacity; i++)
//     {
//         std::cout << "Index: " << i << " Address: " << &table[i] << std::endl;
//         table[i].print();
//     }
// }