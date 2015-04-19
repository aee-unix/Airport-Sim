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

AirNode::AirNode(Airplane* p, AirNode* np)
{
    plane = p;
    next = np;
}
AirNode::~AirNode()
{
    if ( next ) delete next;
}

Airplane* AirNode::getPlane()
{
    return plane;
}

AirNode* AirNode::getNext()
{
    return next;
}

void AirNode::setNext(AirNode* n)
{
    next = n;
}
