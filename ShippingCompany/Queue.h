#pragma once
// Done by EA
#include <iostream>
#include "Node.h"
using namespace std;

template <class T>
class Queue {
	
	Node<T>* Fptr;
	Node<T>* Bptr;

public:
	Queue()
	{
		Fptr = nullptr;
		Bptr = nullptr;
	}
	bool IsEmpty()  const
	{
		if (!this->Fptr) return true;
		else return false;
	}
	bool enqueue(const T& nData);
	bool dequeue(T& Fdata);
	bool peek(T& Fdata) const;
	void print() const;
	Queue(const Queue<T>& LQ);
	~Queue();

};
template<class T>
bool Queue<T>:: enqueue(const T& nData)
{
	Node<T>* newNode = new Node<T>(nData);
	if (IsEmpty())
	{
		Fptr = newNode;
		Bptr = newNode;
	}
	else
	{
		Bptr->setNext(newNode);
		newNode->setNext(nullptr);
		Bptr = newNode;
	}
	return true;
}
template<class T>
bool Queue<T>::dequeue(T& Fdata)
{
	
	if (IsEmpty())
	{
		return false;
	}
		Node<T>* oldHead = Fptr;
		T oldData = oldHead->getItem();
		Fptr = Fptr->getNext();
		
		delete oldHead;
	
	return true;
}

template <typename T>
bool Queue<T>::peek(T& Fdata) const
{
	if (IsEmpty())
		return false;

	Fdata = Fptr->getItem();
	return true;

}
template <class T>
Queue<T>::~Queue()
{
	T temp;
	while (dequeue(temp));
}
template <class T>
void Queue<T>::print() const
{
	Node<T>* temp = Fptr;
	if (IsEmpty())
	{
		cout << "IS empty" << endl;
		return;
	}
	cout << *(temp->getItem());
	temp = temp->getNext();
	while (temp)
	{
		cout << " , " << *(temp->getItem());

	while (temp) {
		cout << (temp->getItem());
		if (temp->getNext()) cout << " , ";
		temp = temp->getNext();
	}
}
template <typename T>
Queue<T>::Queue(const Queue<T>& LQ)
{
	Node<T>* NodePtr = LQ.Fptr;
	if (!NodePtr) //LQ is empty
	{
		Fptr = Bptr = nullptr;
		return;
	}

	//insert the first node
	Node<T>* ptr = new Node<T>(NodePtr->getItem());
	Fptr = Bptr = ptr;
	NodePtr = NodePtr->getNext();

	//insert remaining nodes
	while (NodePtr)
	{
		Node<T>* ptr = new Node<T>(NodePtr->getItem());
		Bptr->setNext(ptr);
		Bptr = ptr;
		NodePtr = NodePtr->getNext();
	}
}
