///////////////////////////////////////////////////////////
//  Roadway.h
//  Implementation of the Class Roadway
//  Created on:      04-Jul-2016 09:47:38
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_6F019866_7C8D_4d9d_9042_D397AEF36B49__INCLUDED_)
#define EA_6F019866_7C8D_4d9d_9042_D397AEF36B49__INCLUDED_

#include "StartArea.h"
#include "DischargingArea.h"
#include "Scales.h"
#include "LoadingArea.h"

class Roadway
{

public:
	Roadway();
	virtual ~Roadway();
	StartArea *startArea;
	DischargingArea *dischargingArea;
	Scales *scales;
	LoadingArea *loadingArea;

};
#endif // !defined(EA_6F019866_7C8D_4d9d_9042_D397AEF36B49__INCLUDED_)
