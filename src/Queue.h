// =====================================================================================
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
//         Author:  Anna McDougald (), texas.tiel@gmail.com
//        Company:  
// 
// =====================================================================================

#ifndef QUEUE_H
#define QUEUE_H

#include "AirNode.h"

class Queue
{
    private:
	AirNode* head;
	AirNode* tail;
    public:
	Queue();
    	bool isEmpty();
	void addNewPlane();
	AirNode* dequeue();
	AirNode* peek();
};

#endif
