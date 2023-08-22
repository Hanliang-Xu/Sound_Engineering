// File name: Stack_t.cpp
// Name: Hanliang Xu
// VUnetid: xuh11
// Email: hanliang.xu@vanderbilt.edu
// Class: CS2201
// Assignment Number: 07
// Honor statement: I pledge that I finished this project myself.
// Description:  Maintains a stack of ItemType.  Implements functions to
//     push, pop, retrieve top, and retrieve size of the stack.
// Last Changed:


#include <cstddef>
#include <stdexcept>
#include <algorithm>

template <typename ItemType>
Stack<ItemType>::Stack() : mySize(0), myHead(nullptr) {
}

template <typename ItemType>
Stack<ItemType>::Stack(const Stack<ItemType> &rhs): mySize(rhs.mySize), myHead(nullptr) {
    if (rhs.myHead != nullptr) {
        // copy first node
        myHead = new Node;
        myHead->value = rhs.myHead->value;
        myHead->next = rhs.myHead->next;
        // copy rest of the list
        NodePtr newPtr = myHead;
        NodePtr origPtr = rhs.myHead;
        while (origPtr->next != nullptr) {
            origPtr = origPtr->next;
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->value = origPtr->value;
            newPtr->next = nullptr;
        }
    }
}

template <typename ItemType>
Stack<ItemType>::~Stack() {
    while (myHead != nullptr) {
        NodePtr tmp = myHead;
        myHead = myHead->next;
        delete tmp;
    }
    mySize = 0;
}

template <typename ItemType>
const Stack<ItemType> &Stack<ItemType>::operator=(const Stack<ItemType> &rhs) {
    if (this != &rhs) {
        Stack<ItemType> tmp(rhs);
        std::swap(myHead, tmp.myHead);
        std::swap(mySize, tmp.mySize);
    }
    return *this;
}

template <typename ItemType>
bool Stack<ItemType>::isEmpty() const {
    return myHead == nullptr;
}

template <typename ItemType>
void Stack<ItemType>::push(const ItemType &item) {
    NodePtr tmp(myHead);
    myHead = new Node;
    myHead->next = tmp;
    myHead->value = item;
    mySize++;
}

template <typename ItemType>
void Stack<ItemType>::pop() {
    if (isEmpty()) {
        throw std::underflow_error("The stack is empty");
    } else {
        NodePtr tmp(myHead);
        myHead = myHead->next;
        delete tmp;
        mySize--;
    }
}

template <typename ItemType>
ItemType Stack<ItemType>::top() const {
    if (isEmpty()) {
        throw std::underflow_error("The stack is empty");
    } else {
        return myHead->value;
    }
}

template <typename ItemType>
size_t Stack<ItemType>::size() const {
    return mySize;
}