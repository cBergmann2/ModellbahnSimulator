///////////////////////////////////////////////////////////
//  Scales.cpp
//  Implementation of the Class Scales
//  Created on:      04-Jul-2016 09:47:39
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "Scales.h"

using namespace std;



PathSection* Scales::getPathSectionToStartArea(){

	return  this->pathToStartArea;
}


double Scales::scalingProcedure(){

	return 0;
}


extern "C" void Scales::taskBehavior(void *parms){
/*	Scales* scales = (Scales*)parms;

	xQueueReceive(ls->getMailbox(), &recBuffer, portMAX_DELAY);
	if (recBuffer == LOAD_PLACE_1_PRESENCE_SENSOR_INCOMING ||
		recBuffer == LOAD_PLACE_2_PRESENCE_SENSOR_INCOMING){

		*/
}


void Scales::setMailbox(QueueHandle_t mailbox){
	this->mailbox = mailbox;
}

QueueHandle_t Scales::getMailbox(){
	return this->mailbox;
}