#ifndef SCALES_H
#define SCALES_H


#pragma once

#include "Station.h"
#include "PathSection.h"
#include "Defines.h"
#include "DischargingArea.h"

class DischargingArea;
class WaitingArea;
class Scales : public Station
{
public:
	Scales();
	void static taskBehavior(void*);
	void setMailbox(QueueHandle_t);
	void setCommunicationSim(xQueueHandle);
	void errorHandling();

	void setDischargingArea(DischargingArea*);

	xQueueHandle xQHandle;
	QueueHandle_t mailboxStartArea;
	DischargingArea *dischargingArea;

	PathSection *pathToStartArea;
	PathSection *getPathSectionToStartArea();

	~Scales();
};


#endif