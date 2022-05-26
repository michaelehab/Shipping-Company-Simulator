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

	totalSimHours = 0;

	Events = new Queue<Event*>;

	VIPCargos = new PriorityQueue<Cargo*>;

	SpecialCargos = new Queue<Cargo*>;

	NormalCargos = new LinkedList<Cargo*>;
	DeliveredCargos = new Queue<Cargo*>;

	VIPTrucks = new Queue<Truck*>;
	InCheckupVIPTrucks = new Queue<Truck*>;

	SpecialTrucks = new Queue<Truck*>;
	InCheckupSpecialTrucks = new Queue<Truck*>;

	NormalTrucks = new Queue<Truck*>;
	InCheckupNormalTrucks = new Queue<Truck*>;

	//LoadingTrucks = new Queue<Truck*>;
	MovingTrucks = new PriorityQueue<Truck*>;

	// [0, 1, 2]
	// 0 : The Truck of any type carrying VIP Cargos being loaded.
	// 1 : The Truck of any type carrying Normal Cargos being loaded.
	// 2 : The Truck of any type carrying Special Cargos being loaded.
	loadingTrucks = new Truck * [3];

	for (int i = 0; i < 3; i++) loadingTrucks[i] = NULL;

	simMode = 1;
	ui = new UI(this);
	loadFile();
	ui->readMode();

}

void Company::loadFile() {
	ui->readFileName();
	ifstream inputFile(fileName + ".txt");
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
			if (ET != "") {
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
		}
		else if (eventType == 'X') {
			int id;
			string ET, d, h;

			inputFile >> ET >> id;

			size_t j = 0;
			if (ET != "") {
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
		}
		else if (eventType == 'P') {
			int id;
			double extramoney;
			string ET, d, h;

			inputFile >> ET >> id >> extramoney;

			size_t j = 0;
			if (ET != "") {
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
}

Queue<Event*>* Company::getEvents() const {
	return Events;
}

PriorityQueue<Cargo*>* Company::getVIPCargos() const {
	return VIPCargos;
}

Queue<Cargo*>* Company::getSpecialCargos() const {
	return SpecialCargos;
}

LinkedList<Cargo*>* Company::getNormalCargos() {
	return NormalCargos;
}
Queue<Cargo*>* Company::getDeliveredCargos() const {
	return DeliveredCargos;
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

void Company::simulate()
{
	int day = 1;   //current day

	while (simMode)
	{
		for (int i = 0; i < 24; i++)
		{
			totalSimHours++;
			if (i > 4 && i < 24)
			{
				// Checks if there's an event to execute now (d:h)
				checkEvents(day, i);
				// Checks if there's any truck who finished loading to start its journey
				loadingTruckstoMoving(day, i);
				// Checks if there's any truck who finished its checkup and move it to ready empty trucks
				handleInCheckupTrucks(day, i);
				// Checks if there's any truck who is returning to the company now (d:h) and handle it
				handleReturningTrucks(day, i);
				// Checks if there's any normal cargo who needs to be auto promoted after waiting autoP days
				checkAutoPromotion(day, i);
				// Checks if there's normal/special cargos waiting more than maxW hours and handle them
				checkMaxWRule(day, i);
				// Handles the loading rule for each waiting cargo and truck
				handleLoadingRule(day,i);
				// Checks if now (d:h) is the delivery time of any cargo and handle it
				deliverCargos(day, i);
			}
			// Handles Off-Working hours
			else {
				deliverCargos(day, i);
				handleReturningTrucks(day, i);
				handleInCheckupTrucks(day, i);
			}

			// Checks if the simulation has already ended
			if (checkSimulationEnd())
			{
				simMode = 0;  // the simulation ended
				ui->printbyMode(day, i); //to activate the silentmode function if it was chosen
				writeFile();
				break;
			}

			// Prints the day status to the UI using the appropriate mode selected by the user
			ui->printbyMode(day, i);
		}
		day++;
	}
}

void Company::checkEvents(int currentDay, int currentHour) {
	Event* e;
	while (Events->peek(e) && e->getDay() <= currentDay && e->getHour() <= currentHour)
	{
		Events->dequeue(e);
		e->Execute();
	}
}

bool Company::checkSimulationEnd() {
	return Events->IsEmpty()
		&& SpecialCargos->IsEmpty()
		&& VIPCargos->isEmpty()
		&& NormalCargos->isEmpty()
		&& MovingTrucks->isEmpty()
		&& !loadingTrucks[0] && !loadingTrucks[1] && !loadingTrucks[2]
		&& InCheckupNormalTrucks->IsEmpty()
		&& InCheckupSpecialTrucks->IsEmpty()
		&& InCheckupVIPTrucks->IsEmpty();
}

void Company::handleLoadingRule(int currentDay, int currentHr)
{
	handleVIPLoading(currentDay, currentHr);
	handleSpecialLoading(currentDay, currentHr);
	handleNormalLoading(currentDay,currentHr);
}
void Company::handleVIPLoading(int currentDay, int currentHr)
{
	Truck* t;
	int number = VIPCargos->getSize();
	if (VIPTrucks->peek(t)) {
		if ((number >= t->getTC() || (number && Events->getSize() == 0)) && !loadingTrucks[0])
		{
			LoadVIPCargos();
			VIPTrucks->dequeue(t);
			moveTrucktoLoading(t, currentDay,currentHr, 0);
		}
	}
	else if (NormalTrucks->peek(t)) {
		if ((number >= t->getTC() || (number && Events->getSize() == 0)) && !loadingTrucks[0])
		{
			LoadVIPCargos();
			NormalTrucks->dequeue(t);
			moveTrucktoLoading(t, currentDay, currentHr, 0);
		}
	}
	else if (SpecialTrucks->peek(t)) {
		if ((number >= t->getTC() || (number && Events->getSize() == 0)) && !loadingTrucks[0])
		{
			LoadVIPCargos();
			SpecialTrucks->dequeue(t);
			moveTrucktoLoading(t, currentDay, currentHr, 0);
		}
	}
}
void Company::handleNormalLoading(int currentDay, int currentHr)
{
	Truck* t;
	if (NormalTrucks->peek(t)) {
		if (NormalCargos->getSize() >= t->getTC() && !loadingTrucks[1])
		{
			LoadNormalCargos();
			NormalTrucks->dequeue(t);
			moveTrucktoLoading(t, currentDay, currentHr, 1);
		}
	}
	else if (VIPTrucks->peek(t)) {
		if (NormalCargos->getSize() >= t->getTC() && !loadingTrucks[1])
		{
			LoadNormalCargos();
			VIPTrucks->dequeue(t);
			moveTrucktoLoading(t, currentDay, currentHr, 1);
		}
	}
}
void Company::handleSpecialLoading(int currentDay, int currentHr)
{
	Truck* t;
	if (SpecialTrucks->peek(t)) {
		if (SpecialCargos->getSize() >= t->getTC() && !loadingTrucks[2])
		{
			LoadSpecialCargos();
			SpecialTrucks->dequeue(t);
			moveTrucktoLoading(t, currentDay, currentHr, 2);
		}
	}
}
void Company::LoadVIPCargos()
{
	Truck* t;
	Cargo* c;
	int maxLoadTime = 0;
	int sumUnloadTime = 0;
	int maxDeliveryDist = 0;
	if (VIPTrucks->getSize())
	{
		VIPTrucks->peek(t);
		int TC = t->getTC();
		while (TC-- && VIPCargos->pop(c))  //To load all the TC cargos to the truck
		{
			c->setTID(t->getID());
			t->loadCargo(c);
			maxLoadTime = max(maxLoadTime, c->get_LoadTime());
			sumUnloadTime += c->get_LoadTime();
			maxDeliveryDist = max(maxDeliveryDist, c->getDel_dis());
		}
		t->setMaxCargoLoad(maxLoadTime);
		t->setDI(maxDeliveryDist, sumUnloadTime);
	}
	else if (NormalTrucks->getSize())
	{
		NormalTrucks->peek(t);
		int TC = t->getTC();
		while (TC-- && VIPCargos->pop(c))  //To load all the TC cargos to the truck
		{
			c->setTID(t->getID());
			t->loadCargo(c);
			maxLoadTime = max(maxLoadTime, c->get_LoadTime());
			sumUnloadTime += c->get_LoadTime();
			maxDeliveryDist = max(maxDeliveryDist, c->getDel_dis());
		}
		t->setMaxCargoLoad(maxLoadTime);
		t->setDI(maxDeliveryDist, sumUnloadTime);
	}
	else if (SpecialTrucks->getSize())
	{
		SpecialTrucks->peek(t);
		int TC = t->getTC();
		while (TC-- && VIPCargos->pop(c))  //To load all the TC cargos to the truck
		{
			c->setTID(t->getID());
			t->loadCargo(c);
			maxLoadTime = max(maxLoadTime, c->get_LoadTime());
			sumUnloadTime += c->get_LoadTime();
			maxDeliveryDist = max(maxDeliveryDist, c->getDel_dis());
		}
		t->setMaxCargoLoad(maxLoadTime);
		t->setDI(maxDeliveryDist, sumUnloadTime);
	}
}
void Company::LoadNormalCargos()
{
	Truck* t;
	Cargo* c;
	int maxLoadTime = 0;
	int sumUnloadTime = 0;
	int maxDeliveryDist = 0;
	if (NormalTrucks->getSize())
	{
		NormalTrucks->peek(t);
		int TC = t->getTC();
		while (TC--)  //To load all the TC cargos to the truck
		{
			NormalCargos->pop(c);
			c->setTID(t->getID());
			t->loadCargo(c);
			maxLoadTime = max(maxLoadTime, c->get_LoadTime());
			sumUnloadTime += c->get_LoadTime();
			maxDeliveryDist = max(maxDeliveryDist, c->getDel_dis());
		}
		t->setMaxCargoLoad(maxLoadTime);
		t->setDI(maxDeliveryDist, sumUnloadTime);
	}
	else if (VIPTrucks->getSize())
	{
		VIPTrucks->peek(t);
		int TC = t->getTC();
		while (TC--)  //To load all the TC cargos to the truck
		{
			NormalCargos->pop(c);
			c->setTID(t->getID());
			t->loadCargo(c);
			maxLoadTime = max(maxLoadTime, c->get_LoadTime());
			sumUnloadTime += c->get_LoadTime();
			maxDeliveryDist = max(maxDeliveryDist, c->getDel_dis());
		}
		t->setMaxCargoLoad(maxLoadTime);
		t->setDI(maxDeliveryDist, sumUnloadTime);
	}
}
void Company::LoadSpecialCargos()
{
	Truck* t;
	Cargo* c;
	int maxLoadTime = 0;
	int sumUnloadTime = 0;
	int maxDeliveryDist = 0;

	if (SpecialTrucks->getSize())
	{
		SpecialTrucks->peek(t);
		int TC = t->getTC();
		while (TC--)  //To load all the TC cargos to the truck
		{
			SpecialCargos->dequeue(c);
			c->setTID(t->getID());
			t->loadCargo(c);
			maxLoadTime = max(maxLoadTime, c->get_LoadTime());
			sumUnloadTime += c->get_LoadTime();
			maxDeliveryDist = max(maxDeliveryDist, c->getDel_dis());
		}
		t->setMaxCargoLoad(maxLoadTime);
		t->setDI(maxDeliveryDist, sumUnloadTime);
	}
}
void Company::moveTrucktoLoading(Truck* t, int load_d, int load_h, int idx)
{
	t->setLoadTime(load_d, load_h);
	t->calcDepartmentTime(load_d, load_h);
	// Indicates that a truck carrying this type is being loaded
	loadingTrucks[idx] = t;
}

void Company::movingTrucktoCheckUp(Truck* x)
{
	if (x->getType() == 'N')
	{
		InCheckupNormalTrucks->enqueue(x);
	}
	else if (x->getType() == 'V')
	{
		InCheckupVIPTrucks->enqueue(x);
	}
	else if (x->getType() == 'S')
	{
		InCheckupSpecialTrucks->enqueue(x);
	}
}
void Company::movingTrucktoReady(Truck* x)
{
	if (x->getType() == 'N')
	{
		NormalTrucks->enqueue(x);
	}
	else if (x->getType() == 'V')
	{
		VIPTrucks->enqueue(x);
	}
	else if(x->getType() == 'S')
	{
		SpecialTrucks->enqueue(x);
	}
}

void Company::handleReturningTrucks(int d, int h) {
	Truck* x;
	while (MovingTrucks->peek(x) && x->checkArrivalTime(d, h))
	{
		if (MovingTrucks->pop(x)) {
			if (x->gettotalJourneys() % J == 0)
				movingTrucktoCheckUp(x);
			else
				movingTrucktoReady(x);
		}
	}
};

void Company::loadingTruckstoMoving(int d, int h) 
{
	for (int i = 0; i < 3; i++) {
		if (loadingTrucks[i] && loadingTrucks[i]->checkDepartmentTime(d, h)) {
			srand((unsigned int)time(0));
			// A Very Low Probability of delivery failure
			bool failureProbability = ((1 + (rand() % 1000)) == 123);
			if (failureProbability) {
				movingTrucktoCheckUp(loadingTrucks[i]);
				// removing all the cargos from the truck and moving it to ready
				Cargo* c = loadingTrucks[i]->unloadCargo();
				while (c) {
					VIPCargos->push(c, c->getPriority());
					c = loadingTrucks[i]->unloadCargo();
				}
				int zero = 0;
				// resetting the truck data to spend only the checkup time
				loadingTrucks[i]->setDI(zero, zero);
				loadingTrucks[i]->calcArrivalTime(d, h);
				loadingTrucks[i] = nullptr;
			}
			else {
				loadingTrucks[i]->calcArrivalTime(d, h);
				// Priority is the time the truck comes back to the company (Ascending :-1)
				MovingTrucks->push(loadingTrucks[i], -1 * loadingTrucks[i]->getPriority());
				loadingTrucks[i]->incrementJourneys();
				loadingTrucks[i] = nullptr;
			}
		}
	}
}

void Company::inCheckupVIPToReady(int d, int h) {
	Truck* t;
	while (InCheckupVIPTrucks->peek(t)) {
		if (t->getArrivalTime() + t->getCheckupTime() == d * 24 + h) {
			InCheckupVIPTrucks->dequeue(t);
			VIPTrucks->enqueue(t);
		}
		else break;
	}
}

void Company::inCheckupNormalToReady(int d, int h) {
	Truck* t;
	while (InCheckupNormalTrucks->peek(t)) {
		if (t->getArrivalTime() + t->getCheckupTime() == d * 24 + h) {
			InCheckupNormalTrucks->dequeue(t);
			NormalTrucks->enqueue(t);
		}
		else break;
	}
}

void Company::inCheckupSpecialToReady(int d, int h) {
	Truck* t;
	while (InCheckupSpecialTrucks->peek(t)) {
		if (t->getArrivalTime() + t->getCheckupTime() == d * 24 + h) {
			InCheckupSpecialTrucks->dequeue(t);
			SpecialTrucks->enqueue(t);
		}
		else break;
	}
}

void Company::handleInCheckupTrucks(int d, int h) {
	inCheckupVIPToReady(d, h);
	inCheckupNormalToReady(d, h);
	inCheckupSpecialToReady(d, h);
}

void Company::moveCargotoDelivered(Cargo* c) {
	DeliveredCargos->enqueue(c);
}

void Company::deliverCargos(int d, int h) {
	int sz1 = MovingTrucks->getSize();
	int sz2 = sz1;
	Queue <Truck*> tmp;
	while (sz1--) {
		Truck* t;
		MovingTrucks->pop(t);
		// checkDelivery checks if the CDT of the front of the loaded cargos
		// is d : h, it returns the pointer of this cargo and dequeue it from the truck.
		Cargo* c = t->checkDelivery(d, h);
		while (c) {
			moveCargotoDelivered(c);
			c = t->checkDelivery(d, h);
		}
		tmp.enqueue(t);
	}

	while (sz2--) {
		Truck* t;
		tmp.dequeue(t);
		MovingTrucks->push(t, -1 * t->getPriority());
	}
}

void Company::loadWaitingNormalCargos(int d, int h) {
	Truck* t;
	Cargo* c;
	int maxLoadTime = 0;
	int sumUnloadTime = 0;
	int maxDeliveryDist = 0;
	if (NormalTrucks->getSize())
	{
		NormalTrucks->peek(t);
		int TC = t->getTC();
		while (TC--)
		{
			if (NormalCargos->pop(c)) {
				if ((24 * d + h) - (24 * c->get_d() + c->get_h()) >= maxW) {
					c->setTID(t->getID());
					t->loadCargo(c);
					maxLoadTime = max(maxLoadTime, c->get_LoadTime());
					sumUnloadTime += c->get_LoadTime();
					maxDeliveryDist = max(maxDeliveryDist, c->getDel_dis());
				}
				else {
					NormalCargos->InsertBegin(c);
					break;
				}
			}
			else break;
		}
		t->setMaxCargoLoad(maxLoadTime);
		t->setDI(maxDeliveryDist, sumUnloadTime);
	}
	else if (VIPTrucks->getSize())
	{
		VIPTrucks->peek(t);
		int TC = t->getTC();
		while (TC--)  //To load all the TC cargos to the truck
		{
			if (NormalCargos->pop(c)) {
				if ((24 * d + h) - (24 * c->get_d() + c->get_h()) >= maxW) {
					c->setTID(t->getID());
					t->loadCargo(c);
					maxLoadTime = max(maxLoadTime, c->get_LoadTime());
					sumUnloadTime += c->get_LoadTime();
					maxDeliveryDist = max(maxDeliveryDist, c->getDel_dis());
				}
				else {
					NormalCargos->InsertBegin(c);
					break;
				}
			}
			else break;
		}
		t->setMaxCargoLoad(maxLoadTime);
		t->setDI(maxDeliveryDist, sumUnloadTime);
	}
}

void Company::checkNormalMaxW(int currentDay, int currentHr)
{
	Truck* t;
	if (NormalTrucks->peek(t)) {
		Cargo* c;
		if (NormalCargos->pop(c)) {
			NormalCargos->InsertBegin(c);
			if ((24 * currentDay + currentHr) - (24 * c->get_d() + c->get_h()) >= maxW && !loadingTrucks[1]) {
				loadWaitingNormalCargos(currentDay, currentHr);
				NormalTrucks->dequeue(t);
				moveTrucktoLoading(t, currentDay, currentHr, 1);
			}
		}
	}
	else if (VIPTrucks->peek(t)) {
		Cargo* c;
		if (NormalCargos->pop(c)) {
			NormalCargos->InsertBegin(c);
			if ((24 * currentDay + currentHr) - (24 * c->get_d() + c->get_h()) >= maxW && !loadingTrucks[1]) {
				loadWaitingNormalCargos(currentDay, currentHr);
				VIPTrucks->dequeue(t);
				moveTrucktoLoading(t, currentDay, currentHr, 1);
			}
		}
	}
}

void Company::loadWaitingSpecialCargos(int d, int h) {
	Truck* t;
	Cargo* c;
	int maxLoadTime = 0;
	int sumUnloadTime = 0;
	int maxDeliveryDist = 0;

	if (SpecialTrucks->getSize())
	{
		SpecialTrucks->peek(t);
		int TC = t->getTC();
		while (TC-- && SpecialCargos->peek(c) && (24 * d + h) - (24 * c->get_d() + c->get_h()) >= maxW)
		{
			SpecialCargos->dequeue(c);
			c->setTID(t->getID());
			t->loadCargo(c);
			maxLoadTime = max(maxLoadTime, c->get_LoadTime());
			sumUnloadTime += c->get_LoadTime();
			maxDeliveryDist = max(maxDeliveryDist, c->getDel_dis());
		}
		t->setMaxCargoLoad(maxLoadTime);
		t->setDI(maxDeliveryDist, sumUnloadTime);
	}
}

void Company::checkSpecialMaxW(int currentDay, int currentHr)
{
	Truck* t;
	if (SpecialTrucks->peek(t)) {
		Cargo* c;
		if (SpecialCargos->peek(c) && (24 * currentDay + currentHr) - (24 * c->get_d() + c->get_h()) >= maxW && !loadingTrucks[2]) {
			loadWaitingSpecialCargos(currentDay, currentHr);
			SpecialTrucks->dequeue(t);
			moveTrucktoLoading(t, currentDay, currentHr, 2);
		}
	}
}
void Company::checkMaxWRule(int d, int h) {
	checkNormalMaxW(d, h);
	checkSpecialMaxW(d, h);
}
void Company::checkAutoPromotion(int d, int h)
{
	Cargo* c;
	if (NormalCargos->pop(c)) {
		if(c->get_d() + autoP == d) PromoteNormalCargo(c);
		else NormalCargos->InsertBegin(c);
	}
}
void Company::PromoteNormalCargo(Cargo* c) {
	int p = c->getPriority();
	c->SetCargoT('V');
	c->setAutoPromote(true);
	// Add to VIP Cargos Priority Queue in Company Class
	VIPCargos->push(c, p);
}

bool Company::writeFile() {
	int delivered = DeliveredCargos->getSize();
	string Text = "";
	ofstream outFile(fileName + "-output.txt");
	if (!(outFile.is_open())) return false;
	if (!delivered) {
		Text = "No Delivered Cargos, Check the input file.";
		outFile << Text;
	}
	else generateStatistics(outFile);
	outFile.close();
	if (outFile.is_open()) return false;
	return true;
}

void Company::generateStatistics(ofstream & file) {
	int totalWaitDays = 0, totalWaitHours = 0, totalAutoP = 0;
	int n = 0, s = 0, v = 0;

	file << "CDT \tID \tPT \t\tWT\t\tTID \n";

	// Printing Delivered Cargos details and collected info needed for statistics
	Cargo* c;
	while (DeliveredCargos->dequeue(c)) {
		int wait_d, wait_h;
		c->getWaitingTime(wait_d, wait_h);
		totalWaitDays += wait_d;
		totalWaitHours += wait_h;
		if (c->checkAutoPromoted()) totalAutoP++;

		if (c->getCargoT() == 'N') n++;
		else if (c->getCargoT() == 'V') v++;
		else if (c->getCargoT() == 'S') s++;

		file << c->getCDTDay() << ':' << c->getCDTHour() << " \t" << c->getID() << " \t" << c->get_d() << ':' << c->get_h() << " \t" << wait_d << ':' << wait_h << " \t" << c->getTID() << '\n';
		delete c;
	}

	for (int i = 0; i < 50; i++) file << ".";
	file << '\n';
	for (int i = 0; i < 50; i++) file << ".";
	file << '\n';

	int totalCargos = (n + s + v), totalTrucks = (numOfNormalTrucks + numOfSpecialTrucks + numOfVIPTrucks);

	// Printing Cargos Statistics
	file << "Cargos: " << totalCargos << " [N: " << n << ", S: " << s << ", V:" << v << "]\n";
	writeAvgWait(totalWaitDays, totalWaitHours, totalCargos, file);
	writeAutoPromoted(totalAutoP, n, file);

	int totalActiveHours = 0;
	float totalUtilization = 0;
	// Collecting info from trucks to calculate statistics
	Truck* t;
	while (NormalTrucks->dequeue(t)) {
		totalActiveHours += t->getActiveTime();
		t->calcUtilization(totalSimHours);
		totalUtilization += t->getUtilization();
		delete t;
	}
	while (SpecialTrucks->dequeue(t)) {
		totalActiveHours += t->getActiveTime();
		t->calcUtilization(totalSimHours);
		totalUtilization += t->getUtilization();
		delete t;
	}
	while (VIPTrucks->dequeue(t)) {
		totalActiveHours += t->getActiveTime();
		t->calcUtilization(totalSimHours);
		totalUtilization += t->getUtilization();
		delete t;
	}
	// Printing Trucks Statistics
	file << "Trucks: " << totalTrucks << " [N: " << numOfNormalTrucks << ", S: " << numOfSpecialTrucks << ", V:" << numOfVIPTrucks << "]\n";
	writeAvgActiveTime(totalActiveHours, totalTrucks, file);
	writeAvgUtilization(totalUtilization, totalTrucks, file);
}

void Company::writeAvgWait(int totalWaitD, int totalWaitH, int totalCargos, ofstream& file) {
	int totalWaitTime = totalWaitD * 24 + totalWaitH;
	float avgWaitHour = (totalWaitTime / float(totalCargos));
	int avgWaitDay = 0;
	while (avgWaitHour >= 24) {
		avgWaitHour -= 24;
		avgWaitDay++;
	}
	file << "Cargo Avg Wait = " << avgWaitDay << ':' << avgWaitHour << '\n';
}

void Company::writeAutoPromoted(int totalAutoP, int normalCargos, ofstream& file) {
	float percentage;
	if (normalCargos) percentage = (totalAutoP / float(normalCargos)) * 100;
	else percentage = 0;
	file << "Auto-Promoted Cargos: " << percentage << "% \n";
}

void Company::writeAvgActiveTime(int totalActive, int totalTrucks, ofstream& file) {
	float percentage;
	if (totalSimHours) percentage = (totalActive / float(totalSimHours)) * 100;
	else percentage = 0;
	// float percentage = (totalActive / float(totalTrucks)) * 100;
	file << "Avg Active Time: " << percentage << "% \n";
}

void Company::writeAvgUtilization(float totalUt, int totalTrucks, ofstream& file) {
	float percentage;
	if (totalTrucks) percentage = (totalUt / float(totalTrucks)) * 100;
	else percentage = 0;
	// float percentage = (totalActive / float(totalSimHours)) * 100;
	file << "Avg Utilization: " << percentage << "% \n";
}

void Company::setFileName(string name) {
	fileName = name;
}
Company::~Company() {
	// All these lists are already empty at this point
	delete Events;
	delete VIPCargos;
	delete SpecialCargos;
	delete NormalCargos;
	delete DeliveredCargos;
	delete VIPTrucks;
	delete InCheckupVIPTrucks; 
	delete SpecialTrucks;
	delete InCheckupSpecialTrucks;
	delete NormalTrucks;
	delete InCheckupNormalTrucks;
	delete MovingTrucks;
	delete loadingTrucks;
}