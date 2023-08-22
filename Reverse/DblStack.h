// File name: Stack_t.h
// Name: Hanliang Xu
// VUnetid: xuh11
// Email: hanliang.xu@vanderbilt.edu
// Class: CS2201
// Assignment Number: 07
// Honor statement: I pledge that I finished this assignment myself.
// Description:  Maintains a stack of ItemType.  Contains functions
//     prototypes to push, pop, retrieve top, and retrieve size of the
//     stack.
// Last Changed:

#ifndef STACK_H
#define STACK_H

template <typename ItemType>
class Stack
{
private:

    // the structure of a linked list node contains a single double value and a next pointer
    struct Node {
        ItemType value;
        Node *next;
    };

    typedef Node* NodePtr;

    // Current size of the stack; i.e., how many elements are in the linked list
    size_t mySize;

    // Stack's linked list; i.e., our "head" pointer
    NodePtr myHead;



public:
    // Class Constructor
    // post: stack is created & initialized to be empty
    Stack();

    // Copy Constructor
    // pre: parameter object, rhs, exists
    // post: stack is created to be a copy of the parameter stack
    Stack(const Stack& rhs);

    // Class Deconstructor
    // pre: the stack exists
    // post: the stack is destroyed and any dynamic memory is returned to the system
    ~Stack();

    // Assignment operator
    // Assigns a stack to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const Stack& operator= (const Stack& rhs);

    // isEmpty
    // Checks if the stack is empty
    // pre:  A stack exists.
    // post: Returns true if it IS empty, false if NOT empty.
    bool isEmpty() const;

    // push
    // Pushes an item on top of the stack.
    // pre:  Stack exists and item is passed.
    // post: the item is placed on top of the stack, and size is incremented.
    void push(const ItemType& item);

    // pop
    // Pops the top item off the stack.
    // pre:  Stack exists.
    // post: Removes item on top of stack.  If the stack
    //       was already empty, throws a std::underflow_error exception.
    void pop();

    // top
    // Returns the top item of the stack without popping it.
    // pre:  Stack exists.
    // post: Returns item on top of stack.  If the stack
    //       was already empty, throws a std::underflow_error exception.
    ItemType top() const;

    // size
    // Returns the number of items on the stack.
    // post: Returns size from the private section of class.
    size_t size() const;
};

#include "DblStack.cpp"
#endif