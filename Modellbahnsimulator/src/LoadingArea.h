///////////////////////////////////////////////////////////
//  LoadingArea.h
//  Implementation of the Class LoadingArea
//  Created on:      04-Jul-2016 09:47:36
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_70556EA6_EF62_402f_BA8C_A6434A014298__INCLUDED_)
#define EA_70556EA6_EF62_402f_BA8C_A6434A014298__INCLUDED_

#include "TwoWaySwitch.h"
#include "LoadingStation.h"
#include "PathSection.h"

class LoadingArea
{
private:
	PathSection *pathSection;
	SemaphoreHandle_t semEmptyPlaces;

public:
	LoadingArea();
	virtual ~LoadingArea();
	TwoWaySwitch *twoWaySwitch;
	LoadingStation* laodingStations[2];
	PathSection *pathToLoadingArea;
	int getEmptyLoadingStation();

	LoadingStation* getLoadingStation(int id);
	PathSection* getPathSection();
	TwoWaySwitch* getSwitch();
	void occupiePlaceInLoadingArea();
	void unblockPlaceInLoadingArea();

};
#endif // !defined(EA_70556EA6_EF62_402f_BA8C_A6434A014298__INCLUDED_)
