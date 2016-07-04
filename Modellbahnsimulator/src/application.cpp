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

#define INCLUDE_vTaskSuspend 1

using namespace std;

/******* Insert your code in this task **********************************************************/
extern "C" void taskApplication(void *pvParameters)
{
	(void*)pvParameters;		// Prevent unused warning
	signed portBASE_TYPE rV;	//Return Value
	int recBuffer; 

	void *startArea[2];

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

}
