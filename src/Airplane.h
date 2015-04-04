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
        int fuel;
        int timeIn;
	bool crashed;
        Airplane(int fuel, int timeIn);
    public:
    	int getFuel();
	int getTimeIn();
	bool isCrashed();
}

#endif
