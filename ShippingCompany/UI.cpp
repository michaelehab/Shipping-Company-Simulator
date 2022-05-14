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
	int normal = c->getNormalCargos()->getSize();
	int special = c->getSpecialCargos()->getSize();
	int vip = c->getVIPCargos()->getSize();
	int total = normal + special + vip;

	cout << total << " Waiting Cargos: ";
	if (normal) {
		cout << '[';
		c->getNormalCargos()->PrintLL();
		cout << "] ";
	}
	if (special) {
		cout << '(';
		c->getSpecialCargos()->print();
		cout << ") ";
	}
	if (vip) {
		cout << '{';
		c->getVIPCargos()->PrintPQ();
		cout << "} ";
	}
	cout << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}
void UI::printCheckUpTrucks()
{
	int normal = c->getInCheckupNormalTrucks()->getSize();
	int special = c->getInCheckupSpecialTrucks()->getSize();
	int vip = c->getInCheckupVIPTrucks()->getSize();
	int total = normal + special + vip;

	cout << total << " In-Checkup Trucks: ";
	if (normal) {
		cout << '[';
		c->getInCheckupNormalTrucks()->print();
		cout << "] ";
	}
	if (special) {
		cout << '(';
		c->getInCheckupSpecialTrucks()->print();
		cout << ") ";
	}
	if (vip) {
		cout << '{';
		c->getInCheckupVIPTrucks()->print();
		cout << "} ";
	}
	cout << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;

}

void UI::printEmptyTrucks()
{
	int normal = c->getNormalTrucks()->getSize();
	int special = c->getSpecialTrucks()->getSize();
	int vip = c->getVIPTrucks()->getSize();
	int total = normal + special + vip;

	cout << total << " Empty Trucks: ";
	if (normal) {
		cout << '[';
		c->getNormalTrucks()->print();
		cout << "] ";
	}
	if (special) {
		cout << '(';
		c->getSpecialTrucks()->print();
		cout << ") ";
	}
	if (vip) {
		cout << '{';
		c->getVIPTrucks()->print();
		cout << "} ";
	}
	cout << endl;
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
		cout << "Press Enter to continue." << endl;
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
	int total = c->getDeliveredCargos()->getSize();

	cout << total << " Delivered Cargos: ";
	if (total) {
		c->getDeliveredCargos()->print();
	}
	cout << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void UI::printMovingCargos()
{
	int total = c->getMovingTrucks()->getSize();
	cout << total << " Moving Cargos: ";
	c->getMovingTrucks()->PrintPQ();
	cout << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
	cout << endl;
}

void UI::printLoadingTrucks()
{
	int total = 0;
	Truck* * t = c->getLoadingTrucks();  //gets the loadingTrucks pointer to pointers
	for (int i = 0; i < 3; i++)
		if (t[i]) total++;
	cout << total << " Loading Trucks: ";
	for (int i = 0; i < 3; i++)
		if (t[i]) cout << t[i] << " ";
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
void UI::printbyMode(int day, int hour)
{

	if (mode == 1)
		InteractiveMode(day, hour);
	else if (mode == 2)
		StepByStepMode(day, hour);
	else if (mode == 3)
		silentMode();


}
