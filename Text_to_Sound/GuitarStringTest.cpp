// File name: GuitarStringTest.cpp
// Author: Hanliang Xu
// userid: xuh11
// Email: hanliang.xu@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 06
// Description: This program tests the GuitarString class.
// Honor statement: I pledge that I finished this project myself.
// Last Changed:

#include "GuitarString.h"
#include <iostream>

int main()
{
    // negative frequency
    try {
        std::cout << "Expect an \"invalid_argument\" exception" << std::endl;
        // The following statement should throw an exception
        std::cout << "Negative frequency :: ";
        GuitarString string1 = GuitarString(-22050);
        std::cout << std::endl;
        std::cout << "EXCEPTION ERROR -- YOU SHOULD NOT SEE THIS MESSAGE"
                  << std::endl;
    }
    catch (std::invalid_argument& excpt) {
        std::cout << "Exception was properly thrown and caught :: "
                  << excpt.what() << std::endl;
    }
    catch (...) {
        std::cout << "EXCEPTION ERROR --  top() threw the wrong exception."
                  << std::endl;
    }

    // N = 2.0;
    GuitarString string1 = GuitarString(22050);
    if (string1.getFrequency() != 22050) {
        std::cout << "Test 1 failed! The default constructor or the getFrequency function"
                     " is not working properly." << std::endl;
    }
    if (string1.getTime() != 0) {
        std::cout << "Test 2 failed! The default constructor or the getTime function"
                     " is not working properly." << std::endl;
    }
    string1.pluck();
    if (string1.sample() > 0.5 || string1.sample() < -0.5) {
        std::cout << "Test 3 failed! The default constructor, the sample function, "
                     "or the pluck function is not working properly." << std::endl;
    }

    double front1 = string1.sample();
    string1.tic();
    double front2 = string1.sample();
    // the next front should be "DECAY_FACTOR * 0.5 * (front1 + front2)"

    if (string1.getTime() != 1) {
        std::cout << "Test 4 failed! The tic function is not working properly." << std::endl;
    }

    string1.tic();
    if (string1.sample() != (DECAY_FACTOR * 0.5 * (front1 + front2))) {
        std::cout << "Test 5 failed! The tic function is not working properly." << std::endl;
    }
    if (string1.getTime() != 2) {
        std::cout << "Test 6 failed! The tic function is not working properly." << std::endl;
    }


    // N = 1.75 -> 2
    GuitarString string2 = GuitarString(25000);
    if (string2.getFrequency() != 25000) {
        std::cout << "Test 7 failed! The default constructor or the getFrequency function"
                     " is not working properly." << std::endl;
    }
    front1 = string2.sample();
    string2.tic();
    front2 = string2.sample();
    // the next front should be "DECAY_FACTOR * 0.5 * (front1 + front2)"
    string2.tic();
    if (string2.sample() != (DECAY_FACTOR * 0.5 * (front1 + front2))) {
        std::cout << "Test 8 failed! The tic function is not working properly." << std::endl;
    }

    // N = 2.25 -> 2
    GuitarString string3 = GuitarString(19600);
    if (string3.getFrequency() != 19600) {
        std::cout << "Test 9 failed! The default constructor or the getFrequency function"
                     " is not working properly." << std::endl;
    }
    front1 = string3.sample();
    string3.tic();
    front2 = string3.sample();
    // the next front should be "DECAY_FACTOR * 0.5 * (front1 + front2)"
    string3.tic();
    if (string3.sample() != (DECAY_FACTOR * 0.5 * (front1 + front2))) {
        std::cout << "Test 10 failed! The tic function is not working properly." << std::endl;
    }
    string3.pluck();
    if (string3.sample() > 0.5 || string3.sample() < -0.5) {
        std::cout << "Test 11 failed! The default constructor or the getFrequency function"
                     " is not working properly." << std::endl;
    }
    string3.tic();
    if (string3.sample() > 0.5 || string3.sample() < -0.5) {
        std::cout << "Test 12 failed! The default constructor or the getFrequency function"
                     " is not working properly." << std::endl;
    }

    // N = 3
    GuitarString string4 = GuitarString(14700);
    string4.pluck();
    if (string4.sample() > 0.5 || string4.sample() < -0.5) {
        std::cout << "Test 13 failed! The default constructor or the getFrequency function"
                     " is not working properly." << std::endl;
    }
    string4.tic();
    if (string4.sample() > 0.5 || string4.sample() < -0.5) {
        std::cout << "Test 14 failed! The default constructor or the getFrequency function"
                     " is not working properly." << std::endl;
    }
    string4.tic();
    if (string4.sample() > 0.5 || string4.sample() < -0.5) {
        std::cout << "Test 15 failed! The default constructor or the getFrequency function"
                     " is not working properly." << std::endl;
    }

    return 0;
}
