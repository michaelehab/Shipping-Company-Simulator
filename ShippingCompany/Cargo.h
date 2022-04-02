#pragma once

class Cargo
{
	
	int hour;
	int day;
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
	void set_H(int h);
	void set_D(int d);
	char getCargoT();
	double get_cost();
	int  get_LoadTime();
	double getDel_dis();
	void set_id(int id);
	int get_id();
	int get_d();
	int get_h();
};

