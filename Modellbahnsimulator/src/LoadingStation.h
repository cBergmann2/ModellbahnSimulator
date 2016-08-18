///////////////////////////////////////////////////////////
//  LoadingStation.h
//  Implementation of the Class LoadingStation
//  Created on:      04-Jul-2016 09:47:36
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#ifndef EA_6D37D681_4F24_4629_BF46_FDF3AEE1337A__INCLUDED_
#define EA_6D37D681_4F24_4629_BF46_FDF3AEE1337A__INCLUDED_

#include "Station.h"
#include "PathSection.h"
#include "DischargingArea.h"
#include "Defines.h"
#include "Scales.h"
#include "LoadingArea.h"

class LoadingArea;
class LoadingStation : public Station
{
private:
	int ID;
	QueueHandle_t mailbox;
	PathSection *pathToLoadingStations, *pathToScales;
	DischargingArea *dischargingArea;
	LoadingArea* loadingArea;
	Scales *scales;

public:
	void static taskBehavior(void *parms);
	
	void loadingProcedure();
	int GetID();
	void SetID(int newVal);
	void setMailbox(QueueHandle_t);
	QueueHandle_t getMailbox();
	void setPathToLoadingStations(PathSection*);
	PathSection* getPathToLoadingStations();
	void setPathToScales(PathSection*);
	PathSection* getPathToScales();
	void setDischargingArea(DischargingArea*);
	DischargingArea* getDischargingArea();
	void setScales(Scales*);
	Scales* getScales();
	void setLoadingArea(LoadingArea*);
	LoadingArea* getLoadingArea();
};
#endif // !defined(EA_6D37D681_4F24_4629_BF46_FDF3AEE1337A__INCLUDED_)
