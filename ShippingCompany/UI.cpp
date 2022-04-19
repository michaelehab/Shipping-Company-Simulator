#include "UI.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

UI::UI(Company* comp)
{
	c = comp;
}
void UI::printWaitingCargos() const
{
	cout << "Waiting Cargos: [";
	c->getNormalCargos()->printList();
	cout << "] (";
	c->getSpecialCargos()->print();
	cout << ") {" ;
	c->getVIPCargos()->PrintPQ();
	cout << "} " << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
}
void UI::printCheckUpTrucks() const
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

}

void UI::printEmptyTrucks() const
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
}

int UI::readMode()
{
	cout << "Please select the program mode:" << endl;
	cout << "1. Interactive Mode" << endl; 
	cout << "2. Step-By-Step Mode" << endl;
	cout << "3. Silent Mode" << endl;
	cout << "Selected Mode : ";
	cin >> mode;
	return mode;
}

void UI::StepByStepMode() const
{

	cout << "Step by step Mode:" << endl;
	/*
	while (!c->isLastDay())
	{
		p_station->simulate_day(); // Simulates a whole day
		PrintDay(); // Prints the day after being simulated
		Sleep(1000); // Waits for a second
	}
	// Generates the output file 
	if (c->writeFile()) cout << "Simulation ends, Output file created";
	else cout << "An Error happened, Please Try again!";
	*/
}

void UI::silentMode() const
{
	cout << "Silent Mode" << endl;
	cout << "Simulation Starts..." << endl;
	cout << "Simulation ends, Output file created" << endl;

	/*
	// Generates the output file 
	if (c->writeFile()) cout << "Simulation ends, Output file created";
	else cout << "An Error happened, Please Try again!";
	*/
}
void UI::InteractiveMode() const
{
	cout << "Interactive Mode: " << endl;
	//while (!c->isLastDay() && cin.get()=='\n')
	//{
	//	c->simulate_day(); // Simulates a whole day
	//	PrintDay(); // Prints the day after being simulated
	// cin.ignore();
	// cout<<"\nPress Enter to continue"<<endl;
	//}

	/*
	// Generates the output file
	if (c->writeFile()) cout << "Simulation ends, Output file created";
	else cout << "An Error happened, Please Try again!";
	*/
}

