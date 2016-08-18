#include "Scales.h"

using namespace std;

/**************************************************
Function name:		taskBehavior
returns:			void
argl:				Parameter enthält Instanz der Waage
Created by:			Christoph Bergmann
Date created:		22.07.2016
Description:		Funktion beschreibt das zyklische Verhalten der Waage
**************************************************/
extern "C" void Scales::taskBehavior(void *parms)
{
	Scales* scales = (Scales*)parms;
	int recBuffer;
	int emptyDischargingStation;
	DischargingStation *ds1, *ds2, *ds3;

	ds1 = scales->dischargingArea->getDischragingStation(0);
	ds2 = scales->dischargingArea->getDischragingStation(1);
	ds3 = scales->dischargingArea->getDischragingStation(2);

	cout << "Waage: betriebsbereit" << endl;

	while (true){
		xQueueReceive(scales->mailbox, &recBuffer, portMAX_DELAY);
		switch (recBuffer){
		case SCALE_PRESENCE_SENSOR_INCOMING_TO_DISCHARGING_AREA:				//Fahrzeug kommt von Beladestation

			sendTo(SCALE_SCALE_ACTIVITY, 0);									//Wiegevorgang starten
			xQueueReceive(scales->mailbox, &recBuffer, portMAX_DELAY);			//Auf Ende des Wiegevorgangs warten

			scales->dischargingArea->occupiePlaceInDischargingArea();			//Eine Entladestation belegen

			scales->dischargingArea->occupieThreeWaySwitch();

			emptyDischargingStation = scales->dischargingArea->getEmptyDischargingStation();

			switch (emptyDischargingStation){
			case DISCHARGE_PLACE_1:
				ds1->occupieStation();
				sendTo(SWITCH_DISCHARGINGSTATION_1_2, LOAD_PLACE_1);
				break;
			case DISCHARGE_PLACE_2:
				ds2->occupieStation();
				sendTo(SWITCH_DISCHARGINGSTATION_1_2, 3);
				break;
			case DISCHARGE_PLACE_3:
				ds3->occupieStation();
				scales->dischargingArea->occupiePathSection();
				sendTo(SWITCH_DISCHARGINGSTATION_1_2, 2);
				sendTo(SWITCH_DISCHARGINGSTATION_3, 1);
				break;
			}

			vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) + 1);					//kritischer Programmabschnitt -> Priorität erhöhen

			sendTo(SCALE_PLACE_STOP_ACTOR, DEACTIVATE);								//Stop-Aktor des Startbereichs deaktivieren
			xQueueReceive(scales->mailbox, &recBuffer, portMAX_DELAY);				//Darauf warten, dass das Fahrzeug die Waage verlässt
			if (recBuffer == SCALE_PRESENCE_SENSOR_OUTGOING_TO_DISCHARGING_AREA){
				sendTo(SCALE_PLACE_STOP_ACTOR, ACTIVATE);							//Stop-Aktor der Waage aktivieren
			}

			vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) - 1);					//kritischer Programmabschnitt vorbei -> Priorität heruntersetzen

			scales->unblockStation();

			break;
		case SCALE_PRESENCE_SENSOR_INCOMING_TO_START_AREA:							//Fahrzeug kommt vom Entladebreich

			scales->dischargingArea->unblockPlaceInDischargingAreaOrWaitingArea();

			sendTo(SCALE_SCALE_ACTIVITY, 0);										//Wiegevorgang starten
			xQueueReceive(scales->mailbox, &recBuffer, portMAX_DELAY);				//Auf Ende des Wiegevorgangs warten

			vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) + 1);					//kritischer Programmabschnitt -> Priorität erhöhen

			sendTo(SCALE_PLACE_STOP_ACTOR, DEACTIVATE);								//Stop-Aktor des Startbereichs deaktivieren
			xQueueReceive(scales->mailbox, &recBuffer, portMAX_DELAY);				//Darauf warten, dass das Fahrzeug die Waage verlässt
			if (recBuffer == SCALE_PRESENCE_SENSOR_OUTGOING_TO_START_AREA){
				sendTo(SCALE_PLACE_STOP_ACTOR, ACTIVATE);							//Stop-Aktor der Waage aktivieren
			}

			vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) - 1);					//kritischer Programmabschnitt vorbei -> Priorität heruntersetzen

			scales->unblockStation();

			break;
		}
	}
}

Scales::Scales()
{
}


Scales::~Scales()
{
}

/**************************************************
Function name:		setMailbox
returns:			void
argl:				Mailbox über die kommuniziert wird
Created by:			Christoph Bergmann
Date created:		22.07.2016
Description:		Setzt die Mailbox
**************************************************/
void Scales::setMailbox(QueueHandle_t mailbox){
	this->mailbox = mailbox;
}

void Scales::setCommunicationSim(xQueueHandle handle){
	this->xQHandle = handle;
}

/**************************************************
Function name:		setDischargingArea
returns:			void
argl:				Referenz auf Entladebereich
Created by:			Christoph Bergmann
Date created:		22.07.2016
Description:		Setzt die Refereuz auf den Entladebereich
**************************************************/
void Scales::setDischargingArea(DischargingArea *dischargingArea){
	this->dischargingArea = dischargingArea;
}