/**************************************************************************************************
Module:		PathSection.h
Purpose:
System:		Visual Studio / Windows - FreeRTOS Simulator
Date:		2016-07-04
Version:	2.1.0
Author:		Christoph Bergmann
**************************************************************************************************/

#if !defined(EA_87B819B5_AD99_4152_80A7_4C0DE723B2AF__INCLUDED_)
#define EA_87B819B5_AD99_4152_80A7_4C0DE723B2AF__INCLUDED_

#include <FreeRTOS.h>
#include <stdio.h>
#include <iostream>
#include "task.h"
#include "util\bprint.h"
#include "util\simCommunication.h"
#include "kernel\queue.h"
#include "semphr.h"

#define INCLUDE_vTaskSuspend 1


class PathSection
{
private:
	SemaphoreHandle_t semHandle;

public:
	PathSection();
	virtual ~PathSection();

	void occupiePath();
	void releasePath();


};
#endif // !defined(EA_87B819B5_AD99_4152_80A7_4C0DE723B2AF__INCLUDED_)
