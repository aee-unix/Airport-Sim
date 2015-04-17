// =====================================================================================
// 
//       Filename:  Runway.cpp
// 
//    Description:  Runway to handle plane takeoffs and landings.
// 
//        Version:  1.0
//        Created:  04/04/2015 02:28:43 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Eric Dilmore (), ericdilmore@gmail.com
//        Company:  
// 
// =====================================================================================

#include "Runway.h"

Runway::Runway(Airplane* plane, int time)
{
    currentPlane = plane;
    timeRemaining = time;
}
Airplane* Runway::getCurrentPlane()
{
    return currentPlane;
}
Queue* Runway::getTakeoffQueue()
{
    return &takeoffQueue;
}
int Runway::getTimeRemaining()
{
    return timeRemaining;
}
void Runway::timestep()
{
    //if plane is not landing, take plane from top of takeoff queue and make it
    //the currentPlane
    timeRemaining--;
}
