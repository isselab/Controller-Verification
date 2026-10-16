/*
*
* This file includes the definitions of the methods for ObserverStates.h.
* As well as all guards for each transition 
*
*/

#include "ConcreteObserverStates.h"
#include <dios.h>
#include <sys/divm.h>
#include <iostream>
//using namespace std;


/*
* The part below creats new Object used as States
*/
ObserverState& Rest::getInstance() {
    static Rest singleton;
    return singleton;
}

ObserverState& Transient::getInstance() {
    static Transient singleton;
    return singleton;
}

ObserverState& Rise::getInstance() {
    static Rise singleton;
    return singleton;
}

ObserverState& Overshoot::getInstance() {
    static Overshoot singleton;
    return singleton;
}

ObserverState& Bounded::getInstance() {
    static Bounded singleton;
    return singleton;
}

/*
* The part below covers all possible transitions between the State.
* The Guard are also implemented, may need still some fine tuning (21.06.2023)
*/

/* 
* Possible Transitions from Rest
*/
void Rest::transition(Observer* observer) {
    
    __dios_trace_f("Current State: Rest");
    //__dios_trace_f("Thresholds: %d, %d, %d, %d, %d", observer->epsilon, observer->overshootLevel, observer->riseLevel, observer->riseTime, observer->settlingTime );

    // !!! GUARD CONDITIONS MAY NEED TO BE ADJUSTED !!!

    // Transition Rest -> Transient 
    if (observer->reference != 0) { // should transit as soon as a reference is set (/=0), therefore, true.
        observer->setState(Transient::getInstance());
        //cout << "Next State: Transient" << endl;
    }
    // Selfloop
    else if (observer->error <= observer->epsilon) {
        observer->setState(Rest::getInstance());
        //cout << "Next State: Rest" << endl;
    }
}

/*
* Possible Transitions from Transient
*/
void Transient::transition(Observer* observer) {

    __dios_trace_f("Current State: Transient");

    // Sets the boolean for Transient to true, because Transient is now visited
    observer->setTransientVisited();

    // !!! GUARD CONDITIONS MAY NEED TO BE ADJUSTED !!!


    // Transition Transient -> Rise
    if (observer->error >= observer->riseLevel && observer->time <= observer->riseTime && observer->wasRiseVisited() == false){
        observer->setState(Rise::getInstance());
    }

    // Transition Transient -> Bounded
    else if (observer->error > observer->epsilon*observer->reference) {
        observer->setState(Bounded::getInstance());
    }

    // Transition Transient -> Overshoot
    else if (observer->sysOut < observer->overshootLevel)
    {
        // __dios_trace_f("SysOut: %d, O-Level: %d, %d, %d, Diff: %d", observer->sysOut, observer->overshootLevel, observer->reference, (observer->overshootLevel*observer->reference), (observer->sysOut-(observer->overshootLevel*observer->reference)));
        observer->setState(Overshoot::getInstance());
    }
    

    // Selfloop
    else {
        observer->setState(Transient::getInstance());
    }
}

/*
* Possible Transitions from Rise
*/
void Rise::transition(Observer* observer) {

    __dios_trace_f("Current State: Rise");
    
    // Sets the boolean for Rise to true, because Rise is now visited
    observer->setRiseVisited();

    // !!! GUARD CONDITIONS MAY NEED TO BE ADJUSTED !!!
    // Transition Rise -> Overshoot
    if (observer->sysOut < observer->overshootLevel) {
        // __dios_trace_f("SysOut: %d, O-Level: %d, %d, %d, Diff: %d", observer->sysOut, observer->overshootLevel, observer->reference, (observer->overshootLevel*observer->reference), (observer->sysOut-(observer->overshootLevel*observer->reference)));
        observer->setState(Overshoot::getInstance());
    }

    // Transition Rise -> Bounded
    else if (observer->error > observer->epsilon*observer->reference) {
        observer->setState(Bounded::getInstance());
    }
    
    // Selfloop
    else {
        observer->setState(Transient::getInstance());
    }
}

/*
* Possible Transitions from Overshoot
*/
void Overshoot::transition(Observer* observer) {

    __dios_trace_f("Current State: Overshoot");
    // __dios_trace_f("SysOut: %d, O-Level: %d, %d, %d, Diff: %d", observer->sysOut, observer->overshootLevel, observer->reference, (observer->overshootLevel*observer->reference), (observer->sysOut-(observer->overshootLevel*observer->reference)));
    
    // Sets the boolean for Overshoot to true, because Overshoot is now visited
    observer->setOvershootVisited();

    // !!! GUARD CONDITIONS MAY NEED TO BE ADJUSTED !!!

    // Transition Overshoot -> Bounded
    if (observer->error > observer->epsilon*observer->reference)
    {
        observer->setState(Bounded::getInstance());
    }
    
    // Selfloop
    else if (observer->sysOut < observer->overshootLevel)
    {
        observer->setState(Overshoot::getInstance());
    }

    // Transition Overshoot -> Transient
    else
    {
        observer->setState(Transient::getInstance());
    }
    
}

/*
* Possible Transitions from Bounded
*/
void Bounded::transition(Observer* observer) {

    __dios_trace_f("Current State: Bounded");
    //printf("Time: %d, CounterBounded: %d\n", (int)(10*observer->time), (int)(counterBounded));
    
    // Sets the boolean for Bounded to true, because Bounded is now visited
    observer->setBoundedVisited();
    
    if (counterReset == true) {
        counterBounded = 0;
    }

    // !!! GUARD CONDITIONS MAY NEED TO BE ADJUSTED !!!

    // Transition Bounded -> Rest
    if (observer->error > observer->epsilon*observer->reference && (observer->time - (counterBounded/30)) <= observer->settlingTime && counterBounded >= counterLimit)
    {
        //printf("Time: %d, Counter: %d, Time Diff: %d\n", (int)(10*observer->time), (int)(10*counterBounded/30), (int)(10*(observer->time - (counterBounded/30))));
        observer->setState(Rest::getInstance());
        counterReset = true;
        observer->setRestVisited();
    }

    // Transition Bounded -> Overshoot
    else if (observer->sysOut < observer->overshootLevel)
    {   
        // __dios_trace_f("SysOut: %d, O-Level: %d, %d, %d, Diff: %d", observer->sysOut, observer->overshootLevel, observer->reference, (observer->overshootLevel*observer->reference), (observer->sysOut-(observer->overshootLevel*observer->reference)));
        observer->setState(Overshoot::getInstance());
        counterReset = true;
    }
    
    // Selfloop
    else if (observer->error > observer->epsilon*observer->reference)
    {
        observer->setState(Bounded::getInstance());
        counterReset = false;
        counterBounded++;
    }

        
    // Transition Bounded -> Transient
    else
    {
        observer->setState(Transient::getInstance());
        counterReset = true;
    }

    
    
}