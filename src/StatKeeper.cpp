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
#include <iostream>
using namespace std;

StatKeeper::totalTakeoffTime = 0;
StatKeeper::totalLandingTime = 0;
StatKeeper::takeoffs = 0;
StatKeeper::landings = 0;
StatKeeper::crashes = 0;
StatKeeper::worldTime = 0;

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
int StatKeeper::getWorldTime()
{
    return worldTime;
}
void StatKeeper::incrementTakeoffTime(int time)
{
    totalTakeoffTime += time;
}
void StatKeeper::incrementLandingTime(int time)
{
    totalLandingTime += time;
}
void StatKeeper::setTakeoffs()
{
    takeoffs++; //increments number of takeoffs by 1
}
void StatKeeper::setLandings()
{
    landings++; //increments the number of landings by 1
}
void StatKeeper::setCrashes()
{
    crashes++; //increments the number of crashes by 1
}
void StatKeeper::setWorldTime(int time)
{
    worldTime = time;
}
}
void StatKeeper::incrementTime()
{
    worldTime--;
}
void StatKeeper::printStats()
{
    cout << "Total time spent on takeoffs: " << totalTakeoffTime;
    cout << "\nTotal time spent on landings: " << totalLandingTime;
    cout << "\nTotal number of takeoffs: " << takeoffs;
    cout << "\nTotal number of landings: " << landings;
    cout << "\nTotal number of crashes: " << crashes;
    cout << "\nAverage wait to takeoff: " << getAverageTakeoffTime();
    cout << "\nAverage wait to land: " << getAverageLandingTime();
}
double StatKeeper::getAverageTakeoffTime()
{
    return (double)(totalTakeoffTime) / (takeoffs);
}
double StatKeeper::getAverageLandingTime()
{
    return (double) (totalLandingTime) / (landings + crashes);
}
