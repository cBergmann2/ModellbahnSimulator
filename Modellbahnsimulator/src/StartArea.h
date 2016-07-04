///////////////////////////////////////////////////////////
//  StartArea.h
//  Implementation of the Class StartArea
//  Created on:      04-Jul-2016 09:47:42
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_B806C871_42C6_449b_AEAE_0CEE62310444__INCLUDED_)
#define EA_B806C871_42C6_449b_AEAE_0CEE62310444__INCLUDED_


#include "Station.h"
#include "PathSection.h"
#include "LoadingStation.h"
#include "LoadingArea.h"
#include "Defines.h"

class StartArea : public Station 
{
private:
	PathSection *pSLoadingArea;
	LoadingArea *loadingArea;
public:
	void taskBehavior(void*);

};
#endif // !defined(EA_B806C871_42C6_449b_AEAE_0CEE62310444__INCLUDED_)
