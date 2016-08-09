///////////////////////////////////////////////////////////
//  DischargingStation.h
//  Implementation of the Class DischargingStation
//  Created on:      04-Jul-2016 09:47:22
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_F0F9718E_340D_4d12_83AB_A1A6D13EF606__INCLUDED_)
#define EA_F0F9718E_340D_4d12_83AB_A1A6D13EF606__INCLUDED_


//#include "ThreeWaySwitch.h"
#include "DischargingArea.h"
#include "Station.h"
#include "WaitingArea.h"
#include "Defines.h"

class WaitingArea;
class DischargingArea;
class  DischargingStation : public Station
{
private:
	int ID;															//Station ID or number
	WaitingArea *waitingArea;

public:
	DischargingStation();
	DischargingStation(int, WaitingArea *waitingArea, DischargingArea*);
	virtual ~DischargingStation();

	void static taskBehavior(void *parms);
	void dischargingProcedure();
	
	QueueHandle_t mailbox;
	void setMailbox(QueueHandle_t);
	QueueHandle_t getMailbox();
	
	void setWaitingArea(WaitingArea*);
	WaitingArea *getWaitingArea();

	DischargingArea *dischargingArea;
	void setDischargingArea(DischargingArea*);
	DischargingArea* getDischargingArea();
};
#endif // !defined(EA_F0F9718E_340D_4d12_83AB_A1A6D13EF606__INCLUDED_)
