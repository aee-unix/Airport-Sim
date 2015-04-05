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
    // Blank body
}
Airplane* Runway::getCurrentPlane()
{
    // Blank body
    return currentPlane;
}
Queue* Runway::getTakeoffQueue()
{
    // Blank body
    return &takeoffQueue;
}
int Runway::getTimeRemaining()
{
    // Blank body
    return timeRemaining;
}
void Runway::timestep()
{
    // Blank body
}
