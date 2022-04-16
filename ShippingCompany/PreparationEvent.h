#pragma once
#include "Event.h"
#include "LinkedList.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Cargo.h"
class PreparationEvent :
    public Event
{
public:
    bool Execute(Event* e,LinkedList<Cargo*>* list);
    bool Execute(Event* e, Queue<Cargo*>* queue);
    bool Execute(Event* e, PriorityQueue<Cargo*>* PQ, int p);
    Cargo* CI_Cargo(Event* e);
};

