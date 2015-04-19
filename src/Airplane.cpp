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

// Airplane constructor.
Airplane::Airplane(int f, int t)
{
    fuel = f;
    timeIn = t;
}

// Return the amount of fuel at the time the plane entered the airspace.
int Airplane::getFuel()
{
    return fuel;
}
// Return the time that the plane entered the airspace.
int Airplane::getTimeIn()
{
    return timeIn;
}
// Return whether a plane has crashed due to lack of fuel at a given time.
bool Airplane::isCrashed(int curTime)
{
    if((curTime - timeIn) >= fuel)
        return true;
    else
        return false;
}
