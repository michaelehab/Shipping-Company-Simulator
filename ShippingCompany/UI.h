#pragma once
#include "Cargo.h"
#include "Company.h"
class UI
{
	Company* c;
	int mode;
	//interactive mode flag to indicate whether the interactive mode will work in the next
	//iterations or not
	bool interactiveModeflag;
public:
	UI(Company* comp); // UI Constructor
	int readMode(); // Reads the program interface mode
	void printWaitingCargos(); // Prints the currently waiting cargos
	void printCheckUpTrucks(); // Prints the trucks currently in checkup
	void printEmptyTrucks(); // Prints the currently empty trucks
	void StepByStepMode(int day, int hour); // Shows the program steps in step-by-step mode
	void silentMode() const; // Shows only the silent mode messages
	void InteractiveMode(int day, int hour); // Show the program steps in interactive mode
	void printDeliveredCargos(); // Prints the delivered cargos
	void printMovingCargos(); // Prints the currently moving cargos
	void printLoadingTrucks(); // Prints the trucks in loading state
	void printday(); // Prints a day in simulation
	void printbyMode(int day, int hour); // Prints days using the right mode
	void readFileName(); // Reads the i/o files name
	~UI(); // UI Destructor
};

