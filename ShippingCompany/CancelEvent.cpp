#include "CancelEvent.h"

CancelEvent::CancelEvent()
{

}
CancelEvent::CancelEvent(int id, int day, int hour, char Etype, Company* ptr)
	:Event(id,day,hour,Etype,ptr)
{

}
bool CancelEvent::Execute()
{
	LinkedList<Cargo*>* list = c->getNormalCargos();
	Cargo* car= list->Remove(this->getID());
	if (car) 
	{
		delete car;	
		return 1;
	}
	return 0;
}
