/*
*
* This file includes the abstract class of the Observer States.
* 
*/

#pragma once
#include "Observer.h"

// Forward declaration to resolve circular dependencies
class Observer;

class ObserverState{
    public:
        //virtual void setExternalInputs(double reference, double error) = 0;
        virtual void transition(Observer* observer) = 0;

        // Destructor
        virtual ~ObserverState() {}    
};