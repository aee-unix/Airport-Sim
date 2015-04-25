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
#include <iostream>
#include "RunwayProc.h"

using namespace std;

RunwayProc::RunwayProc(Queue* queue, int tTime, int lTime,
                       double prob, int fd)
    : runway(queue, tTime, lTime, prob)
    , sigFd(fd)
{
    // Empty body
}

void RunwayProc::run()
{
    // Empty body
}

int RunwayProc::getPid()
{
    return pid;
}
