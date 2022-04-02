
#pragma once
template < typename T>
class Node
{
private:
	T item; // A data item
	Node<T>* next; // Pointer to next node
	int priority; //for priority queues only and it will be set to -1 by default
public:
	Node();
	Node(const T& r_Item,int pr=-1);
	Node(const T& r_Item, Node<T>* nextNodePtr,int pr=-1);
	void setPriority(int pr);
	void setItem(const T& r_Item);
	void setNext(Node<T>* nextNodePtr);
	T& getItem();
	Node<T>* getNext() const;
	int getPriority() const;
}; // end Node


template < typename T>
Node<T>::Node()
{
	next = nullptr;
	priority = -1;
}

template < typename T>
Node<T>::Node(const T& r_Item,int pr)//pr stands for priority
{
	item = r_Item;
	next = nullptr;
	priority = pr;
}

template < typename T>
Node<T>::Node(const T& r_Item, Node<T>* nextNodePtr,int pr)
{
	item = r_Item;
	next = nextNodePtr;
	priority = pr;
}
template < typename T>
void Node<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
}
template < typename T>
void Node<T>::setPriority(int pr)
{
	priority = pr;
}

template < typename T>
T& Node<T>::getItem()
{
	return item;
}

template < typename T>
Node<T>* Node<T>::getNext() const
{
	return next;
}

template < typename T>
int Node<T>::getPriority() const
{
	return priority;
}
