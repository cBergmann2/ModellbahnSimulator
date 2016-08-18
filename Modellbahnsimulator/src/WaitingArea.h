///////////////////////////////////////////////////////////
//  WaitingArea.h
//  Implementation of the Class WaitingArea
//  Created on:      04-Jul-2016 09:47:47
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_DE57F2FC_27AF_4922_8B4A_F14A1A88B272__INCLUDED_)
#define EA_DE57F2FC_27AF_4922_8B4A_F14A1A88B272__INCLUDED_


#include "Station.h"
#include "Defines.h"
#include "Scales.h"
#include "DischargingArea.h"

class DischargingArea;
class Scales;
class WaitingArea : public Station 
{
private:
	QueueHandle_t mailbox;
	Scales *scales;
	DischargingArea *dischargingArea;

public:
	WaitingArea();
	~WaitingArea();
	void static taskBehavior(void *parms);
	
	void setMailbox(QueueHandle_t);
	QueueHandle_t getMailbox();
	void setScales(Scales*);
	Scales* getScales();
	void setDischargingArea(DischargingArea*);
	DischargingArea* getDischargingArea();
	
};
#endif // !defined(EA_DE57F2FC_27AF_4922_8B4A_F14A1A88B272__INCLUDED_)
