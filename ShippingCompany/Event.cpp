#include "Event.h"
bool Event::setEt(int d, int h)    //sets the event time
{
	if (d > 0 && h > 4 && h < 24)
	{
		day = d;
		hour = h;
		return 1;
	}
	return 0;
}
bool Event::setEtype(char e)		  //sets the event type
{
	if (e == 'R' || e == 'X' || e == 'P')
	{
		Etype = e; return 1;
	}
	return 0;
}
bool Event::setId(int i)			// sets the cargo id
{
	if (id > 0)
	{
		id = i; return 1;
	}
	return 0;
}
bool Event::setCtype(char c)		//sets the cargo type
{
	if (c == 'N' || c == 'S' || c == 'V')
	{
		Ctype = c; return 1;
	}
	return 0;
}
bool Event::setdist(double d)		//sets the cargo distance
{
	if (d > 0)
	{
		dist = d; return 1;
	}
	return 0;
}
bool Event::setLd(int l)			//sets the loading/unloading time of the cargo
{
	if (l >= 0)
	{
		Ld = l; return 1;
	}
	return 0;
}
bool Event::setcost(double c)  //sets the cargo cost
{
	if (c >= 0)
	{
		cost = c; return 1;

	}
	return 0;
}
bool Event::setEm(double e)		//sets the extra money for promotion
{
	if (e >= 0)
	{
		Em = e; return 1;
	}
	return 0;
}

//Getters
void Event::getEt(int& d, int& h) const //gets the event time
{
	d = day;
	h = hour;
}
char Event::getEtype() const      //gets the event type
{
	return Etype;
}
int Event::getId() const			//gets the cargo id
{
	return id;
}
char Event::getCtype() const     //gets the cargo type
{
	return Ctype;
}
double Event::getdist() const     //gets the cargo distance
{
	return dist;
}
int Event::getLd() const			//gets the loading/unloading time of the cargo
{
	return Ld;
}
double Event::getcost() const		//gets the cargo cost
{
	return cost;
}
double Event::getEm() const		//gets the extra money for promotion
{
	return Em;
}