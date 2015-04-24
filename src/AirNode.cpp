// =====================================================================================
// 
//       Filename:  AirNode.cpp
// 
//    Description:  Node for Queue holding airplanes
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

#include "AirNode.h"

// AirNode constructor.
AirNode::AirNode(Airplane* p, AirNode* np)
{
    plane = p;
    next = np;
}
// AirNode destructor.
AirNode::~AirNode()
{
    if ( next ) delete next;
    if ( plane ) delete plane;
}

// Return the plane from the node.
Airplane* AirNode::getPlane()
{
    return plane;
}
// Return the next node in the linked list.
AirNode* AirNode::getNext()
{
    return next;
}

// Set the next node in the linked list.
void AirNode::setNext(AirNode* n)
{
    next = n;
}
// Set the next node in the linked list.
void AirNode::setPlane(Airplane* p)
{
    plane = p;
}
