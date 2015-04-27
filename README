This is the git repository for the CS 3376 final project. Authors include Anna McDougald, Elyse McCoy, and Eric Dilmore. Our programming log is located at the following location: https://docs.google.com/document/d/1Io_E0gqTMtQvDbemlZ4wm16apYFqo8Uihs9MMgAouDc/edit?usp=sharing. Our entire project is hosted on GitHub at https://github.com/aee-unix/Airport-Sim/

The single-runway version is on the master branch. Input and output is as defined in the project specs. Make and run the file with:
	cd src
	make
	./AirportSim landTime takeoffTime landProb takeoffProb startTime endTime maxFuel

The multiple-runway version is on the multi-master branch. Change to this branch by running the following command from anywhere in the project directory:
	git checkout multi-master
You will need to make the program a second time after checking out a new branch. Statistics are processed on a per-runway basis. Make and run the files with:
	cd src
	make
	./AirportSim landTime takeoffTime landProb takeoffProb startTime endTime maxFuel runwayCount

Note that the multiple-runway version utilizes multiple processes, with a process per branch. They synchronize together using a series of fifo pipes connecting the parent node (controlling the landing planes) and the runways (which each have their own takeoff queues). Also note that the processes have no inherent order for taking planes from the shared landing queue, but due to the nature of starting the queues with individual pipes, earlier runways tend to take more landing planes when the queue is close to empty.
