#include "CancelEvent.h"

CancelEvent::CancelEvent()
{

}
CancelEvent::CancelEvent(int id, int day, int hour, char Etype, Company* ptr)
	:Event(id,day,hour,Etype,ptr)
{

}
bool CancelEvent::Execute(int id, LinkedList<Cargo*>* list)
{
	Node<Cargo*>* prev = NULL;
	Node<Cargo*>* ptr = list->GetHeadptr();
	while (ptr)
	{
		if ((ptr->getItem())->getID() == id)
			return list->DeleteNodeOfPtr(prev, ptr);
		prev = ptr;
		ptr = ptr->getNext();
	}
	return 0;
}
