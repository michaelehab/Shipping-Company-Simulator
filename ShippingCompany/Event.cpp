#include "Event.h"

Event::Event()
{

}
Event::Event(int id, int day, int hour, char Etype,Company* ptr)
{
	setID(id);
	setEtype(Etype);
	setEt(day, hour);
	setCompanyptr(ptr);
}
bool Event::setEt(int d, int h)    //sets the event time
{
	if (d > 0 && h > 0 && h < 25)
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
bool Event::setID(int i)			// sets the cargo id
{
	if (id > 0)
	{
		id = i; return 1;
	}
	return 0;
}
void Event::setCompanyptr(Company* ptr)    //sets the company pointer
{
	c = ptr;
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
int Event::getID() const			//gets the cargo id
{
	return id;
}

