/**************************************************************************************************
Module:		application.c
Purpose:	This template provides a FreeRTOS Windows Simulation
System:		Visual Studio / Windows - FreeRTOS Simulator
Date:		2016-03-11
Version:	2.1.0
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
#define NO_BUFFER 4

using namespace std;

/******* Insert your code in this task **********************************************************/
extern "C" void taskApplication(void *pvParameters)
{
	(void*)pvParameters;		// Prevent unused warning
	signed portBASE_TYPE rV;	//Return Value
	int recBuffer; 
	void *startAreaInit[2];
	UBaseType_t taskPrio;
	QueueHandle_t mailboxStartArea, mailboxLoadingStation1, mailboxLoadingStation2, mailboxScales, mailboxDischargingStation1, mailboxDischargingStation2, mailboxDischargingStation3;

	TaskHandle_t tidStartArea, tidLoadingStation1, tidLoadingStation2, tidScales, tidDischargingStation1, tidDischargingStation2, tidDischargingStation3;

	StartArea *startArea;
	LoadingArea *loadingArea;
	Scales *scales;
	DischargingArea *dischargingArea;
	DischargingStation *dischargingStation1, *dischargingStation2, *dischargingStation3;
	WaitingArea *waitingArea;

	xQueueHandle xQHandle = initSystem();	// Init System
	


	if ((rV = xQueueReceive(xQHandle, &recBuffer, portMAX_DELAY)) == 0){	//Bestätigung der Initialisierung holen
		/*Error*/
		cout << "FEHLER: Initialisierung des Simulators fehlgeschlagen" << endl;
	}
	if (recBuffer != 30){
		/*ERROR Ereignis-Kennung nach initialisierung falsch*/
		cout << "FEHLER: Kennung nach Initialisierung falsch" << endl;
		cout << "Press any key to exit" << endl;
		cin.get();
		exit(0);
	}
	else{
		cout << "Verbindung zum Simulator aufgebaut" << endl;
	}

	taskPrio = uxTaskPriorityGet(NULL);

	/*Create communication objects and worker tasks*/
	startArea = new StartArea();
	loadingArea = new LoadingArea();
	scales = new Scales();
	waitingArea = new WaitingArea();
	dischargingArea = new DischargingArea(waitingArea);

	startArea->setLoadingArea(loadingArea);


	mailboxStartArea = xQueueCreate(NO_BUFFER, sizeof(int));
	startArea->setCommunicationSim(xQHandle);
	startArea->setMailbox(mailboxStartArea);

	mailboxLoadingStation1 = xQueueCreate(NO_BUFFER, sizeof(int));
	loadingArea->getLoadingStation(0)->setMailbox(mailboxLoadingStation1);
	loadingArea->getLoadingStation(0)->setDischargingArea(dischargingArea);
	loadingArea->getLoadingStation(0)->setScales(scales);

	mailboxLoadingStation2 = xQueueCreate(NO_BUFFER, sizeof(int));
	loadingArea->getLoadingStation(1)->setMailbox(mailboxLoadingStation2);
	loadingArea->getLoadingStation(1)->setDischargingArea(dischargingArea);
	loadingArea->getLoadingStation(1)->setScales(scales);

	mailboxScales = xQueueCreate(NO_BUFFER, sizeof(int));
	scales->setMailbox(mailboxScales);
	scales->setDischargingArea(dischargingArea);

	




	xTaskCreate(StartArea::taskBehavior, "START_AREA", 2048, (void*)startArea, taskPrio - 1, &tidStartArea);
	
	xTaskCreate(LoadingStation::taskBehavior, "LOADING_STATION_1", 2048, (void*)loadingArea->getLoadingStation(0), taskPrio - 1, &tidLoadingStation1);
	xTaskCreate(LoadingStation::taskBehavior, "LOADING_STATION_2", 2048, (void*)loadingArea->getLoadingStation(1), taskPrio - 1, &tidLoadingStation2);

	xTaskCreate(Scales::taskBehavior, "SCALES", 2048, (void*)scales, taskPrio - 1, &tidScales);

	while (true){
		if ((rV = xQueueReceive(xQHandle, &recBuffer, portMAX_DELAY)) == 0){	//Daten aus Queue holen und an entsprechendes Objekt weiterleiten
			/*Error*/
			cout << "FEHLER: xQueueReceive" << endl;
			cout << "Press any key to exit" << endl;
			cin.get();
			exit(0);
		}
		cout << "RECIVE MSG from Simulator" << endl;

		switch (recBuffer){
		case START_PLACE_PRESENCE_SENSOR_INCOMING:
		case 1:
			xQueueSendToBack(mailboxStartArea, &recBuffer, portMAX_DELAY);
			cout << "APPLICATION: Send msg to StartArea" << endl;
			break;
		case LOAD_PLACE_1_PRESENCE_SENSOR_INCOMING:
		case LOAD_PLACE_1_PRESENCE_SENSOR_OUTGOING:
		case LOAD_PLACE_1_LOADING_ACTIVITY:
			xQueueSendToBack(mailboxLoadingStation1, &recBuffer, portMAX_DELAY);
			cout << "APPLICATION: Send msg to StartArea" << endl;
			break;
		case LOAD_PLACE_2_PRESENCE_SENSOR_INCOMING:
		case LOAD_PLACE_2_PRESENCE_SENSOR_OUTGOING:
		case LOAD_PLACE_2_LOADING_ACTIVITY:
			xQueueSendToBack(mailboxLoadingStation2, &recBuffer, portMAX_DELAY);
			cout << "APPLICATION: Send msg to StartArea" << endl;
			break;
		case SCALE_PRESENCE_SENSOR_INCOMING_TO_DISCHARGING_AREA:
		case SCALE_PRESENCE_SENSOR_OUTGOING_TO_DISCHARGING_AREA:
		case SCALE_PRESENCE_SENSOR_INCOMING_TO_START_AREA:
		case SCALE_PRESENCE_SENSOR_OUTGOING_TO_START_AREA:
		case SCALE_SCALE_ACTIVITY:
			xQueueSendToBack(mailboxScales, &recBuffer, portMAX_DELAY);
			cout << "APPLICATION: Send msg to Scales";
		}
	}
}
