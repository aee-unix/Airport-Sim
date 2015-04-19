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
    Airplane* plane;
    AirNode* next;
    public:
    AirNode(Airplane* p, AirNode* np);
    Airplane* getPlane();
    AirNode* getNext();
    void setNext(AirNode* n);
};

#endif
