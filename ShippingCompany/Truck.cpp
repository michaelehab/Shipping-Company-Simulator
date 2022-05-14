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

int Truck::gettotalJourneys()
{
	return totalJourneys;
}

int Truck::getJ()
{
	return J;
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

int Truck::getArrivalTime() const {
	return arrival_d * 24 + arrival_h;
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

void Truck::setDI(double& maxDeliveryDist, int& sumUnloadTime) {
	// Assuming that the truck takes the same time to come back.
	DI = 2 * (maxDeliveryDist / speed) + sumUnloadTime;
}

void Truck::setID(int& id) {
	ID = id;
}
void Truck::setLoadTime(int d, int h)
{
	load_d = d;
	load_h = h;
}

void Truck::setMaxCargoLoad(int& time) {
	maxCargoLoad = time;
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
	loadedCargos.push(c, 1);
}

void Truck::calcDepartmentTime(int d, int h) {
	dep_d = load_d;
	dep_h = load_h;
	dep_h += maxCargoLoad;
	while (dep_h >= 24) {
		dep_h -= 24;
		dep_d++;
	}
}

void Truck::calcArrivalTime(int d, int h) {
	arrival_d = dep_d;
	arrival_h = dep_h;
	arrival_h += getDI();
	while (arrival_h >= 24) {
		arrival_h -= 24;
		arrival_d++;
	}
}

bool Truck::checkDepartmentTime(int d, int h) {
	return (d >= dep_d && h >= dep_h);
}

bool Truck::checkArrivalTime(int d, int h) {
	return (d >= arrival_d && h >= arrival_h);
}

void Truck::incrementJourneys() {
	this->totalJourneys++;
}