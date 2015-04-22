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
#include "StatKeeper.h"
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[]){
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
	
	//Declare objects
	Queue queue;
	StatKeeper statkeeper;
	Runway runway;

	//Runs airport simulator
	for (int currentMinute = start; currentMinute > stop; --currentMinute){
	       	//Random time for fuel
		srand (time(NULL));
		int fuel = rand() % crash;

		//If plane should land, land plane	
		if (BoolSource::randBool(probLand) == true){
			Airplane airplane = new Airplane(fuel, currentMinute);
			queue.push(airplane);
		}

		runway.timestep();

	}

	//Outputs number of planes
	cout << "Number of planes: " << statkeeper.setcrashes();

	return 0;
}
