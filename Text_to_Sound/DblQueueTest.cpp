// File name: DblQueueTest.cpp
// Author: Hanliang Xu
// userid: xuh11
// Email: hanliang.xu@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 06
// Description: This program tests the DblQueue class
// Honor statement: I pledge that I finished this project myself.
// Last Changed:

#include "DblQueue.h"
#include <iostream>

int main()
{
    // test the default constructor & the size function (when size = 0)
    Queue<double> queue1 = Queue<double>();
    if (queue1.size() != 0) {
        std::cout << "Test 1 failed! The default constructor or the size function"
                     " is not working properly." << std::endl;
    }

    // test the default constructor & the isEmpty function (when the queue is empty)
    if (! queue1.isEmpty()) {
        std::cout << "Test 2 failed! The default constructor or the isEmpty function"
                     " is not working properly." << std::endl;
    }

    // test the default constructor & the front function (when the queue is empty)
    try {
        std::cout << "Expect an \"underflow_error\" exception" << std::endl;
        // The following statement should throw an exception
        std::cout << "Try to return the front ItemType of queue1 without popping it :: ";
        queue1.front();
        std::cout << std::endl;
        std::cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE"
                  << std::endl;
    }
    catch (std::underflow_error& excpt) {
        std::cout << "Exception was properly thrown and caught :: "
                  << excpt.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION ERROR --  top() threw the wrong exception."
                  << std::endl;
    }

    // test the default constructor & the pop function (when the stack is empty)
    try {
        std::cout << "Expect an \"underflow_error\" exception" << std::endl;
        // The following statement should throw an exception
        std::cout << "Try to pop the top ItemType off queue1 :: ";
        queue1.dequeue();
        std::cout << std::endl;
        std::cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE"
                  << std::endl;
    }
    catch (std::underflow_error& excpt) {
        std::cout << "Exception was properly thrown and caught :: "
                  << excpt.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION ERROR --  pop() threw the wrong exception."
                  << std::endl;
    }

    // test the enqueue function (when the queue is empty) and the size function (when the queue is
    // non-empty)
    queue1.enqueue(3.14);
    if (queue1.size() != 1) {
        std::cout << "Test 3 failed! The push function or the size function"
                     " is not working properly." << std::endl;
    }

    // test the front function (when the queue has one item)
    if (queue1.front() - 3.14 > 0.001) {
        std::cout << "Test 4 failed! The top function is not working properly." << std::endl;
    }

    // test the isEmpty function (when the queue is non-empty)
    if (queue1.isEmpty()) {
        std::cout << "Test 5 failed! The isEmpty function is not working properly." << std::endl;
    }

    queue1.enqueue(6.28);
    // test the size function (when the queue has more than one item) & the push function
    if (queue1.size() != 2) {
        std::cout << "Test 6 failed! The size function or the push function"
                     " is not working properly." << std::endl;
    }

    // test the front function (when the queue is non-empty and has more than one item)
    if (queue1.front() - 3.14 > 0.001) {
        std::cout << "Test 7 failed! The top function is not working properly." << std::endl;
    }

    Queue<double> queue2(queue1);
    // test the alternate constructor
    if (queue2.size() != 2) {
        std::cout << "Test 8 failed! The top function is not working properly." << std::endl;
    }
    if (queue2.front() - 3.14 > 0.001) {
        std::cout << "Test 9 failed! The top function is not working properly." << std::endl;
    }
    queue2.dequeue();
    if (queue2.size() != 1) {
        std::cout << "Test 10 failed! The top function is not working properly." << std::endl;
    }
    if (queue2.front() - 6.28 > 0.001) {
        std::cout << "Test 11 failed! The top function is not working properly." << std::endl;
    }
    queue2.dequeue();
    if (queue2.size() != 0) {
        std::cout << "Test 12 failed! The top function is not working properly." << std::endl;
    }
    if (! queue2.isEmpty()) {
        std::cout << "Test 13 failed! The top function is not working properly." << std::endl;
    }

    Queue<double> queue3 = queue1;
    // test the assignment operator
    if (queue3.size() != 2) {
        std::cout << "Test 14 failed! The top function is not working properly." << std::endl;
    }
    if (queue3.front() - 3.14 > 0.001) {
        std::cout << "Test 15 failed! The top function is not working properly." << std::endl;
    }
    queue3.dequeue();
    if (queue3.size() != 1) {
        std::cout << "Test 16 failed! The top function is not working properly." << std::endl;
    }
    if (queue3.front() - 6.28 > 0.001) {
        std::cout << "Test 17 failed! The top function is not working properly." << std::endl;
    }
    queue3.dequeue();
    if (queue3.size() != 0) {
        std::cout << "Test 18 failed! The top function is not working properly." << std::endl;
    }
    if (! queue3.isEmpty()) {
        std::cout << "Test 19 failed! The top function is not working properly." << std::endl;
    }

    // make sure that changes to queue2 and queue3 don't affect stack1
    if (queue1.size() != 2) {
        std::cout << "Test 20 failed! The top function is not working properly." << std::endl;
    }
    if (queue1.front() - 3.14 > 0.001) {
        std::cout << "Test 21 failed! The top function is not working properly." << std::endl;
    }


    // test destructor
    double big(9999999999999999999999999999999999999.999999999999999999999999999999999);
    Queue<double> dtorTest = Queue<double>();
    for (size_t j=0; j<200000; ++j) {
        dtorTest.enqueue(big);
    }

    std::cout << "Testing the destructor. Watch the memory usage of your computer." << std::endl;
    for (size_t i=0; i<2000; ++i) {
        Queue<double>* bigQueue(new Queue<double>(dtorTest));  // make a big strand object
        if (i%12==0) {
            std::cout << '.' << std::flush;
        }
        delete bigQueue;     // now delete it
    }
    std::cout << std::endl;

    return 0;
}