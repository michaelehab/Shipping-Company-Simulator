#include <iostream>
#include "PriorityQueue.h"
#include "LinkedList.h"
#include "Truck.h"
#include "Event.h"
#include "Cargo.h"
#include "Company.h"
using namespace std;

int main() {
	//
	////For testing PriorityQueue
	///*PriorityQueue<int> q;
	//cout<< q.isEmpty()<<endl;
	//q.push(5, 10);
	//q.push(20, 2);
	//q.push(25, 15);
	//q.push(30, 6);
	//q.push(40, 2);
	//q.push(6, 50);
	//q.PrintPQ();
	//cout << endl<<q.isEmpty() << endl;
	//int x;
	//q.peek(x);
	//cout <<"Front element is " << x << endl;
	//q.pop(x);
	//q.pop(x);
	//q.pop(x);
	//q.pop(x);
	//q.pop(x);
	//q.PrintPQ();
	//q.pop(x);
	//q.pop(x);
	//q.PrintPQ();
	//cout << endl;*/
	// //Testing LinkedList Class
	///*LinkedList<int> tmp;
	//tmp.ReadList();
	//tmp.printList();
	//tmp.InsertBegin(5);
	//tmp.printList();
	//tmp.InsertEnd(10);
	//tmp.printList();
	//tmp.DeleteNode(5);
	//tmp.printList();
	//tmp.DeleteNode(10);
	//tmp.printList();
	//tmp.InsertEnd(99);
	//tmp.printList();
	//tmp.DeleteAll();
	//tmp.InsertBegin(11);
	//tmp.printList();
	//cout << tmp.Contains(11) << ' ' << tmp.Contains(10) << endl;*/

	//// Testing Truck Class and Print function of Data Structures
	/*Truck t(2, 'Z', 1, -2, 4);
	cout << t;*/
	//Truck* k = new Truck(8, 'Z', 1, -2, 4);
	////t->printTruck();
	////Testing PrintPriorityQueue function on Truck object
	////PriorityQueue<Truck*> p;
	////p.push(t,5);
	////p.push(k, 9);
	////p.PrintPQ();
	////Truck* m;
	////p.pop(m);
	////cout << endl;
	////p.PrintPQ();
	////cout << endl;
	////m->printTruck();

	//// Testing PrintLL Function on Trucks (Until Cargo class is fully ready)
	//LinkedList <Truck*> ll;
	//ll.InsertBegin(t);
	//ll.InsertEnd(k);
	//ll.PrintLL();
	//
	/*int x;
	Queue <int >car;
	car.enqueue(10);
	car.dequeue(x);
	car.enqueue(10);
	car.enqueue(10);
	car.enqueue(10);
	car.enqueue(10);
	car.print();*/
	//Company c;
	return 0;
}