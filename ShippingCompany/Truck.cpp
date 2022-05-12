#include <iostream>
#include "Truck.h"

using namespace std;

Truck::Truck(int id, char t, int tc, int checktime, int s) {
	setID(id);
	setType(t);
	setTC(tc);
	setCheckupTime(checktime);
	setSpeed(s);
	this->activeTime = 0;
}

bool Truck::operator ==(const int& a) {
	return ID == a;
}

ostream& operator << (ostream& out, const Truck& c)
{
	out << c.ID;
	c.printLoadedCargos();
	return out;
}

ostream& operator << (ostream& out, const Truck* c)
{
	out << c->getID();
	c->printLoadedCargos();
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
void Truck::setLoadTime(int d, int h)
{
	load_d = d;
	load_h = h;
}

// Utility 

bool Truck::belongsTo(char& c) {
	return type == c;
}

void Truck::printLoadedCargos() const {
	if (loadedCargos.isEmpty()) return;
	if (type == 'N') {
		cout << '[';
		loadedCargos.PrintPQ();
		cout << ']';
	}
	else if (type == 'V') {
		cout << '{';
		loadedCargos.PrintPQ();
		cout << '}';
	}
	else if (type == 'S') {
		cout << '(';
		loadedCargos.PrintPQ();
		cout << ')';
	}
}

Cargo* Truck::unloadCargo(int d, int h) {
	Cargo* tmp;
	if(loadedCargos.pop(tmp)) return tmp;
	// if(loadedCargos->getSize() == 0) activeTime += (d - load_d) + (h - load_h);
	return 0;
}

void Truck::loadCargo(Cargo * c) {
	// NOTE : priority is CDT ascending to be changed!
	loadedCargos.push(c, c->getPriority());
}
