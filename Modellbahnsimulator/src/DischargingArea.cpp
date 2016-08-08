///////////////////////////////////////////////////////////
//  DischargingArea.cpp
//  Implementation of the Class DischargingArea
//  Created on:      04-Jul-2016 09:47:21
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "DischargingArea.h"


DischargingArea::DischargingArea(){

}



DischargingArea::~DischargingArea(){

}


DischargingStation* DischargingArea::getDischragingStation(int ID){

	return  &dischargingStations[ID];
}


ThreeWaySwitch* DischargingArea::getThreeWaySwitch(){

	return  this->threeWaySwitch;
}


TwoWaySwitch* DischargingArea::getTwoWaySwitch(){

	return  this->twoWaySwitch;
}


void DischargingArea::occupiePathSection(){

}


void DischargingArea::occupiePlaceInDischargingArea(){

}


void DischargingArea::occupiePlaceInDischargingAreaOrWaitingArea(){

}


int DischargingArea::occupieThreeWaySwitch(){

	return 0;
}


void DischargingArea::unblockPathSection(int section){

}

int DischargingArea::getEmptyDischargingStation(){
	if (!dischargingStations[0].occupied){
		return 1;
	}
	else{
		if (!dischargingStations[1].occupied){
			return 2;
		}
		else{
			return 3;
		}
	}
}