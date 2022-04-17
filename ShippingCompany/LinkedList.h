#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
	Node<T>* Head;
	Node<T>* Tail;
public:
	LinkedList(); // Constructor
	void printList() const; // prints the LinkedList
	void ReadList(); // Reads the LinkedList
	void InsertEnd(const T&); // Inserts an element at the end of the LinkedList
	void InsertBegin(const T&); // Inserts an element at the beginning of the LinkedList
	void DeleteAll(); // Deletes all the LinkedList Nodes
	bool DeleteNode(const T&); // Searches for a node then Deletes it
	bool DeleteNodeOfPtr(Node<T>*, Node<T>*); //Deletes the Node of poiner ptr
	bool Contains(const T&); // Checks whether the LinkedList contains a specific element
	T* GetByposition(const T&); // Gets the element by its position (index)
	T* GetByValue(const T&); // Gets the element by its value
	Node<T>* GetHeadptr() const;
	void PrintLL() const; // Prints the ID of the values in the LinkedList
	~LinkedList(); // Destructor
};

template <typename T>
LinkedList<T>::LinkedList(){
	Head = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	DeleteAll();
}

template <typename T>
void LinkedList<T>::printList() const{
	Node<T>* p = Head;
	while (p){
		cout << p->getItem() << " ";
		p = p->getNext();
	}
	cout << endl;
}

template <typename T>
void LinkedList<T>::ReadList(){
	int n;
	cin >> n;
	while (n != -1){
		this->InsertEnd(n);
		cin >> n;
	}
}

// O(n)
template <typename T>
void LinkedList<T>::InsertEnd(const T& data){
	Node<T>* ptr = new Node<T>(data);
	if (!Head) {
		Head = ptr;
		Tail = ptr;
	}
	else {
		Tail->setNext(ptr);
		Tail = ptr;
	}
}

// O(1)
template <typename T>
void LinkedList<T>::InsertBegin(const T& data){
	Node<T>* ptr = new Node<T>(data);
	if (!Head){
		Head = ptr;
		Tail = ptr;
		return;
	}
	else{
		ptr->setNext(Head);
		Head = ptr;
	}
}

template <typename T>
void LinkedList<T>::DeleteAll(){
	Node<T>* ptr = Head;
	while (Head){
		ptr = Head;
		Head = Head->getNext();
		delete ptr;
	}
}

template <typename T>
bool LinkedList<T>::DeleteNode(const T& value){
	Node<T>* ptr = Head;
	Node<T>* prev = NULL;
	if (ptr != NULL && ptr->getItem() == value){
		Head = ptr->getNext();
		delete ptr;
		return true;
	}
	while (ptr != NULL && ptr->getItem() != value)
	{
		prev = ptr;
		ptr = ptr->getNext();
	}
	if (ptr == NULL) return false;
	if (ptr == Tail) Tail = prev;
	prev->setNext(ptr->getNext());
	delete ptr;
	return true;
}

template <typename T>
bool LinkedList<T>::Contains(const T& value){
	if (Head){
		Node<T>* ptr = Head;
		while (ptr){
			if (ptr->getItem() == value) return true;
			ptr = ptr->getNext();
		}
		return false;
	}
}

template <typename T>
T* LinkedList<T>::GetByposition(const T& pos){
	int i = 0;
	if (Head){
		Node<T>* ptr = Head;
		while (ptr){
			if (i == pos){
				return ptr->getItem();
			}
			++i;
			ptr = ptr->getNext();
		}
	}
}

template <typename T>
T* LinkedList<T>::GetByValue(const T& data) {
	if (Head) {
		Node<T>* ptr = Head;
		while (ptr) {
			if (ptr->getItem() == data) {
				return ptr->getItem();
			}
		}
	}
}
template <typename T>
Node<T>* LinkedList<T>::GetHeadptr() const
{
	return Head;
}
template <typename T>
bool LinkedList<T>::DeleteNodeOfPtr(Node<T>* prev, Node<T>*ptr)
{
	if (prev==NULL && ptr != NULL ) {
		Head = ptr->getNext();
		delete ptr;
		return true;
	}
	else if(prev !=NULL && ptr != NULL)
	{
		prev->setNext(ptr->getNext());
		delete ptr;
		return true;
	}
	return false;
}

template<typename T>
void LinkedList<T>::PrintLL() const {
	Node<T>* ptr = Head;

	while (ptr){
		cout << ptr->getItem()->getID();
		if (ptr->getNext()) cout << " , ";
		ptr = ptr->getNext();
	}
}