// =====================================================================================
// 
//       Filename:  Queue.cpp
// 
//    Description:  Queue for Airplanes.
// 
//        Version:  1.0
//        Created:  04/04/2015 02:26:10 AM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Eric Dilmore (), ericdilmore@gmail.com
//        Company:  
// 
// =====================================================================================

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include "Queue.h"

Queue::Queue()
    : planes(0)
{
    int pipes[2];
    pipe(pipes);

    inPipe = pipes[0];
    outPipe = pipes[1];
}

Queue::~Queue()
{
    close(inPipe);
    close(outPipe);
}

bool Queue::isEmpty()
{
    return ( planes <= 0 );
}
void Queue::addNewPlane(Airplane * airplane)
{
    lockIn();

    write (inPipe, airplane, sizeof(*airplane));
    ++planes;

    unlockIn();
}
Airplane Queue::dequeue()
{
    lockOut();

    if ( !isEmpty() )
    {
        unlockOut();
        return Airplane(-1, -1);
    }

    Airplane airplane(0, 0);

    read(outPipe, &airplane, sizeof(airplane));

    unlockOut();

    return airplane;
}

void Queue::lockIn()
{
    flock(inPipe, LOCK_EX);
}
void Queue::lockOut()
{
    flock(outPipe, LOCK_EX);
}
void Queue::unlockIn()
{
    flock(inPipe, LOCK_UN);
}
void Queue::unlockOut()
{
    flock(outPipe, LOCK_UN);
}
