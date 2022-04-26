#include "PromoteEvent.h"

PromoteEvent::PromoteEvent()
{

}
PromoteEvent::PromoteEvent(int id, int day, int hour, char Etype, double Em, Company* ptr)
	:Event(id,day,hour,Etype,ptr)
{
	
	setEm(Em);
}
bool PromoteEvent::setEm(double e)		//sets the extra money for promotion
{
	if (e >= 0)
	{
		Em = e; return 1;
	}
	return 0;
}

double PromoteEvent::getEm() const		//gets the extra money for promotion
{
	return Em;
}
bool PromoteEvent::Execute()
{
	LinkedList<Cargo*>* list = c->getNormalCargos();
	Cargo* car= list->Remove(this->getID());
	if (car)
	{
		int p = car->getID() + car->get_cost()/ car->getDel_dis(); // to be changed later
		c->getVIPCargos()->push(car,p);
		return 1;
	}
	return 0;
	
}