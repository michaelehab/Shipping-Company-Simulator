#pragma once
#include "Event.h"
class PromoteEvent :
    public Event
{
    //For promotion event
    double Em;   //extra money for promotion
public:
    bool setEm(double e);		//sets the extra money for promotion
    double getEm() const;		//gets the extra money for promotion
};

