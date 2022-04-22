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
	bool interactiveModeflag ;
	//interactive mode flag to indicate whether the interactive mode will work in the next
	//iterations or not
public:
	UI(Company* comp);
	int readMode();
	void printWaitingCargos() ;
	void printCheckUpTrucks() ;
	void printEmptyTrucks();
	void StepByStepMode() ;
	void silentMode() const;
	void InteractiveMode() ;
	void printDeliveredCargos() ;
	void printMovingCargos() ;
	void printLoadingCargos() ;
	void printday() ;
	void printbyMode() ;
};

