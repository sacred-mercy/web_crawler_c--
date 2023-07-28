#ifndef CUSTOMLIST_H
#define CUSTOMLIST_H

template <typename T, typename U>
class Node
{
public:
    T domain;
    U timestamps;
    Node<T, U> *next;
    Node(T domain, U timestamps) : domain(domain), timestamps(timestamps), next(nullptr) {}
};

template <typename T, typename U>
class CustomList
{
private:
    Node<T, U> *head;

public:
    CustomList();
    ~CustomList();
    void push_front(T domain, U timestamps);
    void push_back(T domain, U timestamps);
    int size() const;
};

#endif
