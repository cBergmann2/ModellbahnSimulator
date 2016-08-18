///////////////////////////////////////////////////////////
//  Station.cpp
//  Implementation of the Class Station
//  Created on:      04-Jul-2016 09:47:45
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "Station.h"

/**************************************************
Function name:	Konstruktor
returns:		void
Created by:		Christoph Bergmann
Date created:	22.07.2016
Description:	Funktion initialisiert Varibalen
**************************************************/
Station::Station(){
	occupied = false;
	semHandle = xSemaphoreCreateCounting(1,1);
}

Station::~Station(){

}


/**************************************************
Function name:	occupieStation
returns:		void
Created by:		Christoph Bergmann
Date created:	22.07.2016
Description:	Belegt die Station
**************************************************/
void Station::occupieStation(){
	xSemaphoreTake(semHandle, portMAX_DELAY);
	this->occupied = true;
}

/**************************************************
Function name:	unblockStation
returns:		void
Created by:		Christoph Bergmann
Date created:	22.07.2016
Description:	Gibt die Station wieder frei
**************************************************/
void Station::unblockStation(){
	this->occupied = false;
	xSemaphoreGive(semHandle);
}