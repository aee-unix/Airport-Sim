//Name: main.cpp
//Date: 04/21/2015 09:09:15 PM
//Author: Elyse McCoy
//Purpose: Controls actions of AirportSim C++ project.

#include <iostream>
#include "Node.h"
#include "Airplane.h"
#include "BoolSource.h"
#include "Queue.h"
#include "Runway.h"
#include "StatKeeper.h"
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]){
    // Set seed for random number generation.
    srand (time(NULL));

   	//Checks if number of parameters is correct 
	if (argc != 8){
		cout << "Error! Invalid number of arguments.\n";
		return 1;
	}

    int land = atoi(argv[1]);
    int takeoff = atoi(argv[2]);
    double probLand = atof(argv[3]);
    double probTakeoff = atof(argv[4]);
    int start = atoi(argv[5]);
    int stop = atoi(argv[6]);
    int crash = atoi(argv[7]);
	
	//Declare objects
	Queue<Airplane *> queue;
	StatKeeper statkeeper;
	Runway runway(&queue, takeoff, land, probTakeoff);

	//Runs airport simulator
	for (statkeeper.setWorldTime(start); statkeeper.getWorldTime() > stop; statkeeper.incrementTime()){
	       	//Random time for fuel
		int fuel = rand() % crash;

		//If plane should land, land plane	
		if (BoolSource::randBool(probLand) == true){
			Airplane* airplane = new Airplane(fuel, statkeeper.getWorldTime());
			queue.addNewPlane(airplane);
		}

		runway.timestep();
	}

    statkeeper.printStats();

	return 0;
}
