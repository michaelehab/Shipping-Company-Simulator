#pragma once
#include "Company.h"
class Event
{
	//General
	int day;
	int hour;
	char Etype;  //event type
	int id;      // cargo id
	
protected:
	Company* c; // a pointer to class company
public:
	Event();
	Event(int id, int day, int hour, char Etype,Company* ptr);

	virtual bool Execute()=0;   //executes the event in the derived classes

	//Setters
	bool setEt(int d, int h);     //sets the event time
	bool setEtype(char e);		  //sets the event type
	bool setID(int i);			// sets the cargo id
	void setCompanyptr(Company* ptr);      //sets the company pointer

	//Getters
	void getEt(int& d, int& h) const; //gets the event time (d, h)
	int getDay() const; // gets the event day
	int getHour() const; // gets the event hour
	char getEtype() const;      //gets the event type
	int getID() const;			//gets the cargo id
	


};

