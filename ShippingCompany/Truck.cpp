#include <iostream>
#include "Truck.h"

using namespace std;

Truck::Truck(int id, char t, int tc, int checktime, int s) {
	setID(id);
	setType(t);
	setTC(tc);
	setCheckupTime(checktime);
	setSpeed(s);
}
bool Truck::operator ==(const int& a) {
	return ID == a;
}


// Getters

char Truck::getType() const {
	return type;
}

int Truck::getTC() const {
	return TC;
}

int Truck::getCheckupTime() const {
	return checkupTime;
}

int Truck::getSpeed() const {
	return speed;
}

int Truck::getDI() const {
	return DI;
}

int Truck::getID() const {
	return ID;
}

// Setters

void Truck::setType(char& c) {
	if (c == 'V' || c == 'S' || c == 'N') {
		type = c;
	}
	else {
		type = 'N';
	}
}

void Truck::setTC(int& n) {
	TC = (n >= 0) ? n : 0;
}

void Truck::setCheckupTime(int& n) {
	checkupTime = (n >= 0) ? n : 0;
}

void Truck::setSpeed(int& n) {
	speed = (n >= 0) ? n : 0;
}

void Truck::setDI(int& n) {
	DI = (n >= 0) ? n : 0;
}

void Truck::setID(int& id) {
	ID = id;
}

// Utility 

bool Truck::belongsTo(char& c) {
	return type == c;
}

void Truck::printTruck() const {
	cout << "Truck :\n";
	cout << "ID : " << getID() << '\n';
	cout << "Type : " << getType() << '\n';
	cout << "TC : " << getTC() << '\n';
	cout << "Checkup Time : " << getCheckupTime() << '\n';
	cout << "Speed : " << getSpeed() << '\n';
	cout << "DI : " << getDI() << '\n';
}

Cargo* Truck::unloadCargo() {
	Cargo* tmp;
	if(loadedCargos.dequeue(tmp)) return tmp;
	return 0;
}
