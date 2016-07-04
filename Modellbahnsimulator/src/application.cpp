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
	QueueHandle_t mailboxStartArea;

	TaskHandle_t tidStartArea;

	StartArea *startArea;
	LoadingArea *loadingArea;

	xQueueHandle xQHandle = initSystem();	// Init System
	


	if ((rV = xQueueReceive(xQHandle, &recBuffer, portMAX_DELAY)) == 0){	//Bestätigung der Initialisierung holen
		/*Error*/
		cout << "FEHLER: " << endl;
	}
	if (recBuffer != 30){
		/*ERROR Ereignis-Kennung nach initialisierung falsch*/
		cout << "FEHLER: Kennung nach Initialisierung falsch" << endl;
	}
	else{
		cout << "Verbindung zum Simulator aufgebaut" << endl;
	}

	taskPrio = uxTaskPriorityGet(NULL);

	/*Create communication objects and worker tasks*/
	startArea = new StartArea();
	loadingArea = new LoadingArea();

	startArea->setLoadingArea(loadingArea);


	mailboxStartArea = xQueueCreate(NO_BUFFER, sizeof(int));
	startArea->setCommunicationSim(xQHandle);
	startArea->setMailbox(mailboxStartArea);
	xTaskCreate(StartArea::taskBehavior, "START_AREA", 2048, (void*)startArea, taskPrio - 1, &tidStartArea);

	while (true){
		if ((rV = xQueueReceive(xQHandle, &recBuffer, portMAX_DELAY)) == 0){	//Bestätigung der Initialisierung holen
			/*Error*/
			cout << "FEHLER: xQueueReceive" << endl;
		}

		switch (recBuffer){
		case 0:
		case 1:
			/*START_PLACE_PRESENCE_SENSOR_INCOMING*/
			xQueueSendToBack(mailboxStartArea, &recBuffer, portMAX_DELAY);
			cout << "APPLICATION: Send msg to StartArea" << endl;
			break;
		
		}
	}



}
