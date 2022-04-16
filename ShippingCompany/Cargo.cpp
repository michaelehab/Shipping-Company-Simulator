#include "Cargo.h"
#include<iostream>
using namespace std;
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
	
}

void Cargo::set_cost(double c)
{

}

void Cargo::set_LoadTime(int LT)
{

}

void Cargo::setDel_dis(double dis)
{

}

void Cargo::set_prepTime()
{

}

void Cargo::setID(int id)
{

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