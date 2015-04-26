// =====================================================================================
// 
//       Filename:  Runway.h
// 
//    Description:  Header for Runway class.
// 
//        Version:  1.0
//        Created:  04/02/2015 09:39:00 PM
//       Revision:  None
//       Compiler:  g++
// 
//         Author:  Anna McDougald (), texas.tiel@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef RUNWAY_H
#define RUNWAY_H

#include "Airplane.h"
#include "Queue.h"
#include "StatKeeper.h"
#include "BoolSource.h"

class Runway
{
    private:
    Queue<Airplane *> takeoffQueue;
    Queue<Airplane *>* landingQueue;
    StatKeeper* runwayStats;
    Airplane* currentPlane;
    int timeRemaining;
    int timeToTakeoff;
    int timeToLand;
    double probTakeoff;
    public:
    Runway(Queue<Airplane *>* queue, int tTime, int lTime, double prob);
    ~Runway();
    Airplane* getCurrentPlane();
    Queue<Airplane *>* getTakeoffQueue();
    Queue<Airplane *>* getLandingQueue();
    int getTimeRemaining();
    void timestep();
    void checkQueues();
};

#endif
