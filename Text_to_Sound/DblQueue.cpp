// File name: Queue_t.cpp
// Author: Hanliang Xu
// userid: xuh11
// Email: hanliang.xu@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 07
// Description: Maintains a queue of ItemType. Implements functions to enqueue, dequeue, retrieve
//              top, and retrieve size of the stack.
// Honor statement: I pledge that I finished this project myself.
// Last Changed:

#include <algorithm>

// Class Constructor
template <typename ItemType>
Queue<ItemType>::Queue() : mySize(0), myFront(nullptr), myBack(nullptr) {
}

// Copy Constructor
// pre:  Class object, aQueue, exists
// post: Object is initialized to be a copy of the parameter
template <typename ItemType>
Queue<ItemType>::Queue(const Queue<ItemType> &rhs): mySize(rhs.mySize), myFront(nullptr),
                                                    myBack(nullptr) {
    if (rhs.myFront != nullptr) {
        // copy first node
        myFront = new Node;
        myFront->value = rhs.myFront->value;
        myFront->next = rhs.myFront->next;
        // copy rest of the list
        NodePtr newPtr = myFront;
        NodePtr origPtr = rhs.myFront;
        while (origPtr->next != nullptr) {
            origPtr = origPtr->next;
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->value = origPtr->value;
            newPtr->next = nullptr;
        }
        myBack = newPtr;
    }
}

// Class Destructor
// Destroys a queue
// pre:  Class object exists
// post: Class object does not exist
template <typename ItemType>
Queue<ItemType>::~Queue() {
    while (myFront != nullptr) {
        NodePtr tmp = myFront;
        myFront = myFront->next;
        delete tmp;
    }
    myBack = nullptr;
    mySize = 0;
}

// Assignment operator
// Assigns a queue to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template <typename ItemType>
const Queue<ItemType> &Queue<ItemType>::operator=(const Queue<ItemType> &rhs) {
    if (this != &rhs) {
        Queue<ItemType> tmp(rhs);
        std::swap(myFront, tmp.myFront);
        std::swap(myBack, tmp.myBack);
        std::swap(mySize, tmp.mySize);
    }
    return *this;
}

// isEmpty
// Checks if the queue is empty
// pre:  A queue exists.
// post: Returns true if it IS empty, false if NOT empty.
template <typename ItemType>
bool Queue<ItemType>::isEmpty() const {
    return myFront == nullptr;
}

// enqueue
// enqueues an item to back of the queue.
// pre:  DblQueue exists and item is passed.
// post: adds the given item to the end of the queue.
template <typename ItemType>
void Queue<ItemType>::enqueue(const ItemType& item) {
    if (isEmpty()) {
        myBack = new Node;
        myFront = myBack;
    } else {
        myBack->next = new Node;
        myBack = myBack->next;
    }
    myBack->value = item;
    myBack->next = nullptr;
    mySize++;
}

// dequeue
// dequeues the front item off the queue
// pre:  DblQueue exists.
// post: Removes item on front of the queue. If the queue
//       was already empty, throws an std::underflow_error exception.
template <typename ItemType>
void Queue<ItemType>::dequeue() {
    if (isEmpty()) {
        throw std::underflow_error("The queue is empty");
    } else {
        NodePtr tmp(myFront);
        myFront = myFront->next;
        if (size() == 1) {
            myBack = nullptr;
        }
        delete tmp;
        mySize--;
    }
}

// front
// Returns the front item of the queue without dequeueing it.
// pre:  DblQueue exists.
// post: Returns item at front of queue.  If the queue is empty,
//       throws an std::underflow_error exception.
template <typename ItemType>
ItemType Queue<ItemType>::front() const {
    if (isEmpty()) {
        throw std::underflow_error("The queue is empty");
    } else {
        return myFront->value;
    }
}

// size
// Returns the number of items on the queue.
template <typename ItemType>
size_t Queue<ItemType>::size() const {
    return mySize;
}