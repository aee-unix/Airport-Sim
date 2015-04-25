// =====================================================================================
// 
//       Filename:  RunwayProc.h
// 
//    Description:  Header for RunwayProc.
// 
//        Version:  1.0
//        Created:  04/25/2015 03:38:04 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Eric Dilmore (), ericdilmore@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef RUNWAYPROC_H
#define RUNWAYPROC_H

#include "Queue.h"
#include "Runway.h" 

class RunwayProc
{
    private:
    Runway runway;
    int sigFd;
    int pid;
    public:
    RunwayProc(Queue* queue, int tTime, int lTime, double prob, int fd);
    void run();
    int getPid();
}

#endif
