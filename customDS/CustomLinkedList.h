#ifndef CUSTOMLINKEDLIST_H
#define CUSTOMLINKEDLIST_H

#include <CustomString.h>

// Forward declaration of CustomHashSet class
template <typename T>
class CustomHashSet;

template <typename T>
struct Node
{
    T data;
    Node<T> *next;

    Node(const T &value) : data(value), next(nullptr) {}
};

// CustomLinkedList class declaration
template <typename T>
class CustomLinkedList
{
private:
    Node<T> *head;

public:
    CustomLinkedList();
    ~CustomLinkedList();

    void insert(const T &value);
    bool contains(const T &value) const;
    void print() const;

    // Friend declaration for rehash() in CustomHashSet
    template <typename U>
    friend void CustomHashSet<U>::rehash();
};

// Constructor
template <typename T>
CustomLinkedList<T>::CustomLinkedList() : head(nullptr)
{
}

// Destructor
template <typename T>
CustomLinkedList<T>::~CustomLinkedList()
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }
}

// Insert an element into the linked list
template <typename T>
void CustomLinkedList<T>::insert(const T &value)
{
    Node<T> *newNode = new Node<T>(value);
    newNode->next = head;
    head = newNode;
}

// Check if an element exists in the linked list
template <typename T>
bool CustomLinkedList<T>::contains(const T &value) const
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true; // Element found
        }
        current = current->next;
    }
    return false; // Element not found
}

// Print the linked list
template <typename T>
void CustomLinkedList<T>::print() const
{
    Node<T> *current = head;
    while (current != nullptr)
    {
        std::cout << "'" << current->data << "'"
                  << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif // CUSTOMLINKEDLIST_H
