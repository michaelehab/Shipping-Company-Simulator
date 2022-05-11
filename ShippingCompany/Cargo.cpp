#include "Cargo.h"
#include<iostream>
using namespace std;
Cargo::Cargo(int id,int prep,int LT,double dis,char carg_T, double cos, int h, int d)
{
	SetCargoT(carg_T);
	set_cost( cos);
	set_LoadTime( LT);
	setDel_dis( dis);
	set_prepTime( prep);
	set_H(h);
	set_D(d);
	setID(id);
	this->autoPromoted = false;
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

void Cargo::setDel_dis(double dis)
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

double Cargo::getDel_dis()
{
	return Del_dis;
}

int Cargo::getPriority() const {
	// Cargos with higher cost have the highest priority
	// Cargos with far delivery distance have less priority
	// Cargos with far preparation time have the least priority
	return (20 * Cost) + (10 * Del_dis) + (4 * day);
}