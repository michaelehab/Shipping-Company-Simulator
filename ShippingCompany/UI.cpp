#include "UI.h"
UI::UI(Company* comp)
{
	c = comp;
}
void UI::printWaitingCargos()
{
	cout << "Waiting Cargos: [";
	c->getNormalCargos()->printList();
	cout << "] (";
	/*c->getSpecialCargos()->printqueue();*/
	cout << ") {" ;
	c->getVIPCargos()->PrintPQ();
	cout << "} " << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";
}
void UI::printCheckUpTrucks()
{
	cout << "In-Checkup Trucks: [";
	/*c->getInCheckupNormalTrucks()->printqueue();
	cout << "] (";
	c->getInCheckupSpecialTrucks()->printqueue();
	cout << ") {";
	c->getInCheckupVIPTrucks()->printqueue();
	cout << "} " << endl;
	for (int i = 0; i < 50; i++)
		cout << "-";*/

}