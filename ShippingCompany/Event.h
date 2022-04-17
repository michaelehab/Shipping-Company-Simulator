#pragma once
class Event
{
	//General
	int day;
	int hour;
	char Etype;  //event type
	int id;      // cargo id
	
public:

	virtual bool Execute() =0;   //executes the event in the derived classes

	//Setters
	bool setEt(int d, int h);     //sets the event time
	bool setEtype(char e);		  //sets the event type
	bool setID(int i);			// sets the cargo id

	//Getters
	void getEt(int& d, int& h) const; //gets the event time
	char getEtype() const;      //gets the event type
	int getID() const;			//gets the cargo id
	


};

