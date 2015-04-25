// =====================================================================================
// 
//       Filename:  RunwayProc.cpp
// 
//    Description:  Class to spin a new process controlling a single runway.
// 
//        Version:  1.0
//        Created:  04/25/2015 03:42:25 PM
//       Revision:  none
//       Compiler:  g++
// 
//         Author:  Eric Dilmore (), ericdilmore@gmail.com
//        Company:  
// 
// =====================================================================================

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <unistd.h>
#include "RunwayProc.h"

std::vector<int> RunwayProc::pidStore;

RunwayProc::RunwayProc(Queue* queue, int tTime, int lTime,
                       double prob, int fd)
    : runway(queue, tTime, lTime, prob)
    , sigFd(fd)
{
    if ((pid = fork()) == -1)
    {
        perror("Failed to fork in RunwayProc.");
        exit(-1);
    } else if (pid == 0)
    {
        run();
    } else
    {
        pidStore.push_back(pid);
    }
    return;
}

void RunwayProc::run()
{
    // Empty body
}

int RunwayProc::getPid()
{
    return pid;
}
