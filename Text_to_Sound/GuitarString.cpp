// File name: GuitarString.h
// Author: Hanliang Xu
// userid: xuh11
// Email: hanliang.xu@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: 06
// Description: This class will model/simulate a vibrating guitar string of a given frequency.
// Honor statement: I pledge that I finished this project myself.
// Last Changed:

#include "GuitarString.h"
#include <chrono>
#include <random>
#include <cmath>

// The constructor for a string of the given frequency.
// pre: frequency is positive.
// post: object is initialized to represent a string at rest.
// Throws a std::invalid_argument exception if the frequency is not positive.
GuitarString::GuitarString(double frequency) : capacity(round(SAMPLE_RATE / frequency)), time(0),
frequency(frequency) {
    if (frequency < 0) {
        throw std::invalid_argument("The frequency is not positive");
    }
    for (size_t i = 0; i < capacity; ++i) {
        ringBuffer.enqueue(0);
    }
}

// Pluck the string.
// post: replaced all elements in the ring buffer with the equivalent quantity of
// random values between -0.5 and +0.5
void GuitarString::pluck() {
    // (1) create the seed
    unsigned seed = (unsigned) std::chrono::system_clock::now().time_since_epoch().count();
    // (2) create the generator using the seed
    std::default_random_engine generator(seed);
    // (3) create the appropriate distribution
    std::uniform_real_distribution<double> distribution(-0.5, 0.5);
    for (size_t i = 0; i < capacity; ++i) {
        ringBuffer.dequeue();
        // (4) create random numbers as needed (the following will likely be in a loop)
        ringBuffer.enqueue(distribution(generator));
    }
}

// Tic the clock by advancing the simulation one step.
// post: the Karplus-Strong update has been applied to the string.
void GuitarString::tic() {
    double first = ringBuffer.front();
    ringBuffer.dequeue();
    ringBuffer.enqueue(DECAY_FACTOR * 0.5 * (first + ringBuffer.front()));
    ++time;
}

// Return the current sound sample of the string.
double GuitarString::sample() const {
    return ringBuffer.front();
}

// Return the number of time steps executed == number of calls to tic().
size_t GuitarString::getTime() const {
    return time;
}

// Return the frequency of the string.
double GuitarString::getFrequency() const {
    return frequency;
}