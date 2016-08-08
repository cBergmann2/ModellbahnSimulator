///////////////////////////////////////////////////////////
//  DischargingArea.cpp
//  Implementation of the Class DischargingArea
//  Created on:      04-Jul-2016 09:47:21
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "DischargingArea.h"


DischargingArea::DischargingArea(WaitingArea *waitingArea)
{
	this->waitingArea = waitingArea;
	this->dischargingStations[0] = new DischargingStation(1, this->waitingArea, this);
	//this->dischargingStations[0]->setWaitingArea(this->waitingArea);
	this->dischargingStations[1] = new DischargingStation(2, this->waitingArea, this);
	//this->dischargingStations[1]->setWaitingArea(this->waitingArea);
	this->dischargingStations[2] = new DischargingStation(3, this->waitingArea, this);
	//this->dischargingStations[2]->setWaitingArea(this->waitingArea);
}


DischargingArea::DischargingArea()
{
	//this->dischargingStations[0] = new DischargingStation();
	//this->dischargingStations[0]->setWaitingArea(this->waitingArea);
	//this->dischargingStations[1] = new DischargingStation();
	//this->dischargingStations[1]->setWaitingArea(this->waitingArea);
	//this->dischargingStations[2] = new DischargingStation();
	//this->dischargingStations[2]->setWaitingArea(this->waitingArea);
}

DischargingArea::~DischargingArea(){

}


DischargingStation* DischargingArea::getDischragingStation(int ID){

	return  dischargingStations[ID];
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


void DischargingArea::unblockPathSection(){

}

void DischargingArea::unblockThreeWaySwitch(){

}

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

