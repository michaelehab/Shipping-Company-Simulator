#include "PreparationEvent.h"


PreparationEvent::PreparationEvent()
{

}
PreparationEvent::PreparationEvent(int id, int day, int hour, char Etype, char ctype, int dist,
	int ld,double cost, Company* ptr):Event(id,day,hour,Etype,ptr)
{
	setCtype(ctype);
	setdist(dist);
	setcost(cost);
	setLd(ld);
}
bool PreparationEvent::Execute()
{
	Cargo* ptr = new Cargo();
	ptr->setID(this->getID());
	ptr->SetCargoT(this->getCtype());
	ptr->setDel_dis(this->getdist());
	ptr->set_cost(this->getcost());
	int d, h;
	this->getEt(d, h);
	ptr->set_D(d);
	ptr->set_H(h);
	ptr->set_LoadTime(this->getLd());

	char k = this->getCtype(); //k is the cargo type
	if (k == 'N')
	{
		c->getNormalCargos()->InsertEnd(ptr);
		return 1;
	}
	else if (k == 'S')
	{
		c->getSpecialCargos()->enqueue(ptr);
		return 1;
	}
	else if (k == 'V')
	{
		int p = ptr->getPriority();
		c->getVIPCargos()->push(ptr, p);
		return 1;
	}
	else return 0;
	
}

bool PreparationEvent::setCtype(char c)		//sets the cargo type
{
	if (c == 'N' || c == 'S' || c == 'V')
	{
		Ctype = c; return 1;
	}
	return 0;
}
bool PreparationEvent::setdist(double d)		//sets the cargo distance
{
	if (d > 0)
	{
		dist = d; return 1;
	}
	return 0;
}
bool PreparationEvent::setLd(int l)			//sets the loading/unloading time of the cargo
{
	if (l >= 0)
	{
		Ld = l; return 1;
	}
	return 0;
}
bool PreparationEvent::setcost(double c)  //sets the cargo cost
{
	if (c >= 0)
	{
		cost = c; return 1;

	}
	return 0;
}
char PreparationEvent::getCtype() const     //gets the cargo type
{
	return Ctype;
}
double PreparationEvent::getdist() const     //gets the cargo distance
{
	return dist;
}
int PreparationEvent::getLd() const			//gets the loading/unloading time of the cargo
{
	return Ld;
}
double PreparationEvent::getcost() const		//gets the cargo cost
{
	return cost;
}