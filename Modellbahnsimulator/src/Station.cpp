///////////////////////////////////////////////////////////
//  Station.cpp
//  Implementation of the Class Station
//  Created on:      04-Jul-2016 09:47:45
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "Station.h"


Station::Station(){
	occupied = false;
}



Station::~Station(){

}





/**
 * returns value > 0 if function was not successful
 */
int Station::occupieStation(){

	return 0;
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

}