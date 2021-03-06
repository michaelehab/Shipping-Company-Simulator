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
	// Remove the cargo from the linked list and get its pointer
	Cargo* car= list->Remove(this->getID());
	if (car)
	{
		int p = car->getPriority();
		car->SetCargoT('V');
		// Add to VIP Cargos Priority Queue in Company Class
		c->getVIPCargos()->push(car,p);
		return true;
	}
	return false;
	
}