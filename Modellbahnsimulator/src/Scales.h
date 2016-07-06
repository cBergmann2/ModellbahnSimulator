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



class Scales : public Station
{
private:
//	LoadingArea* loadingArea;
	QueueHandle_t mailbox;

public:
	PathSection *pathToStartArea;

	PathSection* getPathSectionToStartArea();
	double scalingProcedure();
	void static taskBehavior(void *parms);

//	void setLoadingArea(LoadingArea*);
//	LoadingArea* getLoadingArea();
	void setMailbox(QueueHandle_t);
	QueueHandle_t getMailbox();

};
#endif // !defined(EA_3C335383_6EA5_4015_9842_385D47134873__INCLUDED_)
