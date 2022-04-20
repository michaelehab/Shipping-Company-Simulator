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

ostream& operator << (ostream& out, const Truck& c)
{
	out << c.ID;
	return out;
}

ostream& operator << (ostream& out, const Truck* c)
{
	out << c->getID();
	return out;
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
	cout << getID();
	if (type == 'N') {
		cout << '[';
		loadedCargos.print();
		cout << ']';
	}
	else if (type == 'V') {
		cout << '{';
		loadedCargos.print();
		cout << '}';
	}
	else if (type == 'S') {
		cout << '(';
		loadedCargos.print();
		cout << ')';
	}
}

Cargo* Truck::unloadCargo() {
	Cargo* tmp;
	if(loadedCargos.dequeue(tmp)) return tmp;
	return 0;
}

void Truck::loadCargo(Cargo * c) {
	loadedCargos.enqueue(c);
}
