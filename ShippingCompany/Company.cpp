#include "Company.h"
#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "PriorityQueue.h"
#include "Queue.h"
#include "LinkedList.h"

#include "Cargo.h"
#include "Truck.h"

#include "Event.h"
#include "PreparationEvent.h"
#include "CancelEvent.h"
#include "PromoteEvent.h"
#include "UI.h"

Company::Company()
{
	numOfNormalTrucks = 0;
	numOfSpecialTrucks = 0;
	numOfVIPTrucks = 0;
	speedOfNormalTrucks = 0;
	speedOfSpecialTrucks = 0;
	speedOfVIPTrucks = 0;
	capOfNormalTrucks = 0;
	capOfSpecialTrucks = 0;
	capOfVIPTrucks = 0;
	J = 0;

	normalCheckupDuration = 0;
	specialCheckupDuration = 0;
	VIPCheckupDuration = 0;
	autoP = 0;

	maxW = 0;

	numOfEvents = 0;

	Events = new Queue<Event*>;

	VIPCargos = new PriorityQueue<Cargo*>;
	DeliveredVIPCargos = new Queue<Cargo*>;

	SpecialCargos = new Queue<Cargo*>;
	DeliveredSpecialCargos = new Queue<Cargo*>;

	NormalCargos = new LinkedList<Cargo*>;
	DeliveredNormalCargos = new Queue<Cargo*>;

	VIPTrucks = new Queue<Truck*>;
	InCheckupVIPTrucks = new Queue<Truck*>;

	SpecialTrucks = new Queue<Truck*>;
	InCheckupSpecialTrucks = new Queue<Truck*>;

	NormalTrucks = new Queue<Truck*>;
	InCheckupNormalTrucks = new Queue<Truck*>;

	//LoadingTrucks = new Queue<Truck*>;
	MovingTrucks = new PriorityQueue<Truck*>;

	loadingTrucks = new Truck * [3];

	for (int i = 0; i < 3; i++)
		loadingTrucks[i] = NULL;

	simMode = 1;
	loadFile();
	ui = new UI(this);
	ui->readMode();

}

void Company::loadFile() {
	ifstream inputFile("input2.txt");
	if (!inputFile) {
		return;
	}
	inputFile >> numOfNormalTrucks;
	inputFile >> numOfSpecialTrucks;
	inputFile >> numOfVIPTrucks;

	inputFile >> speedOfNormalTrucks;
	inputFile >> speedOfSpecialTrucks;
	inputFile >> speedOfVIPTrucks;

	inputFile >> capOfNormalTrucks;
	inputFile >> capOfSpecialTrucks;
	inputFile >> capOfVIPTrucks;

	inputFile >> J;
	inputFile >> normalCheckupDuration;
	inputFile >> specialCheckupDuration;
	inputFile >> VIPCheckupDuration;

	int j = 1;
	for (int i = 0; i < numOfNormalTrucks; i++) {
		Truck* loadedTruck = new Truck(j++, 'N', capOfNormalTrucks, normalCheckupDuration, speedOfNormalTrucks);
		NormalTrucks->enqueue(loadedTruck);
	}

	for (int i = 0; i < numOfSpecialTrucks; i++) {
		Truck* loadedTruck = new Truck(j++, 'S', capOfSpecialTrucks, specialCheckupDuration, speedOfSpecialTrucks);
		SpecialTrucks->enqueue(loadedTruck);
	}

	for (int i = 0; i < numOfVIPTrucks; i++) {
		Truck* loadedTruck = new Truck(j++, 'V', capOfVIPTrucks, VIPCheckupDuration, speedOfVIPTrucks);
		VIPTrucks->enqueue(loadedTruck);
	}

	inputFile >> autoP;
	inputFile >> maxW;

	inputFile >> numOfEvents;
	for (int i = 0; i < numOfEvents; i++) {
		char eventType;
		inputFile >> eventType;
		if (eventType == 'R') {
			char type;
			double cost;
			int lt, id, dist;
			string ET, d, h;
			inputFile >> type >> ET >> id >> dist >> lt >> cost;

			// Converting the Day:Hour string to two separated int variables

			size_t j = 0;
			while (ET[j] != ':') {
				d += ET[j++];
			}

			j++;
			while (j < ET.length()) {
				h += ET[j++];
			}

			int day = stoi(d), hour = stoi(h);

			Event* tmp = new PreparationEvent(id, day, hour, eventType, type, dist, lt, cost, this);
			Events->enqueue(tmp);
		}
		else if (eventType == 'X') {
			int id;
			string ET, d, h;

			inputFile >> ET >> id;

			size_t j = 0;
			while (ET[j] != ':') {
				d += ET[j++];
			}

			j++;
			while (j < ET.length()) {
				h += ET[j++];
			}

			int day = stoi(d), hour = stoi(h);
			Event* tmp = new CancelEvent(id, day, hour, eventType, this);
			Events->enqueue(tmp);
		}
		else if (eventType == 'P') {
			int id;
			double extramoney;
			string ET, d, h;

			inputFile >> ET >> id >> extramoney;

			size_t j = 0;
			while (ET[j] != ':') {
				d += ET[j++];
			}

			j++;
			while (j < ET.length()) {
				h += ET[j++];
			}

			int day = stoi(d), hour = stoi(h);
			Event* tmp = new PromoteEvent(id, day, hour, eventType, extramoney, this);
			Events->enqueue(tmp);
		}
	}
}

Queue<Event*>* Company::getEvents() const {
	return Events;
}

PriorityQueue<Cargo*>* Company::getVIPCargos() const {
	return VIPCargos;
}
Queue<Cargo*>* Company::getDeliveredVIPCargos() const {
	return DeliveredVIPCargos;
}

Queue<Cargo*>* Company::getSpecialCargos() const {
	return SpecialCargos;
}
Queue<Cargo*>* Company::getDeliveredSpecialCargos() const {
	return DeliveredSpecialCargos;
}

LinkedList<Cargo*>* Company::getNormalCargos() {
	return NormalCargos;
}
Queue<Cargo*>* Company::getDeliveredNormalCargos() const {
	return DeliveredNormalCargos;
}

Queue<Truck*>* Company::getNormalTrucks() const {
	return NormalTrucks;
}
Queue<Truck*>* Company::getInCheckupNormalTrucks() const {
	return InCheckupNormalTrucks;
}

Queue<Truck*>* Company::getSpecialTrucks() const {
	return SpecialTrucks;
}
Queue<Truck*>* Company::getInCheckupSpecialTrucks() const {
	return InCheckupSpecialTrucks;
}

Queue<Truck*>* Company::getVIPTrucks() const {
	return VIPTrucks;
}
Queue<Truck*>* Company::getInCheckupVIPTrucks() const {
	return InCheckupVIPTrucks;
}
Truck** Company::getLoadingTrucks() const {
	return loadingTrucks;
}
PriorityQueue<Truck*>* Company::getMovingTrucks() const {
	return MovingTrucks;
}
bool Company::getSimulationStatus() const
{
	return simMode;
}

void Company::simulate_day()
{
	/*
	EVERY DAY : EVERY HOUR

	DAY : OFF HOURS
	handleReturningTrucks();
	handleInCheckupTrucks();


	DAY : WORKING HOURS
		checkEvent();

		handleLoadingRule(){
			handleVIPLoading(){
				// If Ready cargos >= Truck TC && !loadingTrucks[0]
					LoadVIPCargo(); // assign waiting time = current time - ready time;
					moveTrucktoLoading(); // assign load_d = d, load_h = h;
			};
			handleNormalLoading(){
				LoadNormalCargo(); // assign waiting time = current time - ready time;
				moveTrucktoLoading();
			};
			handleSpecialLoading(){
				LoadSpecialCargo(); // assign waiting time = current time - ready time;
				moveTrucktoLoading();
			};
		}

		// In case of "at the same time" == "until the load is fully completed"

		// Truck * loadingTrucks = {null, null, null};
		loadingTrucks[0] indicates the truck loading VIP type
		loadingTrucks[1] indicates the truck loading Normal type
		loadingTrucks[2] indicates the truck loading special type
		if loadingTrucks[i] == null this means that we can load this type again.


		loadingTruckstoMoving(){
			for i = 0 to 2:
				if(loadingTrucks[i] && loadingTrucks[i]->checkDepartmentTime(d, h)){
					movingTrucks->enqueue(loadingTrucks[i], loadingTrucks[i]->getPriority());
					loadingTrucks[i] = nullptr;
				}
		}


		checkMaxWRule(){
			checkNormalMaxW(){
				LoadNormalCargo(); // If waiting >= MaxW
			};
			checkSpecialMaxW(){
				LoadSpecialCargo();
			};
		}

		checkAutoPromotion(){
			// If truck -> (d + autoP) == current time
			PromoteNormalCargo();
		};

		handleReturningTrucks(){
			// if truck -> totalJourneys % truck -> J == 0
				movingTrucktoCheckUp(); // increment totalJourneys
			// else
				movingTrucktoReady(); // increment totalJourneys
		};

		handleInCheckupTrucks(){
			inCheckupVIPToReady();
			inCheckupNormalToReady();
			inCheckupSpecialToReady();
		};

		deliverCargos(){
			int sz1 = sz2 = movingTrucks->getSize();
			Queue <Truck*> tmp;
			while(sz1--){
				Truck * t;
				movingTrucks->dequeue(t);

				// checkDelivery checks if the CDT of the front of the loaded cargos
				// is d : h, it returns the pointer of this cargo and dequeue it from the truck.
				Cargo * c = tmp->checkDelivery(d, h); // may increment totalDeliveredCargos
				if(c){
					moveCargotoDelivered(c);
				}

				tmp.enqueue(t);
			}

			while(sz2--){
				Truck * t;
				tmp.dequeue(t);
				movingTrucks->enqueue(t, t->getPriority());
			}
		};

		ui->printbymode();

		AFTER END OF DAYS
		generateOutputFile();

	*/
	int day = 1;   //current day
	Event* e;
	int d, h;		// day and hour of the event
	int countts = 0;  //count the time steps to move the cargos from waiting cargos to delivered after 5 timesteps
	while (simMode)
	{
		for (int i = 0; i < 25; i++)
		{
			if (i > 4 && i < 24)
			{
				Events->peek(e);
				e->getEt(d, h);
				while (!(Events->IsEmpty()) && d == day && h == i)
				{
					Events->dequeue(e);
					e->Execute();
					Events->peek(e);
					e->getEt(d, h);
				}
				handleLoadingRule(day,i);
				/*if (countts == 5)
				{
					Cargo* car = NULL;
					if (NormalCargos->pop(car))
						DeliveredNormalCargos->enqueue(car);
					car = NULL;
					if (SpecialCargos->dequeue(car))
						DeliveredSpecialCargos->enqueue(car);
					car = NULL;
					if (VIPCargos->pop(car))
						DeliveredVIPCargos->enqueue(car);
					car = NULL;
					countts = 0;
				}*/

				/*countts++;*/
				ui->printbyMode(day, i);

				if (Events->IsEmpty() && SpecialCargos->IsEmpty() && VIPCargos->isEmpty() && NormalCargos->isEmpty())
				{
					simMode = 0;  // the simulation ended
					ui->printbyMode(day, i); //to activate the silentmode function if it was chosen
					break;
				}


			}
		}
		day++;
	}
}

void Company::handleLoadingRule(int currentDay, int currentHr)
{
	handleVIPLoading(currentDay, currentHr);
	handleNormalLoading(currentDay,currentHr);
}
void Company::handleVIPLoading(int currentDay, int currentHr)
{
	Truck* t;
	VIPTrucks->peek(t); // gets the first truck in the priorityQueue to get its TC
	if (VIPCargos->getSize() >= t->getTC() && !loadingTrucks[0])
	{
		LoadVIPCargo();
		VIPTrucks->dequeue(t);
		moveTrucktoLoading(t, currentDay,currentHr);
	}
}
void Company::handleNormalLoading(int currentDay, int currentHr)
{
	Truck* t;
	NormalTrucks->peek(t);
	if (NormalCargos->getSize() >= t->getTC() && !loadingTrucks[1])
	{
		LoadNormalCargo();
		NormalTrucks->dequeue(t);
		moveTrucktoLoading(t, currentDay, currentHr);
	}
}
void Company::LoadVIPCargo()
{
	Truck* t;
	Cargo* c;
	if (VIPTrucks->getSize())
	{
		VIPTrucks->peek(t);
		int TC = t->getTC();
		while (TC--)  //To load all the TC cargos to the truck
		{
			VIPCargos->pop(c);
			t->loadCargo(c);
		}
	}
	else if (NormalTrucks->getSize())
	{
		NormalTrucks->peek(t);
		int TC = t->getTC();
		while (TC--)  //To load all the TC cargos to the truck
		{
			NormalCargos->pop(c);
			t->loadCargo(c);
		}
	}
	else if (SpecialTrucks->getSize())
	{
		SpecialTrucks->peek(t);
		int TC = t->getTC();
		while (TC--)  //To load all the TC cargos to the truck
		{
			SpecialCargos->dequeue(c);
			t->loadCargo(c);
		}
	}
}
void Company::LoadNormalCargo()
{
	Truck* t;
	Cargo* c;
	if (NormalTrucks->getSize())
	{
		NormalTrucks->peek(t);
		int TC = t->getTC();
		while (TC--)  //To load all the TC cargos to the truck
		{
			NormalCargos->pop(c);
			t->loadCargo(c);
		}
	}
	else if (VIPTrucks->getSize())
	{
		VIPTrucks->peek(t);
		int TC = t->getTC();
		while (TC--)  //To load all the TC cargos to the truck
		{
			VIPCargos->pop(c);
			t->loadCargo(c);
		}
	}
}
void Company::moveTrucktoLoading(Truck* t,int load_d,int load_h)
{
	t->setLoadTime(load_d, load_h);
	if (t->getType() == 'V')
		loadingTrucks[0] = t;
	else if (t->getType() == 'N')
		loadingTrucks[1] = t;
	else if(t->getType() == 'S')
		loadingTrucks[2] = t;
		
}

/*
	TODO :
	Company Destructor : Empty all lists
*/