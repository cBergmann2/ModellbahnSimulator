///////////////////////////////////////////////////////////
//  DischargingArea.cpp
//  Implementation of the Class DischargingArea
//  Created on:      04-Jul-2016 09:47:21
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "DischargingArea.h"

/**************************************************
Function name:		Konstruktor
returns:
argl:				Referenz auf Wartebereich
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Initialisiert die Klassenvariablen und erstellt die Entladestationen
Notes:
**************************************************/
DischargingArea::DischargingArea(WaitingArea *waitingArea)
{
	this->waitingArea = waitingArea;
	this->pathSection = new PathSection();
	this->pSThreeWaySwitch = new PathSection();
	this->semDischargingAreaAndWaitingStation = xSemaphoreCreateCounting(4, 4);			//Init semaphores
	this->semDischargingArea = xSemaphoreCreateCounting(3, 3);
	this->dischargingStations[0] = new DischargingStation(1, this->waitingArea, this);	//Entladestationen erzeugen
	this->dischargingStations[1] = new DischargingStation(2, this->waitingArea, this);
	this->dischargingStations[2] = new DischargingStation(3, this->waitingArea, this);
}



DischargingArea::~DischargingArea(){

}

/**************************************************
Function name:		getDischragingStation
returns:			DischargingStation*
argl:				ID (0,1 oder 2)  der Beladestation
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Liefert eine der Beladestationen
Notes:
**************************************************/
DischargingStation* DischargingArea::getDischragingStation(int ID){

	return  dischargingStations[ID];
}

/**************************************************
Function name:		getThreeWaySwitch
returns:			ThreeWaySwitch*

Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Liefert Referenz auf Drei-Wege-Weiche
Notes:
**************************************************/
ThreeWaySwitch* DischargingArea::getThreeWaySwitch(){

	return  this->threeWaySwitch;
}

/**************************************************
Function name:		getTwoWaySwitch
returns:			TwoWaySwitch*

Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Liefert Referenz auf Zwei-Wege-Weiche
Notes:
**************************************************/
TwoWaySwitch* DischargingArea::getTwoWaySwitch(){

	return  this->twoWaySwitch;
}

/**************************************************
Function name:		occupiePlaceInDischargingArea
returns:			

Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Blockiert einen Platz im Entladebereich
Notes:
**************************************************/
void DischargingArea::occupiePlaceInDischargingArea(){
	xSemaphoreTake(semDischargingArea, portMAX_DELAY);
}

/**************************************************
Function name:		unblockPlaceInDischargingArea
returns:

Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Gibt einen Platz im Entladebereich wieder frei
Notes:
**************************************************/
void DischargingArea::unblockPlaceInDischargingArea(){
	xSemaphoreGive(semDischargingArea);
}

/**************************************************
Function name:		occupiePlaceInDischargingAreaOrWaitingArea
returns:

Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Blockiert einen Platz im Entlade- oder Wartebereich
Notes:
**************************************************/
void DischargingArea::occupiePlaceInDischargingAreaOrWaitingArea(){
	xSemaphoreTake(this->semDischargingAreaAndWaitingStation, portMAX_DELAY);
}

/**************************************************
Function name:		unblockPlaceInDischargingAreaOrWaitingArea
returns:

Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Gibt einen Platz im Entlade- und Wartebreich wieder frei
Notes:
**************************************************/
void DischargingArea::unblockPlaceInDischargingAreaOrWaitingArea(){
	xSemaphoreGive(this->semDischargingAreaAndWaitingStation);
}

/**************************************************
Function name:		occupieThreeWaySwitch
returns:

Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Blockiert die Drei-Wege-Weiche
Notes:
**************************************************/
void DischargingArea::occupieThreeWaySwitch(){

	this->pSThreeWaySwitch->occupiePath();
}

/**************************************************
Function name:		unblockThreeWaySwitch
returns:

Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Gibt die Drei-Wege-Weiche wieder frei
Notes:
**************************************************/
void DischargingArea::unblockThreeWaySwitch(){
	this->pSThreeWaySwitch->releasePath();
}

/**************************************************
Function name:		occupiePathSection
returns:

Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Blockiert den Weg
Notes:
**************************************************/
void DischargingArea::occupiePathSection(){
	this->pathSection->occupiePath();
}

/**************************************************
Function name:		unblockPathSection
returns:

Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		gibt den Weg wieder frei
Notes:
**************************************************/
void DischargingArea::unblockPathSection(){
	this->pathSection->releasePath();
}

/**************************************************
Function name:		getEmptyDischargingStation
returns:

Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		liefert eine Freie Entladestation
Notes:				Diese Funktion liefert nur dann ein gültiges Ergebnis, 
					wenn zuvor die Funktion occupiePlaceInDischargingArea() erfolgreich aufgerufen wurde 
					und unblockPlaceInDischargingArea() noch nicht aufgerufen wurde.
**************************************************/
int DischargingArea::getEmptyDischargingStation(){
	if (!dischargingStations[0]->occupied){
		return 1;
	}
	else{
		if (!dischargingStations[1]->occupied){
			return 2;
		}
		else{
			return 3;
		}
	}
}

