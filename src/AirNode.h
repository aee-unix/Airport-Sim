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

class AirNode
{
    private:
    Airplane* plane;
    Airplane* nextplane;
    AirNode(Airplane* p, Airplane* np);
    public:
    Airplane* getPlane();
    Airplane* getNextPlane();
    void setNextPlane(Airplane* p);
}

#endif
