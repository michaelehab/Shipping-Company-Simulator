#include "PreparationEvent.h"
bool PreparationEvent::Execute(PreparationEvent* e, LinkedList<Cargo*>* list)
{
	
	list->InsertEnd(CI_Cargo(e));
	return true;
	
}
bool PreparationEvent::Execute(PreparationEvent* e, Queue<Cargo*>* queue)
{
  queue->enqueue(CI_Cargo(e));
 return true;
}
bool PreparationEvent::Execute(PreparationEvent* e, PriorityQueue<Cargo*>* PQ,int p)
{
	PQ->push(CI_Cargo(e),p);
	return true;
}
Cargo* PreparationEvent::CI_Cargo(PreparationEvent* e)
{
	Cargo* ptr = new Cargo();
	ptr->setID(e->getID());
	ptr->SetCargoT(e->getCtype());
	ptr->setDel_dis(e->getdist());
	ptr->set_cost(e->getcost());
	int d, h;
	e->getEt(d, h);
	ptr->set_D(d);
	ptr->set_H(h);
	ptr->set_LoadTime(e->getLd());
	return ptr;

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