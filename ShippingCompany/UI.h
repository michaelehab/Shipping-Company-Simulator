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
	void printWaitingCargos() const;
	void printCheckUpTrucks() const;
	void printEmptyTrucks()const;
	void StepByStepMode() const;
	void silentMode() const;
	void InteractiveMode() const;
};

