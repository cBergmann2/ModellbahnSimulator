///////////////////////////////////////////////////////////
//  WaitingArea.cpp
//  Implementation of the Class WaitingArea
//  Created on:      04-Jul-2016 09:47:47
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "WaitingArea.h"

using namespace std;

WaitingArea::WaitingArea(){

}
WaitingArea::~WaitingArea(){

}

/**************************************************
Function name:		taskBehavior
returns:
argl:				Referenz auf Wartebreich
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Verhalten des Wartebereichs
Notes:				Diese Funktion ist als eigenständige Task auszuführen
**************************************************/
extern "C" void WaitingArea::taskBehavior(void *parms){
	
	int recBuffer;
	WaitingArea *wA = (WaitingArea*)parms;

	cout << "Waitingarea: betriebsbereit" << endl;


	while (true){
		xQueueReceive(wA->getMailbox(), &recBuffer, portMAX_DELAY);
		if (recBuffer == WAITING_PLACE_PRESENCE_SENSOR_INCOMING)
		{
			//cout << "Waitingarea: Fahrzeug eingetroffen" << endl;

			wA->getDischargingArea()->unblockPathSection();
			//cout << "WaitingArea: Streckenabschnitt freigegeben" << endl;
			wA->getDischargingArea()->unblockPlaceInDischargingArea();

			
			wA->getScales()->occupieStation();				//Waage reservieren
			//cout << "Waitingarea: Platz in Waage blockiert" << endl;

			vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) + 1);							//kritischer Programmabschnitt -> Priorität erhöhen

			sendTo(WAITING_PLACE_STOP_ACTOR, DEACTIVATE);
			xQueueReceive(wA->getMailbox(), &recBuffer, portMAX_DELAY);
			if (recBuffer == WAITING_PLACE_PRESENCE_SENSOR_OUTGOING)
			{
				sendTo(WAITING_PLACE_STOP_ACTOR, ACTIVATE);
				wA->unblockStation();
				//cout << "WaitingArea: Wartebreich freigegeben" << endl;
			}

			vTaskPrioritySet(NULL, uxTaskPriorityGet(NULL) - 1);							//kritischer Programmabschnitt vorbei -> Priorität heruntersetzen

		}	

	}
	
}

/**************************************************
Function name:		setDischargingArea
returns:
argl:				Referenz auf Entladebereich
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Setzt die Referenz auf den Entladebereich
Notes:
**************************************************/
void WaitingArea::setDischargingArea(DischargingArea* dischargingArea){
	this->dischargingArea = dischargingArea;
}

/**************************************************
Function name:		getDischargingArea
returns:			DischargingArea*
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		Liefert eine Referenz auf den Entladebereich
Notes:
**************************************************/
DischargingArea* WaitingArea::getDischargingArea(){
	return this->dischargingArea;
}

/**************************************************
Function name:		setMailbox
returns:
argl:				Mailbox über die mit der Task kommunikziert werden soll
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		
Notes:
**************************************************/
void WaitingArea::setMailbox(QueueHandle_t mailbox){
	this->mailbox = mailbox;
}

/**************************************************
Function name:		getMailbox
returns:			QueueHandle_t
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:		
Notes:
**************************************************/
QueueHandle_t WaitingArea::getMailbox(){
	return this->mailbox;
}

/**************************************************
Function name:		setScales
returns:
argl:				Referenz auf die Waage
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:
Notes:
**************************************************/
void WaitingArea::setScales(Scales *scales){
	this->scales = scales;
}

/**************************************************
Function name:		getScales
returns:			Scales*
Created by:			Christoph Bergmann
Date created:		20.07.2016
Description:
Notes:
**************************************************/
Scales* WaitingArea::getScales(){
	return this->scales;
}
