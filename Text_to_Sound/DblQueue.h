// File name: Queue_t.h
// Author: Hanliang Xu
// userid: xuh11
// Email: hanliang.xu@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 07
// Description: Maintains a queue of ItemType. Implements functions to enqueue, dequeue, retrieve
//              top, and retrieve size of the stack.
// Honor statement: I pledge that I finished this project myself.
// Last Changed:


#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>   // make gcc & CLion happy

template <typename ItemType>
class Queue
{
private:

    // the structure of a linked list node contains a single ItemType value and a next pointer
    struct Node {
        ItemType value;
        Node *next;
    };

    typedef Node* NodePtr;

    // Current size of the queue; i.e., how many elements are in the linked list
    size_t mySize;

    // Front and back of the queue
    NodePtr myFront;
    NodePtr myBack;

public:
    // Class Constructor
    Queue<ItemType>();

    // Copy Constructor
    // pre:  Class object, aQueue, exists
    // post: Object is initialized to be a copy of the parameter
    Queue<ItemType>(const Queue<ItemType>& rhs);

    // Class Destructor
    // Destroys a queue
    // pre:  Class object exists
    // post: Class object does not exist
    ~Queue<ItemType>();

    // Assignment operator
    // Assigns a queue to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const Queue<ItemType>& operator= (const Queue<ItemType>& rhs);

    // isEmpty
    // Checks if the queue is empty
    // pre:  A queue exists.
    // post: Returns true if it IS empty, false if NOT empty.
    bool isEmpty() const;

    // enqueue
    // enqueues an item to back of the queue.
    // pre:  DblQueue exists and item is passed.
    // post: adds the given item to the end of the queue.
    void enqueue(const ItemType& item);

    // dequeue
    // dequeues the front item off the queue
    // pre:  DblQueue exists.
    // post: Removes item on front of the queue. If the queue
    //       was already empty, throws an std::underflow_error exception.
    void dequeue();

    // front
    // Returns the front item of the queue without dequeueing it.
    // pre:  DblQueue exists.
    // post: Returns item at front of queue.  If the queue is empty,
    //       throws an std::underflow_error exception.
    ItemType front() const;

    // size
    // Returns the number of items on the queue.
    size_t size() const;

};

#include "DblQueue.cpp"
#endif