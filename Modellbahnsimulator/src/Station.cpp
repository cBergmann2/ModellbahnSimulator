///////////////////////////////////////////////////////////
//  Station.cpp
//  Implementation of the Class Station
//  Created on:      04-Jul-2016 09:47:45
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "Station.h"


Station::Station(){
	occupied = false;
	semHandle = xSemaphoreCreateCounting(1,1);
}



Station::~Station(){

}





/**
 * returns value > 0 if function was not successful
 */
void Station::occupieStation(){
	xSemaphoreTake(semHandle, portMAX_DELAY);
	this->occupied = true;
}


/**
 * Parameter sensorNumber 0: entry, 1: exit
 */
void Station::presenceSensorTriggered(int sensorNumber){

}


void Station::SetSopActorActive(bool newVal){

	stopActorActive = newVal;
}


void Station::unblockStation(){
	this->occupied = false;
	xSemaphoreGive(semHandle);
}