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

#include "Queue.h"
#include "Airplane.h"

class Runway
{
    private:
	Queue takeoffQueue;
	Airplane* currentPlane;
	int timeRemaining;
    public:
	Runway(Airplane* plane, int time);
    	Airplane* getCurrentPlane();
	Queue* getTakeoffQueue();
	int getTime();
    	void timestep();
};

#endif
