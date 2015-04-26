// 
//       Filename:  Queue.h
// 
//    Description:  Header for Queue class.
// 
//        Version:  1.0
//        Created:  04/02/2015 09:26:00 PM
//       Revision:  None
//       Compiler:  g++
// 
//         Author:  Elyse McCoy
//        Company:  
// 
// =====================================================================================

#ifndef QUEUE_H
#define QUEUE_H

#include "Airplane.h"

class Queue
{
    private:
    int writePipe;
    int readPipe;
    Airplane * peeker;

    public:
    Queue();
    ~Queue();
	bool isEmpty();
    void addNewPlane(Airplane * airplane);
    Airplane * dequeue();

    void lockWrite();
    void lockRead();
    void unlockWrite();
    void unlockRead();
};

#endif
