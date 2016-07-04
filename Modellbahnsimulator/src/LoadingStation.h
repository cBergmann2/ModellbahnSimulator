///////////////////////////////////////////////////////////
//  LoadingStation.h
//  Implementation of the Class LoadingStation
//  Created on:      04-Jul-2016 09:47:36
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_6D37D681_4F24_4629_BF46_FDF3AEE1337A__INCLUDED_)
#define EA_6D37D681_4F24_4629_BF46_FDF3AEE1337A__INCLUDED_

#include "Station.h"

class LoadingStation : public Station
{

public:
	void loadingProcedure();
	void taskBehavior();
	int GetID();
	void SetID(int newVal);

private:
	int ID;

};
#endif // !defined(EA_6D37D681_4F24_4629_BF46_FDF3AEE1337A__INCLUDED_)
