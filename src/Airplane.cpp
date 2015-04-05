// =====================================================================================
// 
//       Filename:  Airplane.cpp
// 
//    Description:  Class to store Airplanes and related information, such as fuel.
// 
//        Version:  1.0
//        Created:  04/04/2015 02:16:00 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Eric Dilmore (), ericdilmore@gmail.com
//        Company:  
// 
// =====================================================================================

#include "Airplane.h"

Airplane::Airplane(int f, int t)
{
    fuel = f;
    timeIn = t;
}

int Airplane::getFuel()
{
    return fuel;
}
int Airplane::getTimeIn()
{
    return timeIn;
}
bool Airplane::isCrashed(int curTime)
{
    if((curTime - timeIn) >= fuel)
    	return true;
    else
        return false;
}
