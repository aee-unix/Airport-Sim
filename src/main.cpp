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
#include <vector>
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

    vector<RunwayProc> runways;
    runways.push_back(RunwayProc(&queue, takeoff, land, probTakeoff, sigPipes[1]));
    runways.push_back(RunwayProc(&queue, takeoff, land, probTakeoff, sigPipes[1]));

	//Runs airport simulator
	for (StatKeeper::setWorldTime(start); StatKeeper::getWorldTime() > stop; StatKeeper::incrementTime()){
        // Query runways to see if they are done.
        for (unsigned int i = 0; i < runways.size(); ++i)
        {
            read(sigPipes[0], &doneSig, sizeof(doneSig));
        }

        //Random time for fuel
		int fuel = rand() % crash;

		//If plane should land, land plane	
		if (BoolSource::randBool(probLand) == true){
			Airplane* airplane = new Airplane(fuel, StatKeeper::getWorldTime());
            queue.lockWrite();
			queue.addNewPlane(airplane);
            queue.unlockWrite();
		}

        // Resume all runways.
        for (vector<RunwayProc>::iterator runway = runways.begin();
             runway != runways.end();
             ++runway)
        {
            runway->resume();
        }
	}
    // Resume all runways once more to make up for starting first.
    for (vector<RunwayProc>::iterator runway = runways.begin();
         runway != runways.end();
         ++runway)
    {
        cout << "Runway " << distance(runways.begin(), runway) + 1 << endl;
        runway->resume();
        read(sigPipes[0], &doneSig, sizeof(doneSig));
        if (runway + 1 != runways.end())
        {
            sleep(1);
            cout << endl;
        }
    }

	return 0;
}
