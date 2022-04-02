#pragma once
// Done by EA
#include<iostream>
#include"Node.h"
using namespace std;

template <class T>
class LinkedQueue {
	
	Node<T>* Fptr;
	Node<T>* Bptr;

public:
	LinkedQueue()
	{
		Fptr = nullptr;
		Bptr = nullptr;
	}
	bool IsEmpty()  const
	{
		if (Fptr == nullptr && Bptr == nullptr)
			return true;
		else return false;
	}
	bool enQueue(const T& nData);
	bool deQueue(T& Fdata);
	bool peek(T& Fdata) const;
	LinkedQueue(const LinkedQueue<T>& LQ);
	~LinkedQueue();

};
template<class T>
bool LinkedQueue<T>:: enQueue(const T& nData)
{
	Node<T>* newNode = new Node<T>;
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
bool LinkedQueue<T>::deQueue(T& Fdata)
{
	Node<T>* currPtr;
	if (IsEmpty())
	{
		cout << "Queue is empty" << endl;
		return false;
	}
	else
	{
		currPtr = Fptr;
		Fdata = currPtr->getItem();
		Fptr = Fptr->getNext();
		delete currPtr;
	}
	return true;
}

template <typename T>
bool LinkedQueue<T>::peek(T& Fdata) const
{
	if (IsEmpty())
		return false;

	Fdata = Fptr->getItem();
	return true;

}
template <class T>
LinkedQueue<T>::~LinkedQueue()
{
	T temp;
	while (deQueue(temp));
}

template <typename T>
LinkedQueue<T>::LinkedQueue(const LinkedQueue<T>& LQ)
{
	Node<T>* NodePtr = LQ.frontPtr;
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
