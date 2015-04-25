// =====================================================================================
// 
//       Filename:  Node.cpp
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
Node::Node(Airplane* p, Node* np)
{
    plane = p;
    next = np;
}
// Node destructor.
Node::~Node()
{
    if ( next ) delete next;
    if ( plane ) delete plane;
}

// Return the plane from the node.
Airplane* Node::getPlane()
{
    return plane;
}
// Return the next node in the linked list.
Node* Node::getNext()
{
    return next;
}

// Set the next node in the linked list.
void Node::setNext(Node* n)
{
    next = n;
}
// Set the next node in the linked list.
void Node::setPlane(Airplane* p)
{
    plane = p;
}
