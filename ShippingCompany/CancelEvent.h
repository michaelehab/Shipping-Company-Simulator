#pragma once
#include "Event.h"

class CancelEvent :
    public Event
{
public:
    CancelEvent();
    CancelEvent(int id, int day, int hour, char Etype, Company* ptr);
    bool Execute();
};

