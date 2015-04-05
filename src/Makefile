#Purpose: This makefile will compile and link all files needed for the Airport-Sim
#C++ project.

CC = g++
OBJECTS = Airplane.o Queue.o AirNode.o Runway.o StatKeeper.o BoolSource.o main.o
EXECUTABLE = AirportSim

AirportSim : $(OBJECTS)
	$(CC) -o $(EXECTUBABLE) $(OBJECTS)
Airplane.o : Airplane.cpp Airplane.h
	$(CC) -Wall -g -c Airplane.cpp
Queue.o : Queue.cpp Queue.h
	$(CC) -Wall -g -c Queue.cpp
AirNode.o : AirNode.cpp AirNode.h
	$(CC) -Wall -g -c AirNode.cpp
Runway.o : Runway.cpp Runway.h
	$(CC) -Wall -g -c Runway.cpp
StatKeeper.o : StatKeeper.cpp StatKeeper.h
	$(CC) -Wall -g -c StatKeeper.cpp
BoolSource.o : BoolSource.cpp BoolSource.h
	$(CC) -Wall -g -c BoolSource.cpp
main.o : main.cpp
	$(CC) -Wall -g -c main.cpp

clean :
	rm -rf $(OBJECTS) $(EXECUTABLE)
