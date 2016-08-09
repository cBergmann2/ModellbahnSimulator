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

extern "C" void WaitingArea::taskBehavior(void *parms){
	
	int recBuffer;
	WaitingArea *wA = (WaitingArea*)parms;

	cout << "Waitingarea: betriebsbereit" << endl;


	while (true){
		xQueueReceive(wA->getMailbox(), &recBuffer, portMAX_DELAY);
		if (recBuffer == WAITING_PLACE_PRESENCE_SENSOR_INCOMING)
		{
			cout << "Waitingarea: Fahrzeug eingetroffen" << endl;

			wA->getDischargingArea()->unblockPathSection();

			// wA->pSScales->occupiePath();
			//cout << "Waitingarea: Streckenabschnitt zur Waage blockiert" << endl;
			//wA->Scales->occupieStation();
			//cout << "Waitingarea: Platz in Waage blockiert" << endl;

			//sendTo(SCALES_PLACE_STOP_ACTOR, DEACTIVATE);


		}

		if (recBuffer == WAITING_PLACE_PRESENCE_SENSOR_OUTGOING)
		{
			sendTo(WAITING_PLACE_STOP_ACTOR, ACTIVATE);
		}
	}
	
}


void WaitingArea::setDischargingArea(DischargingArea* dischargingArea){
	this->dischargingArea = dischargingArea;
}

DischargingArea* WaitingArea::getDischargingArea(){
	return this->dischargingArea;
}

void WaitingArea::setMailbox(QueueHandle_t mailbox){
	this->mailbox = mailbox;
}

QueueHandle_t WaitingArea::getMailbox(){
	return this->mailbox;
}

void WaitingArea::setScales(Scales *scales){
	this->scales = scales;
}

Scales* WaitingArea::getScales(){
	return this->scales;
}
