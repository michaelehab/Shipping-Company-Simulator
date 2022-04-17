#pragma once
#include "LinkedList.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Cargo.h"
#include "Truck.h"
class UI
{
public:
	void printWaitingCargos(LinkedList<Cargo*> *n,Queue<Cargo*> *s,PriorityQueue<Cargo*>* vip);
	void printCheckUpTrucks(Queue<Truck*>* n, Queue<Truck*>* s, Queue<Truck*>* vip);
};

