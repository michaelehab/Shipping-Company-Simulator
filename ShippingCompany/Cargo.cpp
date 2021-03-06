#include "Cargo.h"
#include<iostream>
using namespace std;
Cargo::Cargo(int id,int prep,int LT,int dis,char carg_T, double cos, int h, int d)
{
	SetCargoT(carg_T);
	set_cost(cos);
	set_LoadTime(LT);
	setDel_dis(dis);
	set_prepTime(prep);
	set_H(h);
	set_D(d);
	setID(id);
	autoPromoted = false;
}

bool Cargo::operator ==(const int& a) {
	return ID == a;
}

ostream& operator << (ostream& out, const Cargo& c)
{
	out << c.ID;
	return out;
}

Cargo::Cargo()
{
	autoPromoted = false;
}

void Cargo::set_H(int h)
{
	if (h > 0)
		hour = h;
	else cout << "Please enter positive number" << endl;
}

void Cargo::set_D(int d)
{
	if (d > 0)
		day = d;
	else cout << "Please enter positive number" << endl;
}

void Cargo::setTID(int id) {
	TID = id;
}

void Cargo::setAutoPromote(bool b) {
	autoPromoted = b;
}

int Cargo::get_d()
{
	return day;
}

int Cargo::get_h()
{
	return hour;
}


int Cargo::getID()
{
	return ID;
}

void Cargo::SetCargoT(char T)
{
	cargo_type = T;
}

void Cargo::set_cost(double c)
{
	Cost = (c > 0) ? c : 0;
}

void Cargo::set_LoadTime(int LT)
{
	Load_Time = (LT > 0) ? LT : 0;
}

void Cargo::setDel_dis(int dis)
{
	Del_dis = (dis > 0) ? dis : 0;
}

void Cargo::set_prepTime(int preT)
{
	Prep_Time = preT;
}

void Cargo::setID(int id)
{
	ID = id;
}

void Cargo::setCDT(int d, int h) {
	CDT_day = d;
	CDT_hour = h;
}

char Cargo::getCargoT()
{
	return cargo_type;
}

double Cargo::get_cost()
{
	return Cost;
}

int  Cargo::get_LoadTime()
{
	return Load_Time;
}

int Cargo::getDel_dis()
{
	return Del_dis;
}

int Cargo::getPriority() const {
	// Cargos with higher cost have the highest priority
	// Cargos with far delivery distance have less priority
	// Cargos with far preparation time have the least priority
	return (20 * Cost) + (10 * Del_dis) + (4 * day);
}
void Cargo::setWaitingTime(int d, int hr)
{
	waitingTime_day = d;
	waitingTime_hour = hr;
}
void Cargo::getWaitingTime(int &d, int& hr)
{
	d = waitingTime_day;
	hr = waitingTime_hour;
}

bool Cargo::checkAutoPromoted() const {
	return autoPromoted;
}

int Cargo::getCDTDay() const {
	return CDT_day;
}

int Cargo::getCDTHour() const {
	return CDT_hour;
}

int Cargo::getTID() const {
	return TID;
}