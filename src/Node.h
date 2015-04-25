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

#include "Airplane.h"

class Node
{
    private:
    // The plane contained by the node.
    Airplane* plane;
    // The next node in the linked list.
    Node* next;
    public:
    // Constructor for Node.
    Node(Airplane* p, Node* np);
    // Destructor for Node.
    ~Node();
    // Return the plane from the node.
    Airplane* getPlane();
    // Return the next node in the linked list.
    Node* getNext();
    // Set the next node in the linked list.
    void setNext(Node* n);
    // Set the next node in the linked list.
    void setPlane(Airplane* p);
};

#endif
