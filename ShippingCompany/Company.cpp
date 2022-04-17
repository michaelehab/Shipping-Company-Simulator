#include "Company.h"

void Company::loadFile() {
	ifstream inputFile("Input.txt", ios::in);
	inputFile >> numOfNormalTrucks;
	inputFile >> numOfSpecialTrucks;
	inputFile >> numOfVIPTrucks;

	inputFile >> speedOfNormalTrucks;
	inputFile >> speedOfSpecialTrucks;
	inputFile >> speedOfVIPTrucks;

	inputFile >> capOfNormalTrucks;
	inputFile >> capOfSpecialTrucks;
	inputFile >> capOfVIPTrucks;

	inputFile >> J;
	inputFile >> normalCheckupDuration;
	inputFile >> specialCheckupDuration;
	inputFile >> VIPCheckupDuration;

	for (int i = 0; i < numOfNormalTrucks; i++) {
		Truck* loadedTruck = new Truck(i + 1, 'N', capOfNormalTrucks, normalCheckupDuration, speedOfNormalTrucks);
		NormalTrucks->enqueue(loadedTruck);
	}

	for (int i = 0; i < numOfSpecialTrucks; i++) {
		Truck* loadedTruck = new Truck(i + 1, 'S', capOfSpecialTrucks, specialCheckupDuration, speedOfSpecialTrucks);
		SpecialTrucks->enqueue(loadedTruck);
	}

	for (int i = 0; i < numOfVIPTrucks; i++) {
		Truck* loadedTruck = new Truck(i + 1, 'V', capOfVIPTrucks, VIPCheckupDuration, speedOfVIPTrucks);
		VIPTrucks->enqueue(loadedTruck);
	}

	inputFile >> autoP;
	inputFile >> maxW;

	/*inputFile >> numOfEvents;
	for (int i = 0; i < numOfEvents; i++) {
		char eventType;
		inputFile >> eventType;
		if (eventType == 'R') {
			char type;
			double dist, cost;
			int lt, id;
			string ET, d, h;
			inputFile >> type >> ET >> id >> dist >> lt >> cost;

			// Converting the Day:Hour string to two separated int variables

			int j = 0;
			while (ET[j] != ':') {
				d += ET[j];
			}

			j++;
			while (j < ET.length()) {
				h += ET[j];
			}

			int day = stoi(d), hour = stoi(h);

			Event* tmp = new PreparationEvent(i + 1, day, hour, eventType, type, dist, lt, cost);
			Events->enqueue(tmp);
		}
		else if (eventType == 'X') {
			int id;
			string ET, d, h;

			inputFile >> ET >> id;

			int j = 0;
			while (ET[j] != ':') {
				d += ET[j];
			}

			j++;
			while (j < ET.length()) {
				h += ET[j];
			}

			int day = stoi(d), hour = stoi(h);
			Event* tmp = new CancelEvent(id, day, hour, eventType);
			Events->enqueue(tmp);
		}
		else if (eventType == 'P') {
			int id;
			double extramoney;
			string ET, d, h;

			inputFile >> ET >> id >> extramoney;

			int j = 0;
			while (ET[j] != ':') {
				d += ET[j];
			}

			j++;
			while (j < ET.length()) {
				h += ET[j];
			}

			int day = stoi(d), hour = stoi(h);
			Event* tmp = new PromoteEvent(id, day, hour, eventType, extramoney);
			Events->enqueue(tmp);
		}
	}*/
}
