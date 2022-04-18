#pragma once
#include "LinkedList.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "Cargo.h"
#include "Truck.h"
#include "Company.h"
class UI
{
	Company* c;
public:
	UI(Company* comp);
	void printWaitingCargos();
	void printCheckUpTrucks();
	void printEmptyTrucks();
};

