// =====================================================================================
// 
//       Filename:  StatKeeper.cpp
// 
//    Description:  Keeps statistics about plans crashed, landed, and taken off.
// 
//        Version:  1.0
//        Created:  04/04/2015 02:19:57 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Eric Dilmore (), ericdilmore@gmail.com
//        Company:  
// 
// =====================================================================================

#include "StatKeeper.h"

int StatKeeper::getTotalTakeoffTime()
{
    return totalTakeoffTime;
}
int StatKeeper::getTotalLandingTime()
{
    return totalLandingTime;
}
int StatKeeper::getTakeoffs()
{
    return takeoffs;
}
int StatKeeper::getLandings()
{
    return landings;
}
int StatKeeper::getCrashes()
{
    return crashes;
}
void StatKeeper::incrementTakeoffTime(int time)
{
    // Blank body
}
void StatKeeper::incrementLandingTime(int time)
{
    // Blank body
}
void StatKeeper::setTakeoffs()
{
    // Blank body
}
void StatKeeper::setLandings()
{
    // Blank body
}
void StatKeeper::setCrashes()
{
    // Blank body
}
void StatKeeper::incrementTime()
{
    // Blank body
}
void StatKeeper::printStats()
{
    // Blank body
}
int StatKeeper::getAverageTime()
{
    return (double)(totalTakeoffTime + totalLandingTime) / (landings + takeoffs + crashes);
}
