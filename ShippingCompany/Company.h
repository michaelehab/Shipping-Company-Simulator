#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "UI.h"

#include "PriorityQueue.h"
#include "Queue.h"
#include "LinkedList.h"



#include "Cargo.h"
#include "Truck.h"
class Event;
class PreparationEvent;
class CancelEvent;
class PromoteEvent;
using namespace std;

class Company {
	Queue<Event*>* Events;

	PriorityQueue<Cargo*>* VIPCargos;
	Queue<Cargo*>* DeliveredVIPCargos;

	Queue<Cargo*>* SpecialCargos;
	Queue<Cargo*>* DeliveredSpecialCargos;

	LinkedList<Cargo*>* NormalCargos;
	Queue<Cargo*>* DeliveredNormalCargos;

	Queue<Truck*>* VIPTrucks;
	Queue<Truck*>* InCheckupVIPTrucks;

	Queue<Truck*>* SpecialTrucks;
	Queue<Truck*>* InCheckupSpecialTrucks;

	Queue<Truck*>* NormalTrucks;
	Queue<Truck*>* InCheckupNormalTrucks;

	Queue<Truck*>* LoadingTrucks;
	Queue<Truck*>* MovingTrucks;

	int numOfNormalTrucks, numOfSpecialTrucks, numOfVIPTrucks;
	int speedOfNormalTrucks, speedOfSpecialTrucks, speedOfVIPTrucks;
	int capOfNormalTrucks, capOfSpecialTrucks, capOfVIPTrucks;

	// The number of journeys the truck completes before performing a checkup
	int J;

	int normalCheckupDuration, specialCheckupDuration, VIPCheckupDuration;

	// Represents the number of hours after which a normal cargo 
	// is automatically promoted to a VIP cargo.
	int autoP;

	// If there is an available truck that is suitable for a cargo that
	// has been waiting for MaxW hours(or more), such cargo should be immediately
	// loaded and moved to its destination.
	int maxW;

	int numOfEvents;

public:
	Company();
	void loadFile();
};

