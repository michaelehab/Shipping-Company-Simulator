#include "UI.h"
void UI::printWaitingCargos(LinkedList<Cargo*>* n, Queue<Cargo*>* s, PriorityQueue<Cargo*>* vip)
{
	cout << "Waiting Cargos: [";
	n->printList();
	cout << "] (";
	//s->printqueue();
	cout << ") {" ;
	vip->PrintPQ();
	cout << "} " << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
}
void UI::printCheckUpTrucks(Queue<Truck*>* n, Queue<Truck*>* s, Queue<Truck*>* vip)
{
	cout << "In-Checkup Trucks: [";
	/*n->printqueue();
	cout << "] (";
	s->printqueue();
	cout << ") {";
	vip->printqueue();
	cout << "} " << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";*/

}