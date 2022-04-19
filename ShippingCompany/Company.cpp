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
	/*numOfNormalTrucks = 0;
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

	numOfEvents = 0;*/

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

	LoadingTrucks = new Queue<Truck*>;
	MovingTrucks = new Queue<Truck*>;
	
	loadFile();
	ui = new UI(this);
	ui->readMode();
}

void Company::loadFile() {
	ifstream inputFile("input.txt");
	if (!inputFile) numOfNormalTrucks = -1;
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
	
	
	for (int i = 0; i < numOfNormalTrucks; i++) {
		Truck* loadedTruck = new Truck(i + 1, 'N', capOfNormalTrucks, normalCheckupDuration, speedOfNormalTrucks);
		NormalTrucks->enqueue(loadedTruck);
	}

	for (int i = 0; i < numOfSpecialTrucks; i++) {
		Truck* loadedTruck = new Truck(i + 1, 'S', capOfSpecialTrucks, specialCheckupDuration, speedOfSpecialTrucks);
		SpecialTrucks->enqueue(loadedTruck);
	}

	for (int i = 0; i < numOfVIPTrucks; i++) {
		Truck* loadedTruck = new Truck(i + 1, 'V', capOfVIPTrucks, VIPCheckupDuration, speedOfVIPTrucks);
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

			Event* tmp = new PreparationEvent(i + 1, day, hour, eventType, type, dist, lt, cost,this);
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
			Event* tmp = new CancelEvent(id, day, hour, eventType,this);
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
			Event* tmp = new PromoteEvent(id, day, hour, eventType, extramoney,this);
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

LinkedList<Cargo*>* Company::getNormalCargos() const {
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

Queue<Truck*>* Company::getLoadingTrucks() const {
	return LoadingTrucks;
}
Queue<Truck*>* Company::getMovingTrucks() const {
	return MovingTrucks;
}
