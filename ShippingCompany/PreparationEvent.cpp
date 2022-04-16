#include "PreparationEvent.h"
bool PreparationEvent::Execute(Event* e, LinkedList<Cargo*>* list)
{
	
	list->InsertEnd(CI_Cargo(e));
	return true;
	
}
bool PreparationEvent::Execute(Event* e, Queue<Cargo*>* queue)
{
  queue->enqueue(CI_Cargo(e));
 return true;
}
bool PreparationEvent::Execute(Event* e, PriorityQueue<Cargo*>* PQ,int p)
{
	PQ->push(CI_Cargo(e),p);
	return true;
}
Cargo* PreparationEvent::CI_Cargo(Event* e)
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