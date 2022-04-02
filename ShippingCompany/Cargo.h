#pragma once

class Time
{
	int hour;
	int day;
public:
	Time(int h, int d);
	
	void set_H(int h);
	void set_D(int d);
	void set_time(int h, int d);
	int get_d();
	int get_h();
	void  print_time();
	

};
class Cargo
{
	Time prepr_time;
	int Load_Time;
	double Cost;
	char cargo_type;
	double Del_dis;
	int ID;
public:
	Cargo();
	void SetCargoT(char T);
	void set_cost(double c);
	void set_LoadTime(int LT);
	void setDel_dis(double dis);
	void set_prepTime();
	char getCargoT();
	double get_cost();
	int  get_LoadTime();
	double getDel_dis();
	Time get_prepTime();
	void set_id(int id);
	int get_id();
};

