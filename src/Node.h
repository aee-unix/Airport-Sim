// =====================================================================================
// 
//       Filename:  Node.h
// 
//    Description:  Header for Node class.
// 
//        Version:  1.0
//        Created:  04/02/2015 09:33:00 PM
//       Revision:  None
//       Compiler:  g++
// 
//         Author:  Anna McDougald (), texas.tiel@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef NODE_H
#define NODE_H

template < class T >
class Node
{
    private:
    // The value contained by the node.
    T value;
    // The next node in the linked list.
    Node<T>* next;
    public:
    // Constructor for Node.
    Node(T p, Node* np);
    // Destructor for Node.
    ~Node();
    // Return the value from the node.
    T getValue();
    // Return the next node in the linked list.
    Node<T>* getNext();
    // Set the next node in the linked list.
    void setNext(Node* n);
    // Set the next node in the linked list.
    void setValue(T p);
};

#include "Node.hpp"
#endif
