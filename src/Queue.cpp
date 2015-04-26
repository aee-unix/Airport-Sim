// Filename: Queue.cpp
// Author: Elyse McCoy

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/file.h>
#include "Queue.h"

Queue::Queue()
    : peeker(NULL)
{
    int pipes[2];
    pipe(pipes);

    writePipe = pipes[1];
    readPipe = pipes[0];

    int flags = fcntl(readPipe, F_GETFL, 0);
    fcntl(readPipe, F_SETFL, flags | O_NONBLOCK);
}

Queue::~Queue()
{
    close(writePipe);
    close(readPipe);
}

// Tells user whether queue is empty or not
bool Queue::isEmpty()
{
    if (peeker == NULL)
    {
        peeker = (Airplane *) malloc(sizeof(*peeker));
        int status = read(readPipe, peeker, sizeof(*peeker));
        if (status == -1)
        {
            free(peeker);
            peeker = NULL;
        }
    }

    return ( peeker == NULL );
}
void Queue::addNewPlane(Airplane * airplane)
{
    write (writePipe, airplane, sizeof(*airplane));
    delete airplane;
}
Airplane * Queue::dequeue()
{
    isEmpty();

    Airplane * airplane = peeker;
    peeker = NULL;

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
