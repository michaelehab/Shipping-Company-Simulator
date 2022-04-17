#pragma once
#include "Event.h"
#include "LinkedList.h"
#include "Cargo.h"
class CancelEvent :
    public Event
{
public:
    CancelEvent();
    CancelEvent(int id, int day, int hour, char Etype);
    bool Execute(int id,LinkedList<Cargo*>* list);
};

