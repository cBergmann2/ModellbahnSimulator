///////////////////////////////////////////////////////////
//  DischargingStation.cpp
//  Implementation of the Class DischargingStation
//  Created on:      04-Jul-2016 09:47:34
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "DischargingStation.h"

using namespace std;

/**************************************************
Function name:		Konstruktor
returns:			
argl:				ID der Entladestation
arg2:				Zeiger auf Wartebereich-Objekt, das im System genuzt wird
arg3:				Zeiger auf Verwaltungsstruktur für die Entladestationen
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Initialisiert die Klassenvariablen
Notes:				
**************************************************/
DischargingStation::DischargingStation(int id, WaitingArea *waitingArea, DischargingArea *dischargingArea){
	this->ID = id;
	this->waitingArea = waitingArea;
	this->dischargingArea = dischargingArea;
}

DischargingStation::~DischargingStation(){

}



/**************************************************
Function name:		taskBehavior
returns:
argl:				Referenz auf Entladestation, die durch diese Task gesteuert werden soll
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Beschreibt das Verhalten einer Entladestation. Diese Funktion ist als eigenständige Task auszuführen
Notes:
**************************************************/
extern "C" void DischargingStation::taskBehavior(void *parms){
	DischargingStation *ds = (DischargingStation*)parms;
	int recBuffer;
	
	
	while (true){
		
		xQueueReceive(ds->getMailbox(), &recBuffer, portMAX_DELAY);	//Wait for vehicle
		//cout << "DischargingStation " << ds->ID << ": Wagen angekommen" << endl;

		switch (ds->ID){											//Blockierte Streckensegmente Freigeben
		case 1:
		case 2:
			ds->dischargingArea->unblockThreeWaySwitch();
			//cout << "DischargingStation " << ds->ID << ": 3-Wege-Weiche freigegeben" << endl;
			break;
		case 3:
			ds->dischargingArea->unblockThreeWaySwitch();
			//cout << "DischargingStation " << ds->ID << ": 3-Wege-Weiche freigegeben" << endl;
			ds->dischargingArea->unblockPathSection();
			//cout << "DischargingStation " << ds->ID << ": Streckenabschnitt freigegeben" << endl;
			break;
		}

		ds->dischargingProcedure();

		ds->getWaitingArea()->occupieStation();
		//cout << "DischargingStation " << ds->ID << ": Wartebreich blockiert" << endl;

		switch (ds->ID){									//Benötigte Streckensegmenete blockieren
		case 1:
		case 2:
			ds->dischargingArea->occupiePathSection();
			//cout << "DischargingStation " << ds->ID << ": Streckenabschnitt blockiert" << endl;
			sendTo(SWITCH_DISCHARGINGSTATION_3, 2);
			break;
		case 3:												//Nothing to do
			ds->dischargingArea->occupiePathSection();
			//cout << "DischargingStation " << ds->ID << ": Streckenabschnitt blockiert" << endl;	//Muss akutell auch hier gemacht werden, da ansonsten ein Fehler bei SemGive im Wartebreich entsteht.
			break;
		}

		vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) + 1);	//kritischer Programmabschnitt -> Priorität erhöhen

		switch(ds->ID){											//Stop-Actor der Station Aus- und wieder Einschalten
		case 1:
			
			
			sendTo(DISCHARGE_PLACE_1_STOP_ACTOR, DEACTIVATE);	//StopActor deaktivieren

			xQueueReceive(ds->mailbox, &recBuffer, portMAX_DELAY);	//Auf Signal der Anlage warten, dass Fahrzeug die Station verlassen hat
			if (recBuffer == DISCHARGE_PLACE_1_PRESENCE_SENSOR_OUTGOING){
				sendTo(DISCHARGE_PLACE_1_STOP_ACTOR, ACTIVATE);		//StopActor aktivieren
				ds->unblockStation();								//Station freigeben
				//cout << "DischargeingStation_1: unblock station" << endl;
			}
			

			break;
		case 2:
			sendTo(DISCHARGE_PLACE_2_STOP_ACTOR, DEACTIVATE);	//StopActor deaktivieren

			xQueueReceive(ds->mailbox, &recBuffer, portMAX_DELAY);	//Auf Signal der Anlage warten, dass Fahrzeug die Station verlassen hat
			if (recBuffer == DISCHARGE_PLACE_2_PRESENCE_SENSOR_OUTGOING){
				sendTo(DISCHARGE_PLACE_2_STOP_ACTOR, ACTIVATE); //StopActor aktivieren
				ds->unblockStation();	//Station freigeben
				//cout << "DischargeingStation_2: unblock station" << endl;
			}
			break;
		case 3:
			sendTo(DISCHARGE_PLACE_3_STOP_ACTOR, DEACTIVATE);	//StopActor deaktivieren

			xQueueReceive(ds->mailbox, &recBuffer, portMAX_DELAY);	//Auf Signal der Anlage warten, dass Fahrzeug die Station verlassen hat
			if (recBuffer == DISCHARGE_PLACE_3_PRESENCE_SENSOR_OUTGOING){
				sendTo(DISCHARGE_PLACE_3_STOP_ACTOR, ACTIVATE); //StopActor aktivieren
				ds->unblockStation();	//Station freigeben
				//cout << "DischargeingStation_3: unblock station" << endl;
			}
			break;
		}
		vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) - 1);	//kritischer Programmabschnitt vorbei -> Priorität heruntersetzen
	}

	
}

/**************************************************
Function name:		setWaitingArea
returns:
argl:				Referenz auf genutztes Wartebreich-Objekt
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		
Notes:
**************************************************/
void DischargingStation::setWaitingArea(WaitingArea *waitingArea){
	this->waitingArea = waitingArea;
}

/**************************************************
Function name:		getWaitingArea
returns:			WaitingArea*
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Liefert Referenz auf Wartebereichs-Objekt
Notes:
**************************************************/
WaitingArea* DischargingStation::getWaitingArea(){
	return this->waitingArea;
}


/**************************************************
Function name:		dischargingProcedure
returns:
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Führt den Entlade-Prozess aus
Notes:
**************************************************/
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

/**************************************************
Function name:		setDischargingArea
returns:
argl:				Referenz auf Verwaltungsstruktur für Entladestationen
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:
Notes:
**************************************************/
void DischargingStation::setDischargingArea(DischargingArea* dischargingArea){
	this->dischargingArea = dischargingArea;
}

/**************************************************
Function name:		getDischargingArea
returns:			DischargingArea*
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Liefert Referenz auf Verwaltungsstruktur für Entladestationen
Notes:
**************************************************/
DischargingArea* DischargingStation::getDischargingArea(){
	return this->dischargingArea;
}

/**************************************************
Function name:		setMailbox
returns:
argl:				Mailbox über die die Management-Task mit dieser Task kommuniziert
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:
Notes:
**************************************************/
void DischargingStation::setMailbox(QueueHandle_t mailbox){
	this->mailbox = mailbox;
}

/**************************************************
Function name:		getMailbox
returns:			QueueHandle_t*
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Liefert die Mailbox über die die Management-Task mit dieser Task kommuniziert
Notes:
**************************************************/
QueueHandle_t DischargingStation::getMailbox(){
	return this->mailbox;
}
