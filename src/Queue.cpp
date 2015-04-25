// Filename: Queue.cpp
// Author: Elyse McCoy

#include "Queue.h"
#include "stdlib.h"

Queue::Queue()
    : head(NULL)
    , tail(NULL)
{
    // Blank body
}

Queue::~Queue()
{
    delete head;
}

// Tells user whether queue is empty or not
bool Queue::isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

// Adds airplane to queue
void Queue::addNewPlane(Airplane* airplane)
{
    if (head == NULL){
        Node* node = new Node(airplane, NULL);
        head = node;
        tail = node;
    }
    else{
        Node* node = new Node(airplane, NULL);
        tail->setNext(node);
        tail = node;
    }
}

// Removes airplane from queue
Airplane* Queue::dequeue()
{
    if (head == NULL)
        return NULL;
    else{
        Node* node = head;
        head = head->getNext();
        Airplane* airplane = node->getPlane();
        node->setNext(NULL);
        node->setPlane(NULL);
        delete node;
        return airplane;
    }
}

// Returns first airplane in queue
Airplane* Queue::peek()
{
    if (head == NULL)
        return NULL;
    else{
        Node* node = head;
        Airplane* airplane = node->getPlane();
        return airplane;
    }
}
