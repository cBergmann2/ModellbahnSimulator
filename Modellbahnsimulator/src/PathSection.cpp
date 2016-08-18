///////////////////////////////////////////////////////////
//  PathSection.cpp
//  Implementation of the Class PathSection
//  Created on:      04-Jul-2016 09:47:38
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "PathSection.h"

using namespace std;

/**************************************************
Function name:	Konstruktor
returns: 
argl: 
Created by:		Christoph Bergmann
Date created:	22.07.2016
Description:	Initialisiert die Semaphore
**************************************************/
PathSection::PathSection(){
	semHandle = xSemaphoreCreateBinary();

	xSemaphoreGive(semHandle);
}



PathSection::~PathSection(){

}

/**************************************************
Function name:	occupiePath
returns:
argl:
Created by:		Christoph Bergmann
Date created:	22.07.2016
Description:	Belegt den Weg
**************************************************/
void PathSection::occupiePath(){

	if (xSemaphoreTake(semHandle, portMAX_DELAY) == 0){
		/*FEHLER*/
		cout << "!!!Fehler bei SemTake" << endl;
	}
}

/**************************************************
Function name:	releasePath
returns:
argl:
Created by:		Christoph Bergmann
Date created:	22.07.2016
Description:	Gibt den Weg wieder frei
**************************************************/
void PathSection::releasePath(){
	
	if (xSemaphoreGive(semHandle) == 0){
		/*FEHLER*/
		cout << "!!!Fehler bei SemGive" << endl;
	}
}