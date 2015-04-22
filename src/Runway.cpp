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

Runway::Runway(Queue* queue, StatKeeper* stats, int tTime, int lTime)
{
	landingQueue = queue;
	runwayStats = stats;
	timeToTakeoff = tTime;
	timeToLand = lTime;
}
AirNode* Runway::getCurrentPlane()
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
	if(BoolSource::randBool(probTakeoff)){ takeoffQueue.addNewPlane(); } //adds plane to takeoffQueue randomly
	if(timeRemaining == 0 && currentPlane == takeoffQueue.peek())
	{
		currentPlane = NULL;
		runwayStats -> setTakeoffs(); //adds 1 to # of takeoffs
		runwayStats -> incrementTakeoffTime(timeToTakeoff);
		takeoffQueue.dequeue();
		checkQueues();
	}
	else if(timeRemaining == 0 && currentPlane == landingQueue -> peek())
	{
		currentPlane = NULL;
		runwayStats -> setLandings();
		runwayStats -> incrementLandingTime(timeToLand);
		landingQueue -> dequeue();
		checkQueues();
	}
	else
		timeRemaining--;
}
void Runway::checkQueues()
{
	if(landingQueue -> peek() != NULL){ 
		currentPlane = landingQueue -> peek();
		timeRemaining = timeToLand;
	}
	else if(takeoffQueue.peek() != NULL){
		currentPlane = takeoffQueue.peek();
		timeRemaining = timeToTakeoff;
	}
}
