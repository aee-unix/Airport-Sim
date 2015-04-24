// Filename: BoolSource.cpp
// Author: Elyse McCoy

#include <cstdlib>
#include "BoolSource.h"

bool BoolSource::randBool(double prob)
{
    double value;
    value = rand() % 1009;
    if (value < prob * 1009){
	    return true;
    }
    return false;
}
