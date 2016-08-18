///////////////////////////////////////////////////////////
//  LoadingStation.cpp
//  Implementation of the Class LoadingStation
//  Created on:      04-Jul-2016 09:47:37
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "LoadingStation.h"

using namespace std;



/**************************************************
Function name: taskBehavior
returns: void
argl: Parameter enthält Instanz der Beladestation
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Funktion beschreibt das zyklische Verhalten einer Beladestation
**************************************************/
extern "C" void LoadingStation::taskBehavior(void *parms){
	
	LoadingStation *ls = (LoadingStation*)parms;
	int recBuffer;

	cout << "LoadingStation_" << ls->GetID() << ": betriebsbereit" << endl;

	while (true){
		xQueueReceive(ls->getMailbox(), &recBuffer, portMAX_DELAY);
		if (recBuffer == LOAD_PLACE_1_PRESENCE_SENSOR_INCOMING ||
			recBuffer == LOAD_PLACE_2_PRESENCE_SENSOR_INCOMING){

			ls->getPathToLoadingStations()->releasePath();		//Streckenabschnitt zu Beladestationen, inklusive Weiche, freigeben
			//cout << "LoadingStation_" << ls->GetID() << ": Streckenabschnitt zur Bleadestation freigegeben" << endl;

			ls->loadingProcedure();								//Beladevorgang ausführen

			ls->getDischargingArea()->occupiePlaceInDischargingAreaOrWaitingArea();	//Station im Entladebereich reservieren
			ls->getScales()->occupieStation();										//Waage reservieren

			vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) + 1);	//kritischer Programmabschnitt -> Priorität erhöhen
			switch (ls->GetID()){
			case 1:
				sendTo(LOAD_PLACE_1_STOP_ACTOR, DEACTIVATE);	//StopActor deaktivieren

				xQueueReceive(ls->mailbox, &recBuffer, portMAX_DELAY);	//Auf Signal der Anlage warten, dass Fahrzeug die Station verlassen hat
				if (recBuffer == LOAD_PLACE_1_PRESENCE_SENSOR_OUTGOING){
					sendTo(LOAD_PLACE_1_STOP_ACTOR, ACTIVATE); //StopActor aktivieren
					ls->unblockStation();	//Station freigeben
					//cout << "LoadingStation_1: unblock station" << endl;
				}
				break;
			case 2:
				sendTo(LOAD_PLACE_2_STOP_ACTOR, DEACTIVATE);	//StopActor deaktivieren

				xQueueReceive(ls->mailbox, &recBuffer, portMAX_DELAY);	//Auf Signal der Anlage warten, dass Fahrzeug die Station verlassen hat
				if (recBuffer == LOAD_PLACE_2_PRESENCE_SENSOR_OUTGOING){
					sendTo(LOAD_PLACE_2_STOP_ACTOR, ACTIVATE); //StopActor aktivieren
					ls->unblockStation();	//Station freigeben
					//cout << "LoadingStation_2: unblock station" << endl;
				}
				break;
			}
			vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) - 1);	//kritischer Programmabschnitt vorbei -> Priorität heruntersetzen
			ls->loadingArea->unblockPlaceInLoadingArea();	//Platz im Beladebereich freigeben
		}
	}
	
}

void LoadingStation::loadingProcedure(){
	int recBuffer;
	
	switch (this->ID){
	case 1:
		sendTo(LOAD_PLACE_1_LOADING_ACTIVITY, 0);		//Beladevorgang starten

		xQueueReceive(this->mailbox, &recBuffer, portMAX_DELAY);	//Auf Ende des Beladevorgangs warten
		break;
	case 2:
		sendTo(LOAD_PLACE_2_LOADING_ACTIVITY, 0);		//Beladevorgang starten

		xQueueReceive(this->mailbox, &recBuffer, portMAX_DELAY);	//Auf Ende des Beladevorgangs warten
		break;
	}
}

int LoadingStation::GetID(){

	return ID;
}

void LoadingStation::SetID(int newVal){

	ID = newVal;
}


/**************************************************
Function name: setMailbox(QueueHandle_t )
returns: void
argl: Mailbox zur Kommunikation mit Haupt-Threaed
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Speichert die Mailbox-Variable als Instanzvariable im Objekt
**************************************************/
void LoadingStation::setMailbox(QueueHandle_t mailbox){
	this->mailbox = mailbox;
}

/**************************************************
Function name: getMailbox()
returns: QueueHandle_t
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Liefert die Mailbox dieser Instanz
**************************************************/
QueueHandle_t LoadingStation::getMailbox(){
	return this->mailbox;
}


/**************************************************
Function name: setPathToLoadingStations(PathSection*)
returns: void
argl: Path-Objekt das zu den Beladestationen führt
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Speichert das Path-Objekt das zu den Beladestationen führt
**************************************************/
void LoadingStation::setPathToLoadingStations(PathSection *path){
	this->pathToLoadingStations = path;
}


/**************************************************
Function name: getPathToLoadingStations()
returns: PathSection*
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Liefert das Path-Objekt das zu den Beladestationen führt
**************************************************/
PathSection* LoadingStation::getPathToLoadingStations(){
	return this->pathToLoadingStations;
}


/**************************************************
Function name: setPathToScales(PathSection*)
returns: void
argl: Path-Objekt das zu der Waage führt
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Speichert das Path-Objekt das zu der Waage führt
**************************************************/
void LoadingStation::setPathToScales(PathSection* path){
	this->pathToScales = path;
}

/**************************************************
Function name: getPathToScales()
returns: PathSection*
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Liefert das Path-Objekt das zu der Waage führt
**************************************************/
PathSection* LoadingStation::getPathToScales(){
	return this->pathToScales;
}


/**************************************************
Function name: setDischargingArea(DischargingArea*)
returns: void
argl: Objekt, das den Entladebereich repräsentier
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Speichert das Objekt, das den Entladebereich repräsentier
**************************************************/
void LoadingStation::setDischargingArea(DischargingArea* dischargingArea){
	this->dischargingArea = dischargingArea;
}

/**************************************************
Function name: getDischargingArea()
returns: DischargingArea*
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Liefert das Objekt, das den Entladebereich repräsentier
**************************************************/
DischargingArea* LoadingStation::getDischargingArea(){
	return this->dischargingArea;
}


/**************************************************
Function name: setScales(Scales*)
returns: void
argl: Objekt, das die Waage repräsentier
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Speichert das Objekt, das die Waage repräsentier
**************************************************/
void LoadingStation::setScales(Scales* scales){
	this->scales = scales;
}

/**************************************************
Function name: getScales()
returns: Scales*
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Liefert das Objekt, das die Waage repräsentier
**************************************************/
Scales* LoadingStation::getScales(){
	return this->scales;
}

/**************************************************
Function name: setLoadingArea(LoadingArea*)
returns: void
argl: Objekt, das den Beladebereich repräsentier
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Speichert das Objekt, das den Beladebereich repräsentier
**************************************************/
void LoadingStation::setLoadingArea(LoadingArea* loadingArea){
	this->loadingArea = loadingArea;
}

/**************************************************
Function name: getLoadingArea()
returns: LoadingArea*
Created by: Christoph Bergmann
Date created: 22.07.2016
Description: Liefert das Objekt, das den Beladebereich repräsentier
**************************************************/
LoadingArea* LoadingStation::getLoadingArea(){
	return this->loadingArea;
}
