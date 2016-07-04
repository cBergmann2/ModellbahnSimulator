///////////////////////////////////////////////////////////
//  LoadingArea.cpp
//  Implementation of the Class LoadingArea
//  Created on:      04-Jul-2016 09:47:36
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "LoadingArea.h"


LoadingArea::LoadingArea(){
	pathSection = new PathSection();
	laodingStations[0] = new LoadingStation();
	laodingStations[1] = new LoadingStation();

	semEmptyPlaces = xSemaphoreCreateCounting(2, 2);

}


LoadingArea::~LoadingArea(){

}



LoadingStation* LoadingArea::getLoadingStation(int id){

	return  laodingStations[id];
}


PathSection* LoadingArea::getPathSection(){

	return  pathSection;
}


TwoWaySwitch* LoadingArea::getSwitch(){

	return  twoWaySwitch;
}


void LoadingArea::occupiePlaceInLoadingArea(){

	xSemaphoreTake(semEmptyPlaces, portMAX_DELAY);
}


void LoadingArea::unblockPlaceInLoadingArea(){
	xSemaphoreGive(semEmptyPlaces);
}

int LoadingArea::getEmptyLoadingStation(){
	if (!laodingStations[0]->occupied){
		return 0;
	}
	else{
		if (!laodingStations[0]->occupied){
			return 1;
		}
		else{
			return -1;
		}
	}
}