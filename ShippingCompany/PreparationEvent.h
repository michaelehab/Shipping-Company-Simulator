#pragma once
#include "Event.h"

class PreparationEvent :
    public Event
{
    //For preparation event
    char Ctype;  //cargo type
    double dist; //cargo distance in km
    int Ld;      //time in hours to load/unload the cargo
    double cost;  //cargo cost
public:
    PreparationEvent();
    PreparationEvent(int id, int day, int hour, char Etype, char ctype, int dist, int ld, double cost,Company * ptr);

    bool Execute();
  
    bool setCtype(char c);		//sets the cargo type
    bool setdist(double d);		//sets the cargo distance
    bool setLd(int l);			//sets the loading/unloading time of the cargo
    bool setcost(double c);  //sets the cargo cost

    char getCtype() const;      //gets the cargo type
    double getdist() const;     //gets the cargo distance
    int getLd() const;			//gets the loading/unloading time of the cargo
    double getcost() const;		//gets the cargo cost
};

