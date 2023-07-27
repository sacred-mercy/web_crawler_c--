// #ifndef LIST_H
// #define LIST_H

// #include <iostream>

// // Node class to represent each element in the linked list
// template <typename T, typename U>
// class Node
// {
// public:
//     T domain;
//     U timeStapms;
//     Node *next;

//     Node(T value, U timeStapms)
//     {
//         domain = value;
//         this->timeStapms = timeStapms;
//         next = nullptr;
//     }
// };

// // CustomLinkedList class to manage the linked list operations
// template <typename T, typename U>
// class CustomLinkedList
// {
// private:
//     Node<T, U> *head;

// public:
//     CustomLinkedList() : head(nullptr) {}

//     ~CustomLinkedList()
//     {
//         clear();
//     }

//     // Method to add a new node at the end of the linked list
//     void append(T value, U timeStapms)
//     {
//         Node<T, U> *newNode = new Node<T, U>(value, timeStapms);
//         if (!head)
//         {
//             head = newNode;
//         }
//         else
//         {
//             Node<T, U> *current = head;
//             while (current->next)
//             {
//                 current = current->next;
//             }
//             current->next = newNode;
//         }
//     }

//     // Method to add a new node at the start of the linked list
//     void prepend(T value, U timeStapms)
//     {
//         if (!head)
//         {
//             head = new Node<T, U>(value, timeStapms);
//         }
//         else
//         {
//             Node<T, U> *newNode = new Node<T, U>(value, timeStapms);
//             newNode->next = head;
//             head = newNode;
//         }
//     }

//     // Method to remove a node with the given value from the linked list
//     void remove(T value)
//     {
//         if (!head)
//             return;

//         if (head->domain == value)
//         {
//             Node<T, U> *temp = head;
//             head = head->next;
//             delete temp;
//             return;
//         }

//         Node<T, U> *current = head;
//         while (current->next)
//         {
//             if (current->next->domain == value)
//             {
//                 Node<T, U> *temp = current->next;
//                 current->next = current->next->next;
//                 delete temp;
//                 return;
//             }
//             current = current->next;
//         }
//     }

//     // Method to clear the entire linked list
//     void clear()
//     {
//         Node<T> *current = head;
//         while (current)
//         {
//             Node<T> *temp = current;
//             current = current->next;
//             delete temp;
//         }
//         head = nullptr;
//     }

//     // Method to check if the linked list is empty
//     bool isEmpty() const
//     {
//         return head == nullptr;
//     }
// };

// #endif // LIST_H
