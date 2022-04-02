#include <iostream>
#include "PriorityQueue.h"
#include "LinkedList.h"
#include "Truck.h"
#include "Event.h"
#include "Cargo.h"
using namespace std;

int main() {
	//For testing PriorityQueue
	/*PriorityQueue<int> q;
	cout<< q.isEmpty()<<endl;
	q.push(5, 10);
	q.push(20, 2);
	q.push(25, 15);
	q.push(30, 6);
	q.push(40, 2);
	q.push(6, 50);
	q.PrintPriorityQueue();
	cout << q.isEmpty() << endl;
	int x;
	q.peek(x);
	cout <<"Front element is " << x << endl;
	q.pop(x);
	q.pop(x);
	q.pop(x);
	q.pop(x);
	q.pop(x);
	q.PrintPriorityQueue();
	q.pop(x);
	q.pop(x);
	q.PrintPriorityQueue();*/

	// Testing LinkedList Class
	/*LinkedList<int> tmp;
	tmp.ReadList();
	tmp.printList();
	tmp.InsertBegin(5);
	tmp.printList();
	tmp.InsertEnd(10);
	tmp.printList();
	tmp.DeleteNode(5);
	tmp.printList();
	tmp.DeleteNode(10);
	tmp.printList();
	tmp.InsertEnd(99);
	tmp.printList();
	tmp.DeleteAll();
	tmp.InsertBegin(11);
	tmp.printList();
	cout << tmp.Contains(11) << ' ' << tmp.Contains(10) << endl;*/
	// Testing Truck Class
	/*Truck t('Z', 1, -2, 3, 4);
	t.printTruck();*/
	
	return 0;
}