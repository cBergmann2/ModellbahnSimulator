///////////////////////////////////////////////////////////
//  DischargingStation.h
//  Implementation of the Class DischargingStation
//  Created on:      04-Jul-2016 09:47:22
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_F0F9718E_340D_4d12_83AB_A1A6D13EF606__INCLUDED_)
#define EA_F0F9718E_340D_4d12_83AB_A1A6D13EF606__INCLUDED_


#include "ThreeWaySwitch.h"
#include "Station.h"

class DischargingStation : public Station 
{

public:
	void dischargingProcedure();
	void taskBehavior();

};
#endif // !defined(EA_F0F9718E_340D_4d12_83AB_A1A6D13EF606__INCLUDED_)
