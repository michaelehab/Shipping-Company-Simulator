#pragma once
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
	Node<T>* Head;
	Node<T>* Tail;
	int count;
public:
	LinkedList(); // Constructor
	void printList() const; // prints the LinkedList
	void ReadList(); // Reads the LinkedList
	void InsertEnd(const T&); // Inserts an element at the end of the LinkedList
	void InsertBegin(const T&); // Inserts an element at the beginning of the LinkedList
	void DeleteAll(); // Deletes all the LinkedList Nodes
	bool DeleteNode(const T&); // Searches for a node then Deletes it
	bool pop(T&);
	T Remove(const int&); // Removes a specific element and returns it;
	bool Contains(const T&); // Checks whether the LinkedList contains a specific element
	T* GetByposition(const T&); // Gets the element by its position (index)
	T* GetByValue(const T&); // Gets the element by its value
	void PrintLL() const; // Prints the ID of the values in the LinkedList
	bool isEmpty() const;
	int getSize() const;
	~LinkedList(); // Destructor
};

template <typename T>
LinkedList<T>::LinkedList(){
	Head = nullptr;
	Tail = nullptr;
	count = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
	DeleteAll();
}

template <typename T>
void LinkedList<T>::printList() const{
	Node<T>* p = Head;
	while (p){
		cout << *(p->getItem()) << " ";
		p = p->getNext();
	}
	
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
	count++;
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
	count++;
}

template <typename T>
void LinkedList<T>::DeleteAll(){
	Node<T>* ptr = Head;
	while (Head){
		ptr = Head;
		Head = Head->getNext();
		delete ptr;
	}
	count = 0;
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
	count--;
	return true;
}

template <typename T>
T LinkedList<T>::Remove(const int& value) {
	Node<T>* ptr = Head;
	Node<T>* prev = NULL;
	if (ptr != NULL && *(ptr->getItem()) == value) {
		Head = ptr->getNext();
		return ptr->getItem();
	}
	while (ptr != NULL && !(*(ptr->getItem()) == value))
	{
		prev = ptr;
		ptr = ptr->getNext();
	}
	if (ptr == NULL) return 0;
	if (ptr == Tail) Tail = prev;
	prev->setNext(ptr->getNext());
	count--;
	return ptr->getItem();
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

template<typename T>
void LinkedList<T>::PrintLL() const {
	Node<T>* ptr = Head;

	while (ptr){
		cout << *(ptr->getItem());
		if (ptr->getNext()) cout << ", ";
		ptr = ptr->getNext();
	}
}

template<typename T>
bool LinkedList<T>::pop(T& frntEntry)
{

	if (isEmpty())
		return false;

	Node<T>* nodeToDeletePtr = Head;
	frntEntry = Head->getItem();
	Head = Head->getNext();
	if (!Head)
		Tail = NULL;
	// Free memory reserved for the dequeued node
	delete nodeToDeletePtr;
	count--;
	return true;
}
template <typename T>
bool  LinkedList<T>::isEmpty() const
{
	return (Head == nullptr);
}

template <typename T>
int LinkedList<T>::getSize() const {
	return count;
}
