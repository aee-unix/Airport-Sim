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
#include <signal.h>
#include <sys/types.h>
#include "RunwayProc.h"

std::vector<int> RunwayProc::pidStore;

void donothing(int signum)
{
    // Empty body
}

RunwayProc::RunwayProc(Queue* queue, int tTime, int lTime,
                       double prob, int fd)
    : runway(queue, tTime, lTime, prob)
    , sigFd(fd)
{
    pipe(contPipes);

    if ((pid = fork()) == -1)
    {
        perror("Failed to fork in RunwayProc.");
        exit(-1);
    } else if (pid == 0)
    {
        run();
        exit(0);
    } else
    {
        pidStore.push_back(pid);
    }
    return;
}

void RunwayProc::run()
{
    signal(SIGUSR1, donothing);

    write(sigFd, &pid, sizeof(pid));
    waitForResume();
    for (;
         StatKeeper::getWorldTime() > StatKeeper::getEndTime();
         StatKeeper::incrementTime())
    {
        runway.timestep();
        write(sigFd, &pid, sizeof(pid));
        waitForResume();
    }

    StatKeeper::printStats();
}

int RunwayProc::getPid()
{
    return pid;
}

void RunwayProc::waitForResume()
{
    int status = 0;
    read(contPipes[0], &status, sizeof(status));
}

void RunwayProc::resume()
{
    int status = 1;
    write(contPipes[1], &status, sizeof(status));
}
