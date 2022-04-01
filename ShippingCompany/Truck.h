#pragma once

class Truck{

	char type; // Indicates the truck type
	int TC; // Truck Capacity
	int checkupTime; // The truck maintenance (checkup) time
	int speed; // The truck speed
	int DI; // Delivery Interval
public:
	Truck(char, int, int, int, int); // Constructor
	void printTruck() const; // Prints the truck details
	char getType() const; // Returns the truck type
	void setType(char&); // Sets the truck type
	bool belongsTo(char&); // Checks if the truck belongs to a specific type
	int getTC() const; // Returns the truck capacity
	void setTC(int&); // Sets the truck capacity
	int getCheckupTime() const; // Returns the truck maintenance (checkup) time
	void setCheckupTime(int&); // Sets the truck maintenance (checkup) time
	int getSpeed() const; // Returns the truck speed
	void setSpeed(int&); // Sets the truck speed
	int getDI() const; // Returns the delivery interval
	void setDI(int&); // Sets the delivery interval
	//~Truck(); No dynamic allocation so we'll use default destructor
};

