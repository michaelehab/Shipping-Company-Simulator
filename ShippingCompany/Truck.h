#pragma once
#include <iostream>
using namespace std;
#include "PriorityQueue.h"
#include "Cargo.h"

class Truck{
	int ID;
	char type; // Indicates the truck type
	int TC; // Truck Capacity
	int checkupTime; // The truck maintenance (checkup) time
	int speed; // The truck speed
	int DI = 0; // Delivery Interval
	int J; // Number of journeys before checkup
	PriorityQueue<Cargo*> loadedCargos; // Queue contains pointers to the loaded cargos
	int totalDeliveredCargos = 0; // NOTE : increment if checkDelivery returns a cargo
	int totalJourneys = 0;
	// Start point of active time
	int load_d; // the day it started loading cargos
	int load_h; // the hour it started loading cargos
	int maxCargoLoad; // The max time a cargo takes to be loaded on the truck
	int activeTime;
public:
	Truck(int, char, int, int, int); // Constructor
	void printLoadedCargos() const; // Prints the loaded cargos
	char getType() const; // Returns the truck type
	void setType(char&); // Sets the truck type
	bool belongsTo(char&); // Checks if the truck belongs to a specific type
	int getTC() const; // Returns the truck capacity
	void setTC(int&); // Sets the truck capacity
	int getCheckupTime() const; // Returns the truck maintenance (checkup) time
	void setCheckupTime(int&); // Sets the truck maintenance (checkup) time
	void setLoadTime(int, int); //sets the loading day and hour
	int getSpeed() const; // Returns the truck speed
	void setSpeed(int&); // Sets the truck speed
	int getDI() const; // Returns the delivery interval
	void setDI(int&); // Sets the delivery interval
	void setID(int&); // Sets the truck ID
	int getID() const; // Returns the truck ID
	void setMaxCargoLoad(int&); // Sets the max load time of the truck
	Cargo* unloadCargo(int d, int h); // Dequeues the first cargo and returns a ptr to it
	void loadCargo(Cargo*); // Loads a cargo to the truck
	bool operator ==(const int&);
	friend ostream& operator << (ostream& out, const Truck& c);
	friend ostream& operator << (ostream& out, const Truck* c);
	bool checkDepartmentTime(int d, int h);
	//~Truck(); No dynamic allocation so we'll use default destructor
};


