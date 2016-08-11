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
	BaseType_t retValue;
	UBaseType_t taskPrio;
	QueueHandle_t mailboxStartArea, mailboxLoadingStation1, mailboxLoadingStation2, mailboxScales, mailboxDischargingStation1, mailboxDischargingStation2, mailboxDischargingStation3, mailboxWaitingArea;

	TaskHandle_t tidStartArea, tidLoadingStation1, tidLoadingStation2, tidScales, tidDischargingStation1, tidDischargingStation2, tidDischargingStation3, tidWaitingArea;

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

	mailboxDischargingStation1 = xQueueCreate(NO_BUFFER, sizeof(int));
	dischargingArea->getDischragingStation(0)->setMailbox(mailboxDischargingStation1);

	mailboxDischargingStation2 = xQueueCreate(NO_BUFFER, sizeof(int));
	dischargingArea->getDischragingStation(1)->setMailbox(mailboxDischargingStation2);

	mailboxDischargingStation3 = xQueueCreate(NO_BUFFER, sizeof(int));
	dischargingArea->getDischragingStation(2)->setMailbox(mailboxDischargingStation3);

	mailboxWaitingArea = xQueueCreate(NO_BUFFER, sizeof(int));
	waitingArea->setMailbox(mailboxWaitingArea);
	waitingArea->setDischargingArea(dischargingArea);
	waitingArea->setScales(scales);

	if ((retValue = xTaskCreate(StartArea::taskBehavior, "START_AREA", 1024, (void*)startArea, taskPrio - 2, &tidStartArea)) != pdPASS){
		cout << "ERROR: xTaskCreate fails: " << retValue << endl;
		cout << "Press any key to exit" << endl;
		cin.get();
		exit(0);
	}
	else{
		cout << "Task StartArea gestartet" << endl;
	}
	
	if ((retValue = xTaskCreate(LoadingStation::taskBehavior, "LOADING_STATION_1", 1024, (void*)loadingArea->getLoadingStation(0), taskPrio - 2, &tidLoadingStation1)) != pdPASS){
		cout << "ERROR: xTaskCreate fails: " << retValue << endl;
		cout << "Press any key to exit" << endl;
		cin.get();
		exit(0);
	}
	else{
		cout << "Task LoadingStation1 gestartet" << endl;
	}
	
	if ((retValue = xTaskCreate(LoadingStation::taskBehavior, "LOADING_STATION_2", 1024, (void*)loadingArea->getLoadingStation(1), taskPrio - 2, &tidLoadingStation2)) != pdPASS){
		cout << "ERROR: xTaskCreate fails: " << retValue << endl;
		cout << "Press any key to exit" << endl;
		cin.get();
		exit(0);
	}
	else{
		cout << "Task LoadingStation2 gestartet" << endl;
	}

	if ((retValue = xTaskCreate(Scales::taskBehavior, "SCALES", 1024, (void*)scales, taskPrio - 2, &tidScales)) != pdPASS){
		cout << "ERROR: xTaskCreate fails: " << retValue << endl;
		cout << "Press any key to exit" << endl;
		cin.get();
		exit(0);
	}
	else{
		cout << "Task Scales gestartet" << endl;
	}

	if ((retValue = xTaskCreate(DischargingStation::taskBehavior, "DISCHARGING_STATION_1", 1024, (void*)dischargingArea->getDischragingStation(0), taskPrio - 2, &tidDischargingStation1)) != pdPASS){
		cout << "ERROR: xTaskCreate fails: " << retValue << endl;
		cout << "Press any key to exit" << endl;
		cin.get();
		exit(0);
	}
	else{
		cout << "Task DischargingStation1 gestartet" << endl;
	}

	if ((retValue = xTaskCreate(DischargingStation::taskBehavior, "DISCHARGING_STATION_2", 1024, (void*)dischargingArea->getDischragingStation(1), taskPrio - 2, &tidDischargingStation2)) != pdPASS){
		cout << "ERROR: xTaskCreate fails: " << retValue << endl;
		cout << "Press any key to exit" << endl;
		cin.get();
		exit(0);
	}
	else{
		cout << "Task DischargingStation2 gestartet" << endl;
	}

	if ((retValue = xTaskCreate(DischargingStation::taskBehavior, "DISCHARGING_STATION_3", 1024, (void*)dischargingArea->getDischragingStation(2), taskPrio - 2, &tidDischargingStation3)) != pdPASS){
		cout << "ERROR: xTaskCreate fails: " << retValue << endl;
		cout << "Press any key to exit" << endl;
		cin.get();
		exit(0);
	}
	else{
		cout << "Task DischargingStation3 gestartet" << endl;
	}
	
	if ((retValue = xTaskCreate(WaitingArea::taskBehavior, "WatingArea", 1024, (void*)waitingArea, taskPrio - 2, &tidWaitingArea)) != pdPASS){
		cout << "ERROR: xTaskCreate fails: " << retValue << endl;
		cout << "Press any key to exit" << endl;
		cin.get();
		exit(0);
	}
	else{
		cout << "Task WaitingArea gestartet" << endl;
	}
	

	while (true){
		if ((rV = xQueueReceive(xQHandle, &recBuffer, portMAX_DELAY)) == 0){	//Daten aus Queue holen und an entsprechendes Objekt weiterleiten
			/*Error*/
			cout << "FEHLER: xQueueReceive" << endl;
			cout << "Press any key to exit" << endl;
			cin.get();
			exit(0);
		}
		//cout << "RECIVE MSG from Simulator" << endl;

		switch (recBuffer){
		case START_PLACE_PRESENCE_SENSOR_INCOMING:
			cout << "APPLICATION: START_PLACE_PRESENCE_SENSOR_INCOMING" << endl;
		case START_PLACE_PRESENCE_SENSOR_OUTGOING:
			cout << "APPLICATION: START_PLACE_PRESENCE_SENSOR_OUTGOING" << endl;
			xQueueSendToBack(mailboxStartArea, &recBuffer, portMAX_DELAY);
			break;
		case LOAD_PLACE_1_PRESENCE_SENSOR_INCOMING:
			cout << "APPLICATION: LOAD_PLACE_1_PRESENCE_SENSOR_INCOMING" << endl;
		case LOAD_PLACE_1_PRESENCE_SENSOR_OUTGOING:
			cout << "APPLICATION: LOAD_PLACE_1_PRESENCE_SENSOR_INCOMING" << endl;
		case LOAD_PLACE_1_LOADING_ACTIVITY:
			cout << "APPLICATION: LOAD_PLACE_1_LOADING_ACTIVITY" << endl;
			xQueueSendToBack(mailboxLoadingStation1, &recBuffer, portMAX_DELAY);
			break;
		case LOAD_PLACE_2_PRESENCE_SENSOR_INCOMING:
			cout << "APPLICATION: LOAD_PLACE_2_PRESENCE_SENSOR_INCOMING" << endl;
		case LOAD_PLACE_2_PRESENCE_SENSOR_OUTGOING:
			cout << "APPLICATION: LOAD_PLACE_2_PRESENCE_SENSOR_OUTGOING" << endl;
		case LOAD_PLACE_2_LOADING_ACTIVITY:
			cout << "APPLICATION: LOAD_PLACE_2_LOADING_ACTIVITY" << endl;
			xQueueSendToBack(mailboxLoadingStation2, &recBuffer, portMAX_DELAY);
			break;
		case SCALE_PRESENCE_SENSOR_INCOMING_TO_DISCHARGING_AREA:
		case SCALE_PRESENCE_SENSOR_OUTGOING_TO_DISCHARGING_AREA:
		case SCALE_PRESENCE_SENSOR_INCOMING_TO_START_AREA:
		case SCALE_PRESENCE_SENSOR_OUTGOING_TO_START_AREA:
		case SCALE_SCALE_ACTIVITY:
			xQueueSendToBack(mailboxScales, &recBuffer, portMAX_DELAY);
			cout << "APPLICATION: Send msg to Scales" << endl;
			break;
		case DISCHARGE_PLACE_1_PRESENCE_SENSOR_INCOMING:
		case DISCHARGE_PLACE_1_PRESENCE_SENSOR_OUTGOING:
		case DISCHARGE_PLACE_1_DISCHARGING_ACTIVITY:
			xQueueSendToBack(mailboxDischargingStation1, &recBuffer, portMAX_DELAY);
			cout << "APPLICATION: Send msg to DischargingStation1" << endl;
			break;
		case DISCHARGE_PLACE_2_PRESENCE_SENSOR_INCOMING:
		case DISCHARGE_PLACE_2_PRESENCE_SENSOR_OUTGOING:
		case DISCHARGE_PLACE_2_DISCHARGING_ACTIVITY:
			xQueueSendToBack(mailboxDischargingStation2, &recBuffer, portMAX_DELAY);
			cout << "APPLICATION: Send msg to DischargingStation2" << endl;
			break;
		case DISCHARGE_PLACE_3_PRESENCE_SENSOR_INCOMING:
		case DISCHARGE_PLACE_3_PRESENCE_SENSOR_OUTGOING:
		case DISCHARGE_PLACE_3_DISCHARGING_ACTIVITY:
			xQueueSendToBack(mailboxDischargingStation3, &recBuffer, portMAX_DELAY);
			cout << "APPLICATION: Send msg to DischargingStation3" << endl;
			break;
		case WAITING_PLACE_PRESENCE_SENSOR_INCOMING:
		case WAITING_PLACE_PRESENCE_SENSOR_OUTGOING:
			xQueueSendToBack(mailboxWaitingArea, &recBuffer, portMAX_DELAY);
			cout << "APPLICATION: Send msg to WaitingArea" << endl;
		}
	}
}

