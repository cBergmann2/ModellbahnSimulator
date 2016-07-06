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
#include "Defines.h"

#define INCLUDE_vTaskSuspend 1

using namespace std;

extern "C" void StartArea::taskBehavior(void *parms){
	int emptyLoadingStation;
	int recBuffer;
	StartArea *sA = (StartArea*)parms;


	sA->pSLoadingArea = sA->loadingArea->getPathSection();
	
	cout << "Startarea: betriebsbereit" << endl;
	
	while (true){
		xQueueReceive(sA->mailboxStartArea, &recBuffer, portMAX_DELAY);
		if (recBuffer == START_PLACE_PRESENCE_SENSOR_INCOMING){

			cout << "Startarea: Fahrzeug eingetroffen" << endl;

			sA->pSLoadingArea->occupiePath();

			cout << "Startarea: Streckenabschnitt zur Beladestation blockiert" << endl;

			sA->loadingArea->occupiePlaceInLoadingArea();

			cout << "Startarea: Platz in Beladebereich blockiert" << endl;

			emptyLoadingStation = sA->loadingArea->getEmptyLoadingStation();

			switch (emptyLoadingStation){
			case 0:
				sA->loadingArea->getLoadingStation(0)->occupieStation();
				sendTo(SWITCH_LOADINGSTATION, LOAD_PLACE_1);

				break;
			case 1:
				sA->loadingArea->getLoadingStation(1)->occupieStation();
				sendTo(SWITCH_LOADINGSTATION, LOAD_PLACE_2);
				break;
			}

			sendTo(START_PLACE_STOP_ACTOR, DEACTIVATE);


			xQueueReceive(sA->mailboxStartArea, &recBuffer, portMAX_DELAY);
			if (recBuffer == START_PLACE_PRESENCE_SENSOR_OUTGOING){
				sendTo(START_PLACE_STOP_ACTOR, ACTIVATE);
			}
		}
		else{
			cout << "FEHLER: Start Area falsches Kommando" << endl;
		}
	}

}

void StartArea::setMailbox(QueueHandle_t mailbox){
	this->mailboxStartArea = mailbox;
}

void StartArea::setCommunicationSim(xQueueHandle handle){
	this->xQHandle = handle;
}

void StartArea::setLoadingArea(LoadingArea *loadingArea){
	this->loadingArea = loadingArea;
}