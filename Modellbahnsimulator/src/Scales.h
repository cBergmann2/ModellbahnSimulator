///////////////////////////////////////////////////////////
//  Scales.h
//  Implementation of the Class Scales
//  Created on:      04-Jul-2016 09:47:38
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_3C335383_6EA5_4015_9842_385D47134873__INCLUDED_)
#define EA_3C335383_6EA5_4015_9842_385D47134873__INCLUDED_


#include "Station.h"
#include "PathSection.h"
#include "Defines.h"
#include "DischargingArea.h"


class Scales : public Station
{
private:

public:
	void static taskBehavior(void*);
	QueueHandle_t mailbox;
	DischargingArea *dischargingArea;

	PathSection *pathToStartArea;
	PathSection* getPathSectionToStartArea();
	double scalingProcedure();

//	void setLoadingArea(LoadingArea*);
//	LoadingArea* getLoadingArea();
	void setMailbox(QueueHandle_t);
	QueueHandle_t getMailbox();

};
#endif // !defined(EA_3C335383_6EA5_4015_9842_385D47134873__INCLUDED_)
