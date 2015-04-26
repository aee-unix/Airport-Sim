// Filename: Queue.hpp
// Author: Elyse McCoy

#include "Queue.h"
#include "stdlib.h"

template < class T >
Queue<T>::Queue()
    : head(NULL)
    , tail(NULL)
{
    // Blank body
}

template < class T >
Queue<T>::~Queue()
{
    delete head;
}

// Tells user whether queue is empty or not
template < class T >
bool Queue<T>::isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}

// Adds value to queue
template < class T >
void Queue<T>::addNewPlane(T value)
{
    if (head == NULL){
        Node<T>* node = new Node<T>(value, NULL);
        head = node;
        tail = node;
    }
    else{
        Node<T>* node = new Node<T>(value, NULL);
        tail->setNext(node);
        tail = node;
    }
}

// Removes value from queue
template < class T >
T Queue<T>::dequeue()
{
    if (head == NULL)
        return NULL;
    else{
        Node<T>* node = head;
        head = head->getNext();
        T value = node->getValue();
        node->setNext(NULL);
        node->setValue(NULL);
        delete node;
        return value;
    }
}

// Returns first value in queue
template < class T >
T Queue<T>::peek()
{
    if (head == NULL)
        return NULL;
    else{
        Node<T>* node = head;
        T value = node->getValue();
        return value;
    }
}
