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
	// Remove the cargo from the linked list and get its pointer
	Cargo* car= list->Remove(this->getID());
	if (car) 
	{
		delete car;	
		return true;
	}
	return false;
}
