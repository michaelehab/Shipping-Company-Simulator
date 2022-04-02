#include "CancelEvent.h"
bool CancelEvent::Execute(int id, LinkedList<Cargo>& list)
{
	Node<Cargo>* prev = NULL;
	Node<Cargo>* ptr = list.GetHeadptr();
	while (ptr)
	{
		if ((ptr->getItem()).get_id() == id)
			return list.DeleteNodeOfPtr(prev, ptr);
		prev = ptr;
		ptr = ptr->getNext();
	}
	return 0;
}
