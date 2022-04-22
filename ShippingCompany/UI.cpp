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
	c->getNormalCargos()->printList();
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

void UI::StepByStepMode() 
{
	if (c->getsimMode())
	{
		printday(); // Prints the day after being simulated
		Sleep(1000); // Waits for a second
	}
/*
// Generates the output file
if (c->writeFile()) cout << "Simulation ends, Output file created";
else cout << "An Error happened, Please Try again!";
*/
}

void UI::silentMode() const
{
	if (!(c->getsimMode()))
	{
		cout << "Simulation Starts..." << endl;
		cout << "Simulation ends, Output file created" << endl;
	}

	/*
	// Generates the output file
	if (c->writeFile()) cout << "Simulation ends, Output file created";
	else cout << "An Error happened, Please Try again!";
	*/
}
void UI::InteractiveMode() 
{
	if (c->getsimMode())
	{
		if (interactiveModeflag && cin.get() == '\n')
		{
			printday(); // Prints the day after being simulated
			cin.ignore();
			cout << "\nPress Enter to continue, else press any key." << endl;
		}
		else
			interactiveModeflag = 0;
	}

	/*
	// Generates the output file
	if (c->writeFile()) cout << "Simulation ends, Output file created";
	else cout << "An Error happened, Please Try again!";
	*/
}

void UI::printDeliveredCargos() 
{
	cout << "Delivered Cargos: { ";
	c->getDeliveredVIPCargos()->print();
	cout << " } ";
	cout << "[ ";
	c->getDeliveredNormalCargos()->print();
	cout << " ] ";
	cout << "( ";
	c->getDeliveredSpecialCargos()->print();
	cout << " ) \n";
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void UI::printMovingCargos() 
{
	c->getMovingTrucks()->print();
}

void UI::printLoadingCargos() 
{
	c->getLoadingTrucks()->print();
}

void UI::printday() 
{
	printWaitingCargos();
	printLoadingCargos();
	printEmptyTrucks();
	printMovingCargos();
	printCheckUpTrucks();
	printDeliveredCargos();
}
void UI::printbyMode() 
{
	if (mode == 1)
		InteractiveMode();
	else if (mode == 2)
		StepByStepMode();
	else if (mode == 3)
		silentMode();


}
