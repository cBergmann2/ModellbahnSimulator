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
#include "WaitingArea.h"

class DischargingStation;
class DischargingArea
{
private:
	SemaphoreHandle_t semDischargingArea;
	SemaphoreHandle_t semDischargingAreaAndWaitingStation;
	WaitingArea *waitingArea;

public:
	DischargingArea(WaitingArea *waitingArea);
	DischargingArea();
	virtual ~DischargingArea();
	TwoWaySwitch *twoWaySwitch;
	ThreeWaySwitch *threeWaySwitch;
	DischargingStation* dischargingStations[3];
	PathSection *pathSection;

	DischargingStation* getDischragingStation(int ID);
	ThreeWaySwitch* getThreeWaySwitch();
	TwoWaySwitch* getTwoWaySwitch();
	static void occupiePlaceInDischargingArea();
	void unblockPlaceInDischargingArea();
	static void occupiePlaceInDischargingAreaOrWaitingArea();
	void unblockPlaceInDischargingAreaOrWaitingArea();
	int occupieThreeWaySwitch();
	void unblockThreeWaySwitch();
	void occupiePathSection();
	void unblockPathSection();
	int getEmptyDischargingStation();
	//void setWaitingArea(WaitingArea);



};
#endif // !defined(EA_8714FDB4_A9FD_466e_BF44_3EC28972B799__INCLUDED_)
