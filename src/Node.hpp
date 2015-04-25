// =====================================================================================
// 
//       Filename:  Node.hpp
// 
//    Description:  Node for the Queue
// 
//        Version:  1.0
//        Created:  04/04/2015 01:44:47 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Eric Dilmore (), ericdilmore@gmail.com
//        Company:  
// 
// =====================================================================================

#include "Node.h"

// Node constructor.
template < class T >
Node<T>::Node(T p, Node* np)
{
    value = p;
    next = np;
}
// Node destructor.
template < class T >
Node<T>::~Node()
{
    if ( next ) delete next;
    if ( value ) delete value;
}

// Return the value from the node.
template < class T >
T Node<T>::getValue()
{
    return value;
}
// Return the next node in the linked list.
template < class T >
Node<T>* Node<T>::getNext()
{
    return next;
}

// Set the next node in the linked list.
template < class T >
void Node<T>::setNext(Node* n)
{
    next = n;
}
// Set the next node in the linked list.
template < class T >
void Node<T>::setValue(T p)
{
    value = p;
}
