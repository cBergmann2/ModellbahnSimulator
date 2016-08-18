///////////////////////////////////////////////////////////
//  LoadingArea.h
//  Implementation of the Class LoadingArea
//  Created on:      04-Jul-2016 09:47:36
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#ifndef EA_70556EA6_EF62_402f_BA8C_A6434A014298__INCLUDED_
#define EA_70556EA6_EF62_402f_BA8C_A6434A014298__INCLUDED_

#include "TwoWaySwitch.h"
#include "PathSection.h"
#include "LoadingStation.h"

class LoadingStation;
class LoadingArea
{
private:
	PathSection *pathSection;
	SemaphoreHandle_t semEmptyPlaces;
	TwoWaySwitch *twoWaySwitch;
	LoadingStation* laodingStations[2];
	PathSection *pathToLoadingArea;

public:
	LoadingArea();
	virtual ~LoadingArea();
	int getEmptyLoadingStation();

	LoadingStation* getLoadingStation(int id);
	PathSection* getPathSection();
	TwoWaySwitch* getSwitch();
	void occupiePlaceInLoadingArea();
	void unblockPlaceInLoadingArea();

};
#endif // !defined(EA_70556EA6_EF62_402f_BA8C_A6434A014298__INCLUDED_)
