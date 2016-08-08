///////////////////////////////////////////////////////////
//  Scales.cpp
//  Implementation of the Class Scales
//  Created on:      04-Jul-2016 09:47:39
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "Scales_old.h"

using namespace std;

extern "C" void Scales_old::taskBehavior(void *parms){
	
	Scales_old* scales = (Scales_old*)parms;
	int recBuffer;
	int emptyDischargingStation;
	DischargingStation *ds1, *ds2, *ds3;

	ds1 = scales->dischargingArea->getDischragingStation(1);
	ds2 = scales->dischargingArea->getDischragingStation(2);
	ds3 = scales->dischargingArea->getDischragingStation(3);
	
	cout << "Waage: betriebsbereit" << endl;

	while (true){
		xQueueReceive(scales->getMailbox(), &recBuffer, portMAX_DELAY);
		switch (recBuffer){
		case SCALE_PRESENCE_SENSOR_INCOMING_TO_DISCHARGING_AREA:

			sendTo(SCALE_SCALE_ACTIVITY, 0);								//Wiegevorgang starten
			xQueueReceive(scales->getMailbox(), &recBuffer, portMAX_DELAY);	//Auf Ende des Wiegevorgangs warten

			scales->dischargingArea->occupiePlaceInDischargingArea();		//Eine Entladestation belegen

			scales->dischargingArea->occupieThreeWaySwitch();

			emptyDischargingStation = scales->dischargingArea->getEmptyDischargingStation();

			switch (emptyDischargingStation){
			case DISCHARGE_PLACE_1:
				//ds1->occupieStation();
				sendTo(SWITCH_DISCHARGINGSTATION_1_2, LOAD_PLACE_1);
				break;
			case DISCHARGE_PLACE_2:
				//ds2->occupieStation();
				sendTo(SWITCH_DISCHARGINGSTATION_1_2, 3);
				break;
			case DISCHARGE_PLACE_3:
				//ds3->occupieStation();
				scales->dischargingArea->occupiePathSection();
				sendTo(SWITCH_DISCHARGINGSTATION_1_2, 2);
				sendTo(SWITCH_DISCHARGINGSTATION_3, 1);
				break;
			}

			sendTo(SCALE_PLACE_STOP_ACTOR, DEACTIVATE);										//Stop-Aktor des Startbereichs deaktivieren
			xQueueReceive(scales->getMailbox(), &recBuffer, portMAX_DELAY);					//Darauf warten, dass das Fahrzeug die Waage verl�sst
			if (recBuffer == SCALE_PRESENCE_SENSOR_OUTGOING_TO_DISCHARGING_AREA){
				sendTo(START_PLACE_STOP_ACTOR, ACTIVATE);									//Stop-Aktor der Waage aktivieren
			}


			break;
		case SCALE_PRESENCE_SENSOR_INCOMING_TO_START_AREA:
			break;
		}
	}		
	
}

PathSection* Scales_old::getPathSectionToStartArea(){

	return  this->pathToStartArea;
}


double Scales_old::scalingProcedure(){

	return 0;
}



void Scales_old::setMailbox(QueueHandle_t mailbox){
	this->mailbox = mailbox;
}

QueueHandle_t Scales_old::getMailbox(){
	return this->mailbox;
}