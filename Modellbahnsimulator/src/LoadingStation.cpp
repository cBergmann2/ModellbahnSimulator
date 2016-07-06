///////////////////////////////////////////////////////////
//  LoadingStation.cpp
//  Implementation of the Class LoadingStation
//  Created on:      04-Jul-2016 09:47:37
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "LoadingStation.h"

using namespace std;




extern "C" void LoadingStation::taskBehavior(void *parms){
	LoadingStation *ls = (LoadingStation*)parms;
	int recBuffer;

	cout << "LoadingStation_" << ls->GetID() << ": betriebsbereit" << endl;

	while (true){
		xQueueReceive(ls->getMailbox(), &recBuffer, portMAX_DELAY);
		if (recBuffer == LOAD_PLACE_1_PRESENCE_SENSOR_INCOMING ||
			recBuffer == LOAD_PLACE_2_PRESENCE_SENSOR_INCOMING){

			ls->getPathToLoadingStations()->releasePath();		//Streckenabschnitt zu Beladestationen, inklusive Weiche, freigeben
			cout << "LoadingStation_" << ls->GetID() << ": Streckenabschnitt zur Bleadestation freigegeben" << endl;

			ls->loadingProcedure();								//Beladevorgang ausführen

			ls->getDischargingArea()->occupiePlaceInDischargingAreaOrWaitingArea();	//Station im Entladebereich reservieren
			ls->getScales()->occupieStation();										//Waage reservieren

			
			switch (ls->GetID()){
			case 1:
				sendTo(LOAD_PLACE_1_LOADING_ACTIVITY, 0);		//Beladevorgang starten

				xQueueReceive(ls->mailbox, &recBuffer, portMAX_DELAY);	//Auf Ende des Beladevorgangs warten

				sendTo(LOAD_PLACE_1_STOP_ACTOR, DEACTIVATE);	//StopActor deaktivieren

				xQueueReceive(ls->mailbox, &recBuffer, portMAX_DELAY);	//Auf Signal der Anlage warten, dass Fahrzeug die Station verlassen hat
				if (recBuffer == LOAD_PLACE_1_PRESENCE_SENSOR_OUTGOING){
					sendTo(LOAD_PLACE_1_STOP_ACTOR, ACTIVATE); //StopActor aktivieren
					ls->unblockStation();	//Station freigeben
					cout << "LoadingStation_1: unblock station" << endl;
				}
				break;
			case 2:
				sendTo(LOAD_PLACE_2_STOP_ACTOR, DEACTIVATE);	//StopActor deaktivieren

				xQueueReceive(ls->mailbox, &recBuffer, portMAX_DELAY);	//Auf Signal der Anlage warten, dass Fahrzeug die Station verlassen hat
				if (recBuffer == LOAD_PLACE_2_PRESENCE_SENSOR_OUTGOING){
					sendTo(LOAD_PLACE_2_STOP_ACTOR, ACTIVATE); //StopActor aktivieren
					ls->unblockStation();	//Station freigeben
					cout << "LoadingStation_2: unblock station" << endl;
				}
				break;
			}

			ls->loadingArea->unblockPlaceInLoadingArea();	//Platz im Beladebereich freigeben
		}
	}
}

void LoadingStation::loadingProcedure(){

}

int LoadingStation::GetID(){

	return ID;
}

void LoadingStation::SetID(int newVal){

	ID = newVal;
}

void LoadingStation::setMailbox(QueueHandle_t mailbox){
	this->mailbox = mailbox;
}

QueueHandle_t LoadingStation::getMailbox(){
	return this->mailbox;
}

void LoadingStation::setPathToLoadingStations(PathSection *path){
	this->pathToLoadingStations = path;
}

PathSection* LoadingStation::getPathToLoadingStations(){
	return this->pathToLoadingStations;
}

void LoadingStation::setPathToScales(PathSection* path){
	this->pathToScales = path;
}

PathSection* LoadingStation::getPathToScales(){
	return this->pathToScales;
}

void LoadingStation::setDischargingArea(DischargingArea* dischargingArea){
	this->dischargingArea = dischargingArea;
}

DischargingArea* LoadingStation::getDischargingArea(){
	return this->dischargingArea;
}

void LoadingStation::setScales(Scales* scales){
	this->scales = scales;
}

Scales* LoadingStation::getScales(){
	return this->scales;
}


void LoadingStation::setLoadingArea(LoadingArea* loadingArea){
	this->loadingArea = loadingArea;
}

LoadingArea* LoadingStation::getLoadingArea(){
	return this->loadingArea;
}
