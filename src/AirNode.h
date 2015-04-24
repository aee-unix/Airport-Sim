// =====================================================================================
// 
//       Filename:  AirNode.h
// 
//    Description:  Header for AirNode class.
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

#ifndef AIRNODE_H
#define AIRNODE_H

#include "Airplane.h"

class AirNode
{
    private:
    // The plane contained by the node.
    Airplane* plane;
    // The next node in the linked list.
    AirNode* next;
    public:
    // Constructor for AirNode.
    AirNode(Airplane* p, AirNode* np);
    // Destructor for AirNode.
    ~AirNode();
    // Return the plane from the node.
    Airplane* getPlane();
    // Return the next node in the linked list.
    AirNode* getNext();
    // Set the next node in the linked list.
    void setNext(AirNode* n);
    // Set the next node in the linked list.
    void setPlane(Airplane* p);
};

#endif
