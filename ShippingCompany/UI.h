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
	int mode;
public:
	UI(Company* comp);
	int readMode();
	void printWaitingCargos();
	void printCheckUpTrucks();
	void printEmptyTrucks();
};

