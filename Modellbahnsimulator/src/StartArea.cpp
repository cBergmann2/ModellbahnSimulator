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

/// <summary>
///	 Funktion soll als eigenständige Task ausgeführt werden.
/// </summary>
extern "C" void StartArea::taskBehavior(void *parms){
	int emptyLoadingStation;
	int recBuffer;
	StartArea *sA = (StartArea*)parms;


	sA->pSLoadingArea = sA->loadingArea->getPathSection();
	
	cout << "Startarea: betriebsbereit" << endl;
	
	
	while (true){																			//Funktion des Startbereichs wird bis zum Ende des Programms zyklisch ausgeführt
		xQueueReceive(sA->mailboxStartArea, &recBuffer, portMAX_DELAY);						//Auf ankommendes Fahrzeug warten
		if (recBuffer == START_PLACE_PRESENCE_SENSOR_INCOMING){								

			//cout << "Startarea: Fahrzeug eingetroffen" << endl;

			sA->pSLoadingArea->occupiePath();												//Pfad zur Beladestation belegen

			//cout << "Startarea: Streckenabschnitt zur Beladestation blockiert" << endl;

			sA->loadingArea->occupiePlaceInLoadingArea();									//Platz im Beladebereich belegen

			//cout << "Startarea: Platz in Beladebereich blockiert" << endl;

			emptyLoadingStation = sA->loadingArea->getEmptyLoadingStation();				//Leere Beladestation ermitteln

			switch (emptyLoadingStation){
			case 0:
				sA->loadingArea->getLoadingStation(0)->occupieStation();					//Ladestation 1 belegen
				//cout << "Startarea: Bleadestation 1 blockiert" << endl;
				sendTo(SWITCH_LOADINGSTATION, LOAD_PLACE_1);								//Weiche in Richtung Ladestation 1 stellen

				break;
			case 1:
				sA->loadingArea->getLoadingStation(1)->occupieStation();					//Ladestation 2 belegen
				sendTo(SWITCH_LOADINGSTATION, LOAD_PLACE_2);								//Weiche in Richtung Ladestation 2 stellen
				//cout << "Startarea: Bleadestation 2 blockiert" << endl;
				break;
			}

			vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) + 1);							//kritischer Programmabschnitt -> Priorität erhöhen

			sendTo(START_PLACE_STOP_ACTOR, DEACTIVATE);										//Stop-Aktor des Startbereichs deaktivieren
			//cout << "Startarea: Stop-Actor deaktiviert" << endl;

			xQueueReceive(sA->mailboxStartArea, &recBuffer, portMAX_DELAY);					//Darauf warten, dass das Fahrzeug den Startbereich verlässt
			if (recBuffer == START_PLACE_PRESENCE_SENSOR_OUTGOING){
				sendTo(START_PLACE_STOP_ACTOR, ACTIVATE);									//Stop-Aktor des Startbereics aktivieren
				//cout << "Startarea: Stop-Actor aktiviert" << endl;
			}
			else{
				sA->errorHandling();														//Anderes Kommando empfangen, als erwartet wurde
			}

			vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) - 1);							//kritischer Programmabschnitt vorbei -> Priorität heruntersetzen
		}
		else{
			sA->errorHandling();															//Anderes Kommando empfangen, als erwartet wurde
		}
	}

}

/// <summary>
///	 Setzt die Mailbox des Startbereichs
/// </summary>
void StartArea::setMailbox(QueueHandle_t mailbox){
	this->mailboxStartArea = mailbox;
}

/// <summary>
///	 Liefert den xQueueHandle für die Kommunikation mit dem Simulator
/// </summary>
void StartArea::setCommunicationSim(xQueueHandle handle){
	this->xQHandle = handle;
}

/// <summary>
///	 Setzt die verwendete Instanz des Ladebereichs
/// </summary>
void StartArea::setLoadingArea(LoadingArea *loadingArea){
	this->loadingArea = loadingArea;
}

/// <summary>
///	 Gibt eine Fehlermeldung aus und beendet das Programm
/// </summary>
void StartArea::errorHandling(){
	cout << "FEHLER: Start Area nicht erwartetes Kommando empfangen" << endl;							//Es wurde ein anderes Kommando erwartet. Die Funktion der Task ist erheblich gestört.
	cout << "Press any key to exit" << endl;
	cin.get();
	exit(0);
}