// Name: Hanliang Xu
// Email: hanliang.xu@vanderbilt.edu
// VUnetid: xuh11
// Class: CS2201
// Date: 03/20/2023
// Honor statement: I pledge that I finished this project myself.
// Description:
// This program tests the DblStack class.

#include <iostream>
#include "DblStack.h"

int main()
{
    // test the default constructor & the size function (when size = 0)
    Stack<double> stack1 = Stack<double>();
    if (stack1.size() != 0) {
        std::cout << "Test 1 failed! The default constructor or the size function"
                     " is not working properly." << std::endl;
    }

    // test the default constructor & the isEmpty function (when the stack is empty)
    if (! stack1.isEmpty()) {
        std::cout << "Test 2 failed! The default constructor or the isEmpty function"
                     " is not working properly." << std::endl;
    }

    // test the default constructor & the top function (when the stack is empty)
    try {
        std::cout << "Expect an \"underflow_error\" exception" << std::endl;
        // The following statement should throw an exception
        std::cout << "Try to return the top ItemType of stack1 without popping it :: ";
        stack1.top();
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
        std::cout << "Try to pop the top ItemType off stack1 :: ";
        stack1.pop();
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

    // test the push function (when the stack is empty) and the size function (when the stack is
    // non-empty)
    stack1.push(3.14);
    if (stack1.size() != 1) {
        std::cout << "Test 3 failed! The push function or the size function"
                     " is not working properly." << std::endl;
    }

    // test the top function (when the stack has one item)
    if (stack1.top() - 3.14 > 0.001) {
        std::cout << "Test 4 failed! The top function is not working properly." << std::endl;
    }

    // test the isEmpty function (when the stack is non-empty)
    if (stack1.isEmpty()) {
        std::cout << "Test 5 failed! The isEmpty function is not working properly." << std::endl;
    }

    stack1.push(6.28);
    // test the size function (when the stack has more than one item) & the push function
    if (stack1.size() != 2) {
        std::cout << "Test 6 failed! The size function or the push function"
                     " is not working properly." << std::endl;
    }

    // test the top function (when the stack is non-empty and has more than one item)
    if (stack1.top() - 6.28 > 0.001) {
        std::cout << "Test 7 failed! The top function is not working properly." << std::endl;
    }

    Stack<double> stack2(stack1);
    // test the alternate constructor
    if (stack2.size() != 2) {
        std::cout << "Test 8 failed! The top function is not working properly." << std::endl;
    }
    if (stack2.top() - 6.28 > 0.001) {
        std::cout << "Test 9 failed! The top function is not working properly." << std::endl;
    }
    stack2.pop();
    if (stack2.size() != 1) {
        std::cout << "Test 10 failed! The top function is not working properly." << std::endl;
    }
    if (stack2.top() - 3.14 > 0.001) {
        std::cout << "Test 11 failed! The top function is not working properly." << std::endl;
    }
    stack2.pop();
    if (stack2.size() != 0) {
        std::cout << "Test 12 failed! The top function is not working properly." << std::endl;
    }
    if (! stack2.isEmpty()) {
        std::cout << "Test 13 failed! The top function is not working properly." << std::endl;
    }

    Stack<double> stack3 = stack1;
    // test the assignment operator
    if (stack3.size() != 2) {
        std::cout << "Test 14 failed! The top function is not working properly." << std::endl;
    }
    if (stack3.top() - 6.28 > 0.001) {
        std::cout << "Test 15 failed! The top function is not working properly." << std::endl;
    }
    stack3.pop();
    if (stack3.size() != 1) {
        std::cout << "Test 16 failed! The top function is not working properly." << std::endl;
    }
    if (stack3.top() - 3.14 > 0.001) {
        std::cout << "Test 17 failed! The top function is not working properly." << std::endl;
    }
    stack3.pop();
    if (stack3.size() != 0) {
        std::cout << "Test 18 failed! The top function is not working properly." << std::endl;
    }
    if (! stack3.isEmpty()) {
        std::cout << "Test 19 failed! The top function is not working properly." << std::endl;
    }

    // make sure that changes to stack2 and stack3 don't affect stack1
    if (stack1.size() != 2) {
        std::cout << "Test 20 failed! The top function is not working properly." << std::endl;
    }
    if (stack1.top() - 6.28 > 0.001) {
        std::cout << "Test 21 failed! The top function is not working properly." << std::endl;
    }


    // test destructor
    double big(9999999999999999999999999999999999999.999999999999999999999999999999999);
    Stack<double> dtorTest = Stack<double>();
    for (size_t j=0; j<200000; ++j) {
        dtorTest.push(big);
    }

    std::cout << "Testing the destructor. Watch the memory usage of your computer." << std::endl;
    for (size_t i=0; i<2000; ++i) {
        Stack<double>* bigStack(new Stack<double>(dtorTest));  // make a big strand object
        if (i%12==0) {
            std::cout << '.' << std::flush;
        }
        delete bigStack;     // now delete it
    }
    std::cout << std::endl;

    return 0;
}