///////////////////////////////////////////////////////////
//  DischargingArea.h
//  Implementation of the Class DischargingArea
//  Created on:      04-Jul-2016 09:47:21
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_8714FDB4_A9FD_466e_BF44_3EC28972B799__INCLUDED_)
#define EA_8714FDB4_A9FD_466e_BF44_3EC28972B799__INCLUDED_

#include "TwoWaySwitch.h"
#include "ThreeWaySwitch.h"
#include "DischargingStation.h"
#include "PathSection.h"

class DischargingArea
{

public:
	DischargingArea();
	virtual ~DischargingArea();
	TwoWaySwitch *twoWaySwitch;
	ThreeWaySwitch *threeWaySwitch;
	DischargingStation *dischargingStations;
	PathSection *pathSection;

	DischargingStation getDischragingStation(int ID);
	ThreeWaySwitch getThreeWaySwitch();
	TwoWaySwitch getTwoWaySwitch();
	void occupiePathSection(int pathSection);
	static void occupiePlaceInDischargingArea();
	static void occupiePlaceInDischargingAreaOrWaitingArea();
	int occupieThreeWaySwitch();
	void unblockPathSection(int section);

private:
	Semaphore semDischargingArea;
	Semaphore semDischargingAreaAndWaitingStation;

};
#endif // !defined(EA_8714FDB4_A9FD_466e_BF44_3EC28972B799__INCLUDED_)
