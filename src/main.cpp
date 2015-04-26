//Name: main.cpp
//Date: 04/21/2015 09:09:15 PM
//Author: Elyse McCoy
//Purpose: Controls actions of AirportSim C++ project.

#include <iostream>
#include "AirNode.h"
#include "Airplane.h"
#include "BoolSource.h"
#include "Queue.h"
#include "Runway.h"
#include "RunwayProc.h"
#include "StatKeeper.h"
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
using namespace std;

int main(int argc, char *argv[]){
    // Set seed for random number generation.
    srand (time(NULL));

   	//Checks if number of parameters is correct 
	if (argc != 8){
		cout << "Error! Invalid number of arguments.";
		return 1;
	}

    int land = atoi(argv[1]);
    int takeoff = atoi(argv[2]);
    double probLand = atof(argv[3]);
    double probTakeoff = atof(argv[4]);
    int start = atoi(argv[5]);
    int stop = atoi(argv[6]);
    int crash = atoi(argv[7]);

    StatKeeper::setWorldTime(start);
    StatKeeper::setEndTime(stop);
	
	//Declare objects
	Queue queue;
    int sigPipes[2];
    int doneSig;

    pipe(sigPipes);

	RunwayProc runway(&queue, takeoff, land, probTakeoff, sigPipes[1]);

	//Runs airport simulator
	for (StatKeeper::setWorldTime(start); StatKeeper::getWorldTime() > stop; StatKeeper::incrementTime()){
	       	//Random time for fuel
		int fuel = rand() % crash;

		//If plane should land, land plane	
		if (BoolSource::randBool(probLand) == true){
			Airplane* airplane = new Airplane(fuel, StatKeeper::getWorldTime());
			queue.addNewPlane(airplane);
		}

        kill(SIGUSR1, runway.getPid());
        read(sigPipes[0], &doneSig, sizeof(doneSig));
	}

	return 0;
}
