///////////////////////////////////////////////////////////
//  PathSection.cpp
//  Implementation of the Class PathSection
//  Created on:      04-Jul-2016 09:47:38
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "PathSection.h"

using namespace std;

PathSection::PathSection(){
	semHandle = xSemaphoreCreateBinary();
}



PathSection::~PathSection(){

}


int PathSection::occupiePath(){

	if (xSemaphoreTake(semHandle, portMAX_DELAY) == 0){
		/*FEHLER*/
		cout << "Fehler bei SemTake" << endl;
	}
}


void PathSection::releasePath(){
	
	if (xSemaphoreGive(semHandle) == 0){
		/*FEHLER*/
		cout << "Fehler bei SemGive" << endl;
	}
}