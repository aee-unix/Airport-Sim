// =====================================================================================
// 
//       Filename:  StatKeeper.h
// 
//    Description:  Header for StatKeeper class.
// 
//        Version:  1.0
//        Created:  04/02/2015 09:47:00 PM
//       Revision:  None
//       Compiler:  g++
// 
//         Author:  Anna McDougald (), texas.tiel@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef STATKEEPER_H
#define STATKEEPER_H

class StatKeeper
{
    private:
    static int totalTakeoffTime;
    static int totalLandingTime;
    static int takeoffs;
    static int landings;
    static int crashes;
    static int worldTime;
    static int totalSimTime;
    public:
    static int getTotalTakeoffTime();
    static int getTotalLandingTime();
    static int getTakeoffs();
    static int getLandings();
    static int getCrashes();
    static int getWorldTime();
    static void incrementTakeoffTime(int time);
    static void incrementLandingTime(int time);
    static void setTakeoffs();
    static void setLandings();
    static void setCrashes();
    static void setWorldTime(int time);
    static void incrementTime();
    static void printStats();
    static double getAverageTakeoffTime();
    static double getAverageLandingTime();
};

#endif
