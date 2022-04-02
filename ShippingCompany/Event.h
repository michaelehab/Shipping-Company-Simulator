#pragma once
class Event
{
	//General
	int day;
	int hour;
	char Etype;  //event type
	int id;      // cargo id
	
	//For preparation event
	char Ctype;  //cargo type
	double dist; //cargo distance in km
	int Ld;      //time in hours to load/unload the cargo
	double cost;  //cargo cost

	//For promotion event
	double Em;   //extra money for promotion
public:

	virtual bool Execute() { return 1; };   //executes the event in the derived classes

	//Setters
	bool setEt(int d, int h);     //sets the event time
	bool setEtype(char e);		  //sets the event type
	bool setId(int i);			// sets the cargo id
	bool setCtype(char c);		//sets the cargo type
	bool setdist(double d);		//sets the cargo distance
	bool setLd(int l);			//sets the loading/unloading time of the cargo
	bool setcost(double c);  //sets the cargo cost
	bool setEm(double e);		//sets the extra money for promotion

	//Getters
	void getEt(int& d, int& h) const; //gets the event time
	char getEtype() const;      //gets the event type
	int getId() const;			//gets the cargo id
	char getCtype() const;      //gets the cargo type
	double getdist() const;     //gets the cargo distance
	int getLd() const;			//gets the loading/unloading time of the cargo
	double getcost() const;		//gets the cargo cost
	double getEm() const;		//gets the extra money for promotion


};

