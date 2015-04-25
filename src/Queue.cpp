// Filename: Queue.cpp
// Author: Elyse McCoy

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

    writePipe = pipes[1];
    readPipe = pipes[0];
}

Queue::~Queue()
{
    close(writePipe);
    close(readPipe);
}

// Tells user whether queue is empty or not
bool Queue::isEmpty()
{
    return ( planes <= 0 );
}
void Queue::addNewPlane(Airplane * airplane)
{
    write (writePipe, airplane, sizeof(*airplane));
    ++planes;
}
Airplane * Queue::dequeue()
{
    if ( isEmpty() )
    {
        return NULL;
    }

    Airplane * airplane = new Airplane(0, 0);

    read(readPipe, airplane, sizeof(*airplane));
    
    --planes;

    return airplane;
}

void Queue::lockWrite()
{
    flock(writePipe, LOCK_EX);
}
void Queue::lockRead()
{
    flock(readPipe, LOCK_EX);
}
void Queue::unlockWrite()
{
    flock(writePipe, LOCK_UN);
}
void Queue::unlockRead()
{
    flock(readPipe, LOCK_UN);
}
