///////////////////////////////////////////////////////////
//  Controller.h
//  Implementation of the Class Controller
//  Created on:      04-Jul-2016 09:47:21
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_36E3EC68_6064_484a_91A5_ABA8F0C16482__INCLUDED_)
#define EA_36E3EC68_6064_484a_91A5_ABA8F0C16482__INCLUDED_

class Controller
{

public:
	Controller();
	virtual ~Controller();

	void setStopActor(Station station, bool activate);
	void startDischargingProcess(int dischargingStation);
	void startWeighingProcess();
	void startLoadingProcess(int station);

};
#endif // !defined(EA_36E3EC68_6064_484a_91A5_ABA8F0C16482__INCLUDED_)
