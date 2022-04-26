#include "UI.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

UI::UI(Company* comp)
{
	c = comp;
	interactiveModeflag = 1;
}
void UI::printWaitingCargos() 
{
	cout << "Waiting Cargos: [";
	c->getNormalCargos()->PrintLL();
	cout << "] (";
	c->getSpecialCargos()->print();
	cout << ") {";
	c->getVIPCargos()->PrintPQ();
	cout << "} " << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}
void UI::printCheckUpTrucks() 
{
	cout << "In-Checkup Trucks: [";
	c->getInCheckupNormalTrucks()->print();
	cout << "] (";
	c->getInCheckupSpecialTrucks()->print();
	cout << ") {";
	c->getInCheckupVIPTrucks()->print();
	cout << "} " << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;

}

void UI::printEmptyTrucks() 
{
	cout << "Empty Trucks: [";
	c->getNormalTrucks()->print();
	cout << "] (";
	c->getSpecialTrucks()->print();
	cout << ") {";
	c->getVIPTrucks()->print();
	cout << "} " << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

int UI::readMode()
{
	cout << "Please select the program mode:" << endl;
	cout << "1. Interactive Mode" << endl;
	cout << "2. Step-By-Step Mode" << endl;
	cout << "3. Silent Mode" << endl;
	cout << "Selected Mode : ";
	cin >> mode;
	if (mode == 1)
		cout << "Interactive Mode: " << endl;
	else if (mode == 2)
		cout << "Step by step Mode:" << endl;
	else if (mode == 3)
		cout << "Silent Mode" << endl;
	return mode;
}

void UI::StepByStepMode(int day, int hour)
{
	if (c->getSimulationStatus())
	{
		cout << "Current Time (Day:Hour): " << day << ":" << hour << endl;
		printday(); // Prints the day after being simulated
		Sleep(1000); // Waits for a second
	}
	else
	{
		cout << "Simulation ends, Output file created" << endl;
	}
}

void UI::silentMode() const
{
	if (!(c->getSimulationStatus()))
	{
		cout << "Simulation Starts..." << endl;
		cout << "Simulation ends, Output file created" << endl;
	}
}
void UI::InteractiveMode(int day, int hour)
{
	if (c->getSimulationStatus())
	{
		cout << "Press Enter to continue, else press any key." << endl;
		if (interactiveModeflag && cin.get() == '\n')
		{
			cout << "Current Time (Day:Hour): " << day << ":" << hour << endl;
			printday(); // Prints the day after being simulated
		}
		else
			interactiveModeflag = 0;
	}
	else 
	{
		cout << "Simulation ends, Output file created" << endl;
	}
}

void UI::printDeliveredCargos() 
{
	cout << "Delivered Cargos: {";
	c->getDeliveredVIPCargos()->print();
	cout << "} ";
	cout << "[";
	c->getDeliveredNormalCargos()->print();
	cout << "] ";
	cout << "(";
	c->getDeliveredSpecialCargos()->print();
	cout << ") \n";
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void UI::printMovingCargos() 
{
	cout << "Moving Cargos: ";
	c->getMovingTrucks()->print();
	cout << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void UI::printLoadingTrucks() 
{
	cout << "Loading Trucks: ";
	c->getLoadingTrucks()->print(); 
	cout << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void UI::printday() 
{
	printWaitingCargos();
	printLoadingTrucks();
	printEmptyTrucks();
	printMovingCargos();
	printCheckUpTrucks();
	printDeliveredCargos();
}
void UI::printbyMode(int day,int hour) 
{
	
	if (mode == 1)
		InteractiveMode(day,hour);
	else if (mode == 2)
		StepByStepMode(day,hour);
	else if (mode == 3)
		silentMode();


}
