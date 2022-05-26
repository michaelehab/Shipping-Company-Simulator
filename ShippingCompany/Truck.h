#pragma once
#include "PriorityQueue.h"
#include "Cargo.h"

class Truck{
	int ID; // The truck ID
	char type; // Indicates the truck type
	int TC; // Truck Capacity
	int checkupTime; // The truck maintenance (checkup) time
	int speed; // The truck speed
	int DI = 0; // Delivery Interval
	int J; // Number of journeys before checkup
	PriorityQueue<Cargo*> loadedCargos; // Queue contains pointers to the loaded cargos
	int totalDeliveredCargos = 0; // The number of cargos delivered by this truck
	int totalJourneys = 0; // The total number of journeys made by this truck

	int load_d; // the day it started loading cargos
	int load_h; // the hour it started loading cargos

	int dep_d; // the day it started its journey
	int dep_h; // the hour it started its journey

	int arrival_d; // the day it gets back to the company
	int arrival_h; // the hour it gets back to the company

	int maxCargoLoad; // The max time a cargo takes to be loaded on the truck
	int activeTime; // Active hours for the truck
	int lastUnloadTime = 0;
	float utilization; // The truck utilization
public:
	Truck(int, char, int, int, int); // Constructor
	void printLoadedCargos() const; // Prints the loaded cargos
	char getType() const; // Returns the truck type
	void setType(char&); // Sets the truck type
	bool belongsTo(char&); // Checks if the truck belongs to a specific type
	int getTC() const; // Returns the truck capacity
	int gettotalJourneys(); // Returns the total journeys made by this truck
	int getJ(); // Returns J
	void setTC(int&); // Sets the truck capacity
	int getCheckupTime() const; // Returns the truck maintenance (checkup) time
	void setCheckupTime(int&); // Sets the truck maintenance (checkup) time
	void setLoadTime(int, int); //sets the loading day and hour
	int getSpeed() const; // Returns the truck speed
	void setSpeed(int&); // Sets the truck speed
	int getDI() const; // Returns the delivery interval
	void setDI(int &, int&); // Sets the delivery interval
	void setID(int&); // Sets the truck ID
	int getID() const; // Returns the truck ID
	int getArrivalTime() const; // Returns the truck arrival time
	void setMaxCargoLoad(int&); // Sets the max load time of the truck
	Cargo* unloadCargo(int d, int h); // Removes a cargo to deliver it 
	Cargo* unloadCargo(); // Dequeues the first cargo and returns a ptr to it
	void loadCargo(Cargo*); // Loads a cargo to the truck
	void calcDepartmentTime(int, int); // Calculates the truck department time
	bool checkDepartmentTime(int, int); // Checks if the given time is the department time
	void calcArrivalTime(int, int); // Calculates the truck arrival time
	bool checkArrivalTime(int, int); // Checks if the given time is the arrival time
	Cargo* checkDelivery(int d, int h); // Checks if there's a Cargo to deliver in the given time
	void incrementJourneys(); // Increase the truck journeys by 1
	int getPriority() const; // Returns the truck priority 
	int getActiveTime() const; // Returns the truck active time
	void calcUtilization(int); // Calculates the truck utilization after simulation
	float getUtilization() const; // Returns the truck uitilization
	bool operator ==(const int&);
	friend ostream& operator << (ostream& out, const Truck& c);
	friend ostream& operator << (ostream& out, const Truck* c);
	//~Truck(); No dynamic allocation so we'll use default destructor
};


