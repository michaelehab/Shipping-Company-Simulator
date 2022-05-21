#pragma once
#include <iostream>
using namespace std;

class Cargo
{
	int hour;
	int day;
	int Load_Time;
	int Prep_Time;
	double Cost;
	char cargo_type;
	int Del_dis;
	int ID;
	int TID; // Truck ID
	bool autoPromoted;
	// Statistics
	int waitingTime_day;
	int waitingTime_hour;
	int CDT_day;
	int CDT_hour;
public:
	Cargo(int id, int prep, int LT, int dis, char carg_T , double cos , int h , int d );
	Cargo();
	void SetCargoT(char T);
	void set_cost(double c);
	void set_LoadTime(int LT);
	void setDel_dis(int dis);
	void set_prepTime(int preT);
	void set_H(int h);
	void set_D(int d);
	void setCDT(int, int);
	void setTID(int);
	void setAutoPromote(bool);
	int getCDTDay() const;
	int getCDTHour() const;
	char getCargoT();
	double get_cost();
	int  get_LoadTime();
	int getDel_dis();
	void setID(int id);
	int getID();
	int get_d();
	int get_h();
	int getTID() const;
	int getPriority() const;
	void setWaitingTime(int,int);
	void getWaitingTime(int&,int&);
	bool checkAutoPromoted() const;
	bool operator ==(const int&);
	friend ostream& operator << (ostream& out, const Cargo& c);
};

