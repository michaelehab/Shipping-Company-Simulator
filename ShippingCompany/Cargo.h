#pragma once

class Cargo
{
	int hour;
	int day;
	int Load_Time;
	int Prep_Time;
	double Cost;
	char cargo_type;
	double Del_dis;
	int ID;
public:
	Cargo(int id, int prep, int LT, double dis, char carg_T , double cos , int h , int d );
	Cargo();
	void SetCargoT(char T);
	void set_cost(double c);
	void set_LoadTime(int LT);
	void setDel_dis(double dis);
	void set_prepTime(int preT);
	void set_H(int h);
	void set_D(int d);
	char getCargoT();
	double get_cost();
	int  get_LoadTime();
	double getDel_dis();
	void setID(int id);
	int getID();
	int get_d();
	int get_h();
};

