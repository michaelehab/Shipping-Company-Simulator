#pragma once
#include "Node.h"
using namespace std;

template <typename T>
class PriorityQueue 
{
private:

	Node<T>* frontPtr;
	int priority;
	int count;
public:
	PriorityQueue();
	bool isEmpty() const;
	bool push(const T& entry, int p);
	bool pop(T& frntEntry);
	bool peek(T& frntEntry)  const;
	void PrintPQ() const;  //only to test the PriorityQueue. To be moved later. 
	int getSize() const;
	~PriorityQueue();

};


template <typename T>
PriorityQueue<T>::PriorityQueue()
{
	frontPtr = nullptr;
	count = 0;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return (count == 0);
}


template <typename T>
bool PriorityQueue<T>::push(const T& newEntry, int p) //p stands for priority
{

	Node<T>* start = frontPtr;

	// Create new Node
	Node<T>* temp = new Node<T>(newEntry, p);
	if (!frontPtr)
	{
		frontPtr = temp;
		frontPtr->setNext(nullptr);
	}
	else if (frontPtr->getPriority() <= p)
	{

		// Insert New Node before head
		temp->setNext(frontPtr);
		frontPtr = temp;
	}
	else
	{

		// Traverse the list and find a
		// position to insert new node
		while (start->getNext() != NULL &&
			start->getNext()->getPriority() > p)
		{
			start = start->getNext();
		}

		// Either at the ends of the list
		// or at required position
		temp->setNext( start->getNext());
		start->setNext(temp);
		
	}
	count++;
	return true;
}

template <typename T>
bool PriorityQueue<T>::pop(T& frntEntry)
{
	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = frontPtr;
	frntEntry = frontPtr->getItem();
	frontPtr = frontPtr->getNext();
	// Queue is not empty; remove front
	

	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;
	count--;
	return true;

}

template <typename T>
bool PriorityQueue<T>::peek(T& frntEntry) const
{
	if (isEmpty())
		return false;

	frntEntry = frontPtr->getItem();
	return true;

}

template <typename T>
PriorityQueue<T>::~PriorityQueue()
{
	T temp;

	//Free (Dequeue) all nodes in the queue
	while (pop(temp));
}



template <typename T>
void PriorityQueue<T>::PrintPQ()	const
{
	Node<T>* p = frontPtr;

	while (p)
	{
		cout <<  *(p->getItem());
		if (p->getNext()) cout << ", ";
		p = p->getNext();
	}
	
}

template<typename T>
int PriorityQueue<T>::getSize() const {
	return count;
}