#pragma once
#include "Event.h"
#include "LinkedList.h"
#include "Cargo.h"
class CancelEvent :
    public Event
{
public:
    bool Execute(int id,LinkedList<Cargo*>* list);
};

