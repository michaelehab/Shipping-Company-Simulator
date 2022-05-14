#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "PriorityQueue.h"
#include "Queue.h"
#include "LinkedList.h"

#include "Cargo.h"
#include "Truck.h"

class UI;
class Event;
class PreparationEvent;
class CancelEvent;
class PromoteEvent;
using namespace std;

class Company {
	Queue<Event*>* Events;

	PriorityQueue<Cargo*>* VIPCargos;

	Queue<Cargo*>* SpecialCargos;

	LinkedList<Cargo*>* NormalCargos;

	Queue<Cargo*>* DeliveredCargos;

	Queue<Truck*>* VIPTrucks;
	Queue<Truck*>* InCheckupVIPTrucks;

	Queue<Truck*>* SpecialTrucks;
	Queue<Truck*>* InCheckupSpecialTrucks;

	Queue<Truck*>* NormalTrucks;
	Queue<Truck*>* InCheckupNormalTrucks;

	//Queue<Truck*>* LoadingTrucks;
	PriorityQueue<Truck*>* MovingTrucks;
	Truck** loadingTrucks;

	UI* ui;

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

	bool simMode;		
	//The simulation mode, if simMode=1 the simulation is working, else the simulation has ended
	//it will be used by the silent mode to determine when to print its output
public:
	Company();
	void loadFile();
	void simulate_day();
	Queue<Event*>* getEvents() const;

	PriorityQueue<Cargo*>* getVIPCargos() const;

	Queue<Cargo*>* getSpecialCargos() const;

	LinkedList<Cargo*>* getNormalCargos();
	Queue<Cargo*>* getDeliveredCargos() const;

	Queue<Truck*>* getNormalTrucks() const;
	Queue<Truck*>* getInCheckupNormalTrucks() const;

	Queue<Truck*>* getSpecialTrucks() const;
	Queue<Truck*>* getInCheckupSpecialTrucks() const;

	Queue<Truck*>* getVIPTrucks() const;
	Queue<Truck*>* getInCheckupVIPTrucks() const;

	Truck** getLoadingTrucks() const;
	
	PriorityQueue<Truck*>* getMovingTrucks() const;

	bool getSimulationStatus() const;

	// Loading Cargo related functions
	void handleLoadingRule(int currentDay,int currentHr );
	void handleVIPLoading(int currentDay, int currentHr);
	void handleNormalLoading(int currentDay, int currentHr);
	void handleSpecialLoading(int currentDay, int currentHr);
	void LoadVIPCargos();
	void LoadNormalCargos();
	void LoadSpecialCargos();
	void moveTrucktoLoading(Truck*,int,int);
	void moveCargotoDelivered(Cargo*);
	void movingTrucktoCheckUp(Truck* x);
	void movingTrucktoReady(Truck* x);
	void handleReturningTrucks(int, int);
	void loadingTruckstoMoving(int d, int h);
	void inCheckupVIPToReady(int, int);
	void inCheckupNormalToReady(int, int);
	void inCheckupSpecialToReady(int, int);
	void handleInCheckupTrucks(int, int);
	void deliverCargos(int, int);
};

