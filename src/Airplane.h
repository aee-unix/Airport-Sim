// =====================================================================================
// 
//       Filename:  Airplane.h
// 
//    Description:  Header for Airplane class.
// 
//        Version:  1.0
//        Created:  03/24/2015 08:23:26 PM
//       Revision:  None
//       Compiler:  g++
// 
//         Author:  Eric Dilmore (), ericdilmore@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef AIRPLANE_H
#define AIRPLANE_H

class Airplane
{
    private:
    // Amount of fuel when the plane enters the airspace.
    int fuel;
    // Time when the plane entered the airspace.
    int timeIn;
    public:
    // Constructor for Airplane.
    Airplane(int fuel, int timeIn);
    // Return the amount of fuel at the time the plane entered the airspace.
    int getFuel();
    // Return the time that the plane entered the airspace.
    int getTimeIn();
    // Return whether a plane has crashed due to lack of fuel at given time.
    bool isCrashed(int curTime);
};

#endif
