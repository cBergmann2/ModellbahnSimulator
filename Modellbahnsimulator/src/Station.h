///////////////////////////////////////////////////////////
//  Station.h
//  Implementation of the Class Station
//  Created on:      04-Jul-2016 09:47:44
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_3E0B59FF_ECA7_473b_B91A_9A66742A4F88__INCLUDED_)
#define EA_3E0B59FF_ECA7_473b_B91A_9A66742A4F88__INCLUDED_

#include <FreeRTOS.h>
#include <stdio.h>
#include <iostream>
#include "task.h"
#include "util\bprint.h"
#include "util\simCommunication.h"
#include "kernel\queue.h"
#include "semphr.h"

class Station
{

public:
	Station();
	virtual ~Station();

	int occupieStation();
	void presenceSensorTriggered(int sensorNumber);
	void SetSopActorActive(bool newVal);
	void unblockStation();

	bool occupied;

private:
	/**
	 * Als Semaphore nutzen
	 */
	SemaphoreHandle_t semHandle;
	bool stopActorActive;

};
#endif // !defined(EA_3E0B59FF_ECA7_473b_B91A_9A66742A4F88__INCLUDED_)
