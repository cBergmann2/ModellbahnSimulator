///////////////////////////////////////////////////////////
//  LoadingArea.cpp
//  Implementation of the Class LoadingArea
//  Created on:      04-Jul-2016 09:47:36
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "LoadingArea.h"


LoadingArea::LoadingArea(){
	pathSection = new PathSection();
}


LoadingArea::~LoadingArea(){

}



LoadingStation LoadingArea::getLoadingStation(int id){

	return  laodingStations[id];
}


PathSection* LoadingArea::getPathSection(){

	return  pathSection;
}


TwoWaySwitch* LoadingArea::getSwitch(){

	return  twoWaySwitch;
}


int LoadingArea::occupiePlaceInLoadingArea(){

	return 0;
}


void LoadingArea::unblockPlaceInLoadingArea(){

}