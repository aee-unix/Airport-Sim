#Purpose: This makefile will compile and link all files needed for the Airport-Sim
#C++ project.

AirportSim : Airplane.o Queue.o AirNode.o Runway.o StatKeeper.o BoolSource.o main.o
	g++ -o AirPortSim Airplane.o Queue.o Runway.o StatKeeper.o BoolSource.o main.o
Airplane.o : Airplane.cpp Airplane.h
	g++ -Wall -g -c Airplane.cpp
Queue.o : Queue.cpp Queue.h
	g++ -Wall -g -c Queue.h
AirNode.o : AirNode.cpp AirNode.h
	g++ -Wall -g -c AirNode.cpp
Runway.o : Runway.cpp Runway.h
	g++ -Wall -g -c Runway.cpp
StatKeeper.o : StatKeeper.cpp StatKeeper.h
	g++ -Wall -g -c StatKeeper.cpp
BoolSource.o : BoolSource.cpp BoolSource.h
	g++ -Wall -g -c BoolSource.cpp
main.o : main.cpp
	g++ -Wall -g -c main.cpp
