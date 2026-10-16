/*
*
* This file includes the definitions of the methods for ObserverStates.h.
* As well as all guards for each transition 
*
*/
#include <iostream>
#include "ConcreteObserverStates.h"
using namespace std;


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

double Transient::transientEnteredTime = 0.0;

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
* Possible Transitions from Rest
*/
void Rest::transition(Observer* observer) {

    // !!! GUARD CONDITIONS MAY NEED TO BE ADJUSTED !!!

    // Transition: Rest -> Transient 
    if (observer->reference != 0 && observer->error >= observer->epsilon) {
        observer->setState(Transient::getInstance());
    }
    // Selfloop
    else if (observer->error <= observer->epsilon) {
        observer->setState(Rest::getInstance());
    }
}

/*
* Possible Transitions from Transient
*/
void Transient::transition(Observer* observer) {

    // Save time when transient was entered for the first time
    if (!observer->wasTransientVisited()) transientEnteredTime = observer->time;

    // Sets the boolean for Transient to true, because Transient is now visited
    observer->setTransientVisited();

    // !!! GUARD CONDITIONS MAY NEED TO BE ADJUSTED !!!

    // Transition: Transient -> Rise
    if (observer->error <= observer->riseLevel && observer->time <= (transientEnteredTime + observer->riseTime) && observer->wasRiseVisited() == false) {
        observer->setState(Rise::getInstance());
    }

    // Transition: Transient -> Bounded
    else if (observer->error <= observer->epsilon) {
        observer->setState(Bounded::getInstance());
    }

    // Transition: Transient -> Overshoot
    else if (observer->sysOut > observer->overshootLevel*observer->reference)
    {
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

    // Sets the boolean for Rise to true, because Rise is now visited
    observer->setRistVisited();

    // !!! GUARD CONDITIONS MAY NEED TO BE ADJUSTED !!!

    // Transition: Rise -> Overshoot
    if (observer->sysOut > observer->overshootLevel*observer->reference) {
        observer->setState(Overshoot::getInstance());
    }

    // Transition: Rise -> Bounded
    else if (observer->error <= observer->epsilon) {
        observer->setState(Bounded::getInstance());
    }
    
    // Selfloop
    else if (observer->error > observer->epsilon && observer->sysOut <= observer->overshootLevel*observer->reference) {
        observer->setState(Rise::getInstance());
    }
}

/*
* Possible Transitions from Overshoot
*/
void Overshoot::transition(Observer* observer) {

    // Sets the boolean for Overshoot to true, because Overshoot is now visited
    observer->setOvershootVisited();

    // !!! GUARD CONDITIONS MAY NEED TO BE ADJUSTED !!!

    // Transition: Overshoot -> Bounded
    if (observer->error <= observer->epsilon)
    {
        observer->setState(Bounded::getInstance());
    }
    
    // Transition: Overshoot -> Transient
    else if (observer->sysOut <= observer->overshootLevel*observer->reference && observer->error > observer->epsilon)
    {
        observer->setState(Transient::getInstance());
    }
    
    // Selfloop
    else if (observer->sysOut > observer->overshootLevel*observer->reference)
    {
        observer->setState(Overshoot::getInstance());
    }
}

/*
* Possible Transitions from Bounded
*/
void Bounded::transition(Observer* observer) {

    // Sets the boolean for Bounded to true, because Bounded is now visited
    observer->setBoundedVisited();
    
    if (counterReset == true) {
        counterBounded = 0;
        lastBounded = observer->time;
    }

    // !!! GUARD CONDITIONS MAY NEED TO BE ADJUSTED !!!

    // Transition: Bounded -> Rest
    if (observer->error <= observer->epsilon && (observer->time - counterBounded) <= observer->settlingTime && counterBounded >= counterLimit)
    {
        observer->setState(Rest::getInstance());
        counterReset = true;
        observer->setRestVisited();
    }
    
    // Transition: Bounded -> Transient
    else if (observer->error > observer->epsilon && observer->sysOut <= observer->overshootLevel*observer->reference)
    {
        observer->setState(Transient::getInstance());
        counterReset = true;
    }

    // Transition: Bounded -> Overshoot
    else if (observer->error > observer->epsilon && observer->sysOut > observer->overshootLevel*observer->reference)
    {
        observer->setState(Overshoot::getInstance());
        counterReset = true;
    }
    
    // Selfloop
    else if (observer->error <= observer->epsilon)
    {
        observer->setState(Bounded::getInstance());
        counterReset = false;
        counterBounded += observer->time - lastBounded;
        lastBounded = observer->time;
    }
}