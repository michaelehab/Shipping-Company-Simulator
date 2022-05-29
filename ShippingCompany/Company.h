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

	//The simulation mode, if simMode=1 the simulation is working, else the simulation has ended
	//it will be used by the silent mode to determine when to print its output
	bool simMode;		

	int totalSimHours;

	string fileName;

	int numOfNormalCargos, numOfSpecialCargos, numOfVIPCargos;
public:
	Company(); // The Company Constructor
	void loadFile(); // Loads the input file
	void setFileName(string); // Sets the file name
	void simulate(); // Runs the Company Simulation
	Queue<Event*>* getEvents() const; // Returns the events queue

	PriorityQueue<Cargo*>* getVIPCargos() const; // Returns the VIP Priority Queue

	Queue<Cargo*>* getSpecialCargos() const; // Returns the Special Cargos Queue

	LinkedList<Cargo*>* getNormalCargos(); // Returns the Normal Cargos LinkedList
	Queue<Cargo*>* getDeliveredCargos() const; // Returns the Delivered Cargos Queue

	Queue<Truck*>* getNormalTrucks() const; // Returns the ready normal trucks
	Queue<Truck*>* getInCheckupNormalTrucks() const; // Returns the normal trucks in checkup

	Queue<Truck*>* getSpecialTrucks() const; // Returns the ready special trucks
	Queue<Truck*>* getInCheckupSpecialTrucks() const; // Returns the special trucks in checkup

	Queue<Truck*>* getVIPTrucks() const; // Returns the ready VIP trucks
	Queue<Truck*>* getInCheckupVIPTrucks() const; // Returns the VIP trucks in checkup

	Truck** getLoadingTrucks() const; // Returns the Trucks of the 3 Cargo types currently loading
	
	PriorityQueue<Truck*>* getMovingTrucks() const; // Returns the moving trucks priority queue

	bool getSimulationStatus() const; // Returns the simulation status
	void checkEvents(int, int); // Executes the events in their right time

	void handleLoadingRule(int, int); // Loads the Cargos following the loading rule
	void handleVIPLoading(int, int); // Checks if it can load VIP cargos in this hour
	void handleNormalLoading(int, int); // Checks if it can load normal cargos in this hour
	void handleSpecialLoading(int, int); // Checks if it can load special cargos in this hour
	void LoadVIPCargos(); // Loads the VIP cargos following the loading rule
	void LoadNormalCargos(); // Loads the normal cargos following the loading rule
	void LoadSpecialCargos(); // Loads the special cargos following the loading rule

	void moveTrucktoLoading(Truck*, int, int, int); // Moves a truck to the loading state
	void loadingTruckstoMoving(int, int); // Moves a loading truck to moving state
	void moveCargotoDelivered(Cargo*); // Moves a Cargo to the delivered state

	void handleReturningTrucks(int, int); // Moves returning trucks to their right state
	void movingTrucktoCheckUp(Truck* x); // Moves returning trucks to checkup state
	void movingTrucktoReady(Truck* x); // Moved returning trucks to ready state

	void handleInCheckupTrucks(int, int); // Moves trucks who finished checkup to ready state
	void inCheckupVIPToReady(int, int); // Moves in checkup VIP truck to ready state
	void inCheckupNormalToReady(int, int); // Moves in checkup normal truck to ready state
	void inCheckupSpecialToReady(int, int); // Moves in checkup special truck to ready state

	void deliverCargos(int, int); // Deliver cargos in their right time
	void checkMaxWRule(int, int); // Loads cargos after waiting maxW hours
	void checkNormalMaxW(int, int); // Checks if it can load waiting normal cargos in this hour
	void loadWaitingNormalCargos(int, int); // Loads the waiting normal cargos following the maxW rule
	void checkSpecialMaxW(int, int); // Checks if it can load waiting special cargos in this hour
	void loadWaitingSpecialCargos(int, int); // Loads the waiting special cargos following the maxW rule

	void PromoteNormalCargo(Cargo* c); // Promotes a normal cargo to VIP
	void checkAutoPromotion(int, int); // Promotes a normal cargo after waiting autoP days
	bool checkSimulationEnd(); // Checks if the simulation has already ended
	bool writeFile(); // Writes the output file
	void generateStatistics(ofstream&); // Generate the statistics in the output file
	void writeAvgWait(int, int, int, ofstream&); // Calculates the Avg Wait and writes it in the output file
	void writeAutoPromoted(int, int, ofstream&); // Calculates the Auto Promoted % and writes it in the output file
	void writeAvgActiveTime(int, int, ofstream&); // Calculates the Avg active time % and writes it in the output file
	void writeAvgUtilization(float, int, ofstream&); // Calculates the Avg utilization % and writes it in the output file
	~Company(); // The Company Destructor
};

