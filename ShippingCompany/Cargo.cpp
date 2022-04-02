#include "Cargo.h"
#include<iostream>
using namespace std;
Time::Time(int h=0, int d=0)
{
	set_time( h, d);
}

void Time::set_H(int h)
{
	if (h > 0)
		hour = h;
	else cout << "Please enter positive number" << endl;
}

void Time::set_D(int d)
{
	if (d > 0)
		day = d;
	else cout << "Please enter positive number" << endl;
}

void Time::set_time(int h, int d)
{
	set_D(d);
	set_H(h);
}

int Time::get_d()
{
	return day;
}

int Time::get_h()
{
	return hour;
}

void Time::print_time()
{
	cout << "the Time is ( " << get_d() << " : " << get_h() << " )" << endl;
}
int Cargo::get_id()
{
	return ID;
}
