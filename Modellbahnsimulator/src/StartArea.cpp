/**************************************************************************************************
Module:		StartArea.cpp
Purpose:	
System:		Visual Studio / Windows - FreeRTOS Simulator
Date:		2016-07-04
Version:	2.1.0
Author:		Christoph Bergmann
**************************************************************************************************/
#include <FreeRTOS.h>
#include <stdio.h>
#include <iostream>
#include "task.h"
#include "util\bprint.h"
#include "util\simCommunication.h"
#include "kernel\queue.h"
#include "StartArea.h"

#define INCLUDE_vTaskSuspend 1

using namespace std;

extern "C" void StartArea::taskBehavior(void *pvParameters){
	(void*)pvParameters;		// Prevent unused warning
	int emptyLoadingStation;
	xQueueHandle xQHandle;

	pSLoadingArea = loadingArea->getPathSection();

	pSLoadingArea->occupiePath();

	loadingArea->occupiePlaceInLoadingArea();

	emptyLoadingStation = loadingArea->getEmptyLoadingStation();

	switch (emptyLoadingStation){
	case 0:
		loadingArea->getLoadingStation[0]->occupieStation();
		sendTo(SWITCH_LOADINGSTATION, LOAD_PLACE_1);
		
		break;
	case 1:
		loadingArea->getLoadingStation[1]->occupieStation();
		sendTo(SWITCH_LOADINGSTATION, LOAD_PLACE_2);
		break;
	}

	sendTo(START_PLACE_STOP_ACTOR, DEACTIVATE);

	sendTo(START_PLACE_STOP_ACTOR, ACTIVATE);


	

}