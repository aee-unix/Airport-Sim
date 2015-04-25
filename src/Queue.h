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
//         Author:  Elyse McCoy
//        Company:  
// 
// =====================================================================================

#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"

class Queue
{
    private:
    Node* head;
    Node* tail;
    public:
    Queue();
    ~Queue();
    bool isEmpty();
    void addNewPlane(Airplane*);
    Airplane* dequeue();
    Airplane* peek();
};

#endif
