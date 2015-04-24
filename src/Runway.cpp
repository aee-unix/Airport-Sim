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
#include <cstdlib>

Runway::Runway(Queue* queue, int tTime, int lTime, double prob)
{
    landingQueue = queue;
    timeToTakeoff = tTime;
    timeToLand = lTime;
    probTakeoff = prob;
    currentPlane = NULL;
}
Airplane* Runway::getCurrentPlane()
{
    return currentPlane;
}
Queue* Runway::getTakeoffQueue()
{
    return &takeoffQueue;
}
Queue* Runway::getLandingQueue()
{
    return landingQueue;
}
int Runway::getTimeRemaining()
{
    return timeRemaining;
}
void Runway::timestep()
{
    //adds plane to takeoffQueue randomly
    if(BoolSource::randBool(probTakeoff))
        takeoffQueue.addNewPlane(new Airplane(0, StatKeeper::getWorldTime()));
	if(timeRemaining > 0 && currentPlane != NULL) timeRemaining--;
    else if(currentPlane == NULL)
    {
        checkQueues();
    }
    if(timeRemaining == 0)
    {
        delete currentPlane;
        currentPlane = NULL;
    }
}
void Runway::checkQueues()
{
    if(landingQueue -> peek() != NULL){ 
        currentPlane = landingQueue -> dequeue();
        timeRemaining = timeToLand;
        if(currentPlane -> isCrashed(StatKeeper::getWorldTime())){
            currentPlane = NULL;
            StatKeeper::setCrashes();
            return;
        }
        StatKeeper::setLandings();
        StatKeeper::incrementLandingTime((currentPlane -> getTimeIn()) - StatKeeper::getWorldTime());
    }
    else if(takeoffQueue.peek() != NULL){
        currentPlane = takeoffQueue.dequeue();
        timeRemaining = timeToTakeoff;
        StatKeeper::setTakeoffs();
        StatKeeper::incrementTakeoffTime((currentPlane -> getTimeIn()) - StatKeeper::getWorldTime());
    }
}
