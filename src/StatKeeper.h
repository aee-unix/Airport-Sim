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
	int totalTakeoffTime;
	int totalLandingTime;
	int takeoffs;
	int landings;
	int crashes;
    	StatKeeper();
    public:
    	int getTotalTakeoffTime();
	int getTotalLandingTime();
	int getTakeoffs();
	int getLandings();
	int getCrashes();
	void incrementTakeoffTime(int time);
	void incrementLandingTime(int time);
	void setTakeoffs();
	void setLandings();
	void setCrashes();
    	void incrementTime();
	void printStats();
	int getAverageTime();
}

#endif
