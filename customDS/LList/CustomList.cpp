#include "CustomList.h"
#include <iostream>

template <typename T, typename U>
CustomList<T, U>::CustomList() : head(nullptr) {}

template <typename T, typename U>
CustomList<T, U>::~CustomList()
{
    while (head != nullptr)
    {
        Node<T, U> *temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T, typename U>
void CustomList<T, U>::push_front(T domain, U timestamps)
{
    Node<T, U> *newNode = new Node<T, U>(domain, timestamps);
    newNode->next = head;
    head = newNode;
}

template <typename T, typename U>
void CustomList<T, U>::push_back(T domain, U timestamps)
{
    if (head == nullptr)
    {
        head = new Node<T, U>(domain, timestamps);
        return;
    }
    Node<T, U> *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = new Node<T, U>(domain, timestamps);
}

template <typename T, typename U>
int CustomList<T, U>::size() const
{
    int count = 0;
    Node<T, U> *temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
