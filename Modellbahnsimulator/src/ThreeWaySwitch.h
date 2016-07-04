///////////////////////////////////////////////////////////
//  ThreeWaySwitch.h
//  Implementation of the Class ThreeWaySwitch
//  Created on:      04-Jul-2016 09:47:45
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_FF8B53DF_3372_4a0f_A4E2_21D28D539BFE__INCLUDED_)
#define EA_FF8B53DF_3372_4a0f_A4E2_21D28D539BFE__INCLUDED_

#include "TwoWaySwitch.h"

class ThreeWaySwitch : public TwoWaySwitch
{

public:
	ThreeWaySwitch();
	virtual ~ThreeWaySwitch();

	void setPosition(int position);

};
#endif // !defined(EA_FF8B53DF_3372_4a0f_A4E2_21D28D539BFE__INCLUDED_)
