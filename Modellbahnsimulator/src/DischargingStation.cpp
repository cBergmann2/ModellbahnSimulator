///////////////////////////////////////////////////////////
//  DischargingStation.cpp
//  Implementation of the Class DischargingStation
//  Created on:      04-Jul-2016 09:47:34
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "DischargingStation.h"

using namespace std;

DischargingStation::DischargingStation(){
	
}

DischargingStation::DischargingStation(int id, WaitingArea *waitingArea, DischargingArea *dischargingArea){
	this->ID = id;
	this->waitingArea = waitingArea;
	this->dischargingArea = dischargingArea;
}

DischargingStation::~DischargingStation(){

}




extern "C" void DischargingStation::taskBehavior(void *parms){
	DischargingStation *ds = (DischargingStation*)parms;
	int recBuffer;
	
	
	while (true){
		
		xQueueReceive(ds->getMailbox(), &recBuffer, portMAX_DELAY);	//Wait for vehicle

		switch (ds->ID){											//Blockierte Streckensegmente Freigeben
		case 1:
		case 2:
			ds->dischargingArea->unblockThreeWaySwitch();
			break;
		case 3:
			ds->dischargingArea->unblockThreeWaySwitch();
			ds->dischargingArea->unblockPathSection();
			break;
		}

		ds->dischargingProcedure();

		ds->getWaitingArea()->occupieStation();

		switch (ds->ID){									//Benötigte Streckensegmenete blockieren
		case 1:
		case 2:
			ds->dischargingArea->occupiePathSection();
			break;
		case 3:												//Nothing to do
			break;
		}

		switch(ds->ID){										//Stop-Actor der Station Aus- und wieder Einschalten
		case 1:
			sendTo(DISCHARGE_PLACE_1_STOP_ACTOR, DEACTIVATE);	//StopActor deaktivieren

			xQueueReceive(ds->mailbox, &recBuffer, portMAX_DELAY);	//Auf Signal der Anlage warten, dass Fahrzeug die Station verlassen hat
			if (recBuffer == DISCHARGE_PLACE_1_PRESENCE_SENSOR_OUTGOING){
				sendTo(DISCHARGE_PLACE_1_STOP_ACTOR, ACTIVATE); //StopActor aktivieren
				ds->unblockStation();	//Station freigeben
				cout << "DischargeingStation_1: unblock station" << endl;
			}
			break;
		case 2:
			sendTo(DISCHARGE_PLACE_2_STOP_ACTOR, DEACTIVATE);	//StopActor deaktivieren

			xQueueReceive(ds->mailbox, &recBuffer, portMAX_DELAY);	//Auf Signal der Anlage warten, dass Fahrzeug die Station verlassen hat
			if (recBuffer == DISCHARGE_PLACE_2_PRESENCE_SENSOR_OUTGOING){
				sendTo(DISCHARGE_PLACE_2_STOP_ACTOR, ACTIVATE); //StopActor aktivieren
				ds->unblockStation();	//Station freigeben
				cout << "DischargeingStation_2: unblock station" << endl;
			}
			break;
		case 3:
			sendTo(DISCHARGE_PLACE_3_STOP_ACTOR, DEACTIVATE);	//StopActor deaktivieren

			xQueueReceive(ds->mailbox, &recBuffer, portMAX_DELAY);	//Auf Signal der Anlage warten, dass Fahrzeug die Station verlassen hat
			if (recBuffer == DISCHARGE_PLACE_3_PRESENCE_SENSOR_OUTGOING){
				sendTo(DISCHARGE_PLACE_3_STOP_ACTOR, ACTIVATE); //StopActor aktivieren
				ds->unblockStation();	//Station freigeben
				cout << "DischargeingStation_3: unblock station" << endl;
			}
			break;
		}
	}

	
}


void DischargingStation::setWaitingArea(WaitingArea *waitingArea){
	this->waitingArea = waitingArea;
}

WaitingArea* DischargingStation::getWaitingArea(){
	return this->waitingArea;
}



void DischargingStation::dischargingProcedure(){
	int recBuffer;
	
	switch (ID){
	case 1:
		sendTo(DISCHARGE_PLACE_1_DISCHARGING_ACTIVITY, 0);		//Entladevorgang starten
		xQueueReceive(mailbox, &recBuffer, portMAX_DELAY);		//Auf Ende des Beladevorgangs warten
		break;

	case 2:
		sendTo(DISCHARGE_PLACE_2_DISCHARGING_ACTIVITY, 0);		//Entladevorgang starten
		xQueueReceive(mailbox, &recBuffer, portMAX_DELAY);		//Auf Ende des Beladevorgangs warten
		break;

	case 3:
		sendTo(DISCHARGE_PLACE_3_DISCHARGING_ACTIVITY, 0);		//Entladevorgang starten
		xQueueReceive(mailbox, &recBuffer, portMAX_DELAY);		//Auf Ende des Beladevorgangs warten
		break;
	}
}

void DischargingStation::setDischargingArea(DischargingArea* dischargingArea){
	this->dischargingArea = dischargingArea;
}

DischargingArea* DischargingStation::getDischargingArea(){
	return this->dischargingArea;
}


void DischargingStation::setMailbox(QueueHandle_t mailbox){
	this->mailbox = mailbox;
}

QueueHandle_t DischargingStation::getMailbox(){
	return this->mailbox;
}
