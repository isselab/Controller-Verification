/*
*
* This file includes the definitions of the methods for the Observer.
*
* Version 0.2               02.06.2023 
*/

#include <math.h>
#include <cstdio>
#include <vector>
#include "Observer.h"
#include "ConcreteObserverStates.h"
#include <iostream>

// Initialization
Observer::Observer() {
    currentState = &Rest::getInstance();

    // System "attributes"
    reference = 0;
    error = 0;
    sysOut = 0;
    time = 0;

    // Init all states with false -> not entered

    restWasEntered = false;
    transientWasEntered = false;
    riseWasEntered = false;
    overshootWasEntered = false;
    boundedWasEntered = false;

    // Thresholds
    epsilon = 0;
    overshootLevel = 0;
    riseLevel = 0;
    riseTime = 0;
    settlingTime = 0;
}

void Observer::setState(ObserverState& newState) {
    currentState = &newState;
}

void Observer::transition() {
    // Next state is determined by the current state
    currentState->transition(this);
}

/*
* Inputs are Signals/Data from the System.
* Order: reference, error, sysOut
*/
void Observer::setExternalInput(double Input1, double Input2, double Input3, double Input4) {
    reference = Input1;
    error = (Input1 != 0.0) ? fabs(Input2/Input1)*100 : Input2;
    sysOut = Input3;
    time = Input4;

    std::cout << "Reference: " << Input1 << "Error: " << error << "Real value: " << Input3 << "Time: " << Input4 << std::endl;
}

/*
* Sets values for the property thresholds.
* Order: steady state error (%), Overhsoot (%), riseLevel (%), rise time (sec), settling time (sec)
*/
void Observer::initialThreshold(double thr1, double thr2, double thr3, double thr4, double thr5) {
    epsilon = thr1;
    overshootLevel = 1.0 + (thr2/100);
    riseLevel = 100-thr3;
    riseTime = thr4;
    settlingTime = thr5;
}

// Returns true or false of Rest was entered
bool Observer::wasRestVisited(){
    return restWasEntered;
}

// Returns true or false of Transient was entered
bool Observer::wasTransientVisited(){
    return transientWasEntered;
}

// Returns true or false of Rise was entered
bool Observer::wasRiseVisited(){
    return riseWasEntered;
}

// Returns true or false of Overshoot was entered
bool Observer::wasOvershootVisited(){
    return overshootWasEntered;
}

// Returns true or false of Bounded was entered
bool Observer::wasBoundedVisited(){
    return boundedWasEntered;
}

// // Returns an array of booleans, representing which States were visited
std::vector<bool> Observer::visitedStates(){
     return {restWasEntered, transientWasEntered, riseWasEntered, overshootWasEntered, boundedWasEntered};
}

void Observer::setRestVisited(){
    restWasEntered = true;
};

void Observer::setTransientVisited(){
    transientWasEntered = true;
};

void Observer::setRistVisited(){
    riseWasEntered = true;
};

void Observer::setOvershootVisited(){
    overshootWasEntered = true;
};

void Observer::setBoundedVisited(){
    boundedWasEntered = true;
};