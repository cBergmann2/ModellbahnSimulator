///////////////////////////////////////////////////////////
//  DischargingStation.h
//  Implementation of the Class DischargingStation
//  Created on:      04-Jul-2016 09:47:22
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_F0F9718E_340D_4d12_83AB_A1A6D13EF606__INCLUDED_)
#define EA_F0F9718E_340D_4d12_83AB_A1A6D13EF606__INCLUDED_

#include ""
#include "ThreeWaySwitch.h"
#include "Station.h"

class DischargingStation : public Station , public StateMachineContext
{

public:
	dischargingProcedure();
	ThreeWaySwitch getThreeWaySwitch();
	void taskBehavior();

	/* Begin - EA generated code for Activities and Interactions */

	void taskBehavior();


	/* End - EA generated code for Activities and Interactions */

	/* Begin - EA generated code for StateMachine */






public:
	enum StateMachineEnum 
	{
		NOSTATEMACHINE,
		DischargingStation_ENUM_STMDISCHARGINGSTATION
	};

	enum StateEnum 
	{
		NOSTATE,
		DischargingStation_VIRTUAL_SUBMACHINESTATE,
		DischargingStation_ENUM_STMDISCHARGINGSTATION_STOPACTORDEACTIVATED,
		DischargingStation_ENUM_STMDISCHARGINGSTATION_EMPTY,
		DischargingStation_ENUM_STMDISCHARGINGSTATION_DISCHARGINGSTATIONFINISHED,
		DischargingStation_ENUM_STMDISCHARGINGSTATION_WAITINGAREAEMTPY,
		DischargingStation_ENUM_STMDISCHARGINGSTATION_OCCUPIED
	};

	enum TransitionEnum 
	{
		NOTRANSITION,
		DischargingStation_ENUM_OCCUPIED__TO__DISCHARGINGSTATIONFINISHED_195,
		DischargingStation_ENUM_EMPTY__TO__OCCUPIED_197,
		DischargingStation_ENUM_STOPACTORDEACTIVATED__TO__EMPTY_206,
		DischargingStation_ENUM_WAITINGAREAEMTPY__TO__STOPACTORDEACTIVATED_222,
		DischargingStation_ENUM_INITIAL_820_820__TO__EMPTY_200,
		DischargingStation_ENUM_DISCHARGINGSTATIONFINISHED__TO__WAITINGAREAEMTPY_221
	};

	enum EntryEnum
	{
		NOENTRY,
		DischargingStation_ENUM_STMDISCHARGINGSTATION_INITIAL_820_820
	};

	DischargingStation();
	DischargingStation(ContextManager* pManager, String sInstanceName);
	
	virtual ~DischargingStation();
	
	StateMachineImpl* m_StateMachineImpl;
	
    String m_sInstanceName;
    String m_sType;
	StateEnum m_stmdischargingstation;
public:
	void TransitionProc(TransitionEnum transition, Signal* signal, StateData* submachineState);

	
	void occupied__TO__dischargingStationfinished_195_effect(Signal* signal);
	void occupied__TO__dischargingStationfinished_195(Signal* signal, StateData* submachineState);
	void empty__TO__occupied_197_effect(Signal* signal);
	void empty__TO__occupied_197(Signal* signal, StateData* submachineState);
	void stopActordeactivated__TO__empty_206_effect(Signal* signal);
	void stopActordeactivated__TO__empty_206(Signal* signal, StateData* submachineState);
	void waitingAreaemtpy__TO__stopActordeactivated_222_effect(Signal* signal);
	void waitingAreaemtpy__TO__stopActordeactivated_222(Signal* signal, StateData* submachineState);
	void initial_820_820__TO__empty_200_effect(Signal* signal);
	void initial_820_820__TO__empty_200(Signal* signal, StateData* submachineState);
	void dischargingStationfinished__TO__waitingAreaemtpy_221_effect(Signal* signal);
	void dischargingStationfinished__TO__waitingAreaemtpy_221(Signal* signal, StateData* submachineState);
	
	bool StateProc(StateEnum state, StateData* submachineState, StateBehaviorEnum behavior, Signal* signal, EntryTypeEnum enumEntryType = DefaultEntry, EntryEnum entryArray[] = NULL, int nArrayCount = 0);

	
	bool stmDischargingStation_stopActordeactivated(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmDischargingStation_stopActordeactivated_behavior(StateBehaviorEnum behavior);
	bool stmDischargingStation_empty(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmDischargingStation_empty_behavior(StateBehaviorEnum behavior);
	bool stmDischargingStation_dischargingStationfinished(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmDischargingStation_dischargingStationfinished_behavior(StateBehaviorEnum behavior);
	bool stmDischargingStation_waitingAreaemtpy(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmDischargingStation_waitingAreaemtpy_behavior(StateBehaviorEnum behavior);
	bool stmDischargingStation_occupied(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmDischargingStation_occupied_behavior(StateBehaviorEnum behavior);
	
	virtual void runStateMachines() ;
	virtual void runStateMachine(String statemachine);
	virtual void runStateMachine(StateMachineEnum statemachine);
	virtual void runStateMachine(StateMachineEnum statemachine, StateData* submachineState, Signal* signal, EntryEnum entryArray[] = NULL, int nEntryCount = 0);
	virtual bool StateProc(int state, StateData* submachineState, StateBehaviorEnum behavior, Signal* signal, EntryTypeEnum enumEntryType, int entryArray[], int nArrayCount);
	virtual bool dispatch(Event* event, StateData* toState, bool bCheckOnly);
	
	virtual bool defer(Event* event, StateData* toState, bool bCheckOnly);
	
	virtual String GetInstanceName();
	virtual String GetTypeName();




	/* End - EA generated code for StateMachine */

};
#endif // !defined(EA_F0F9718E_340D_4d12_83AB_A1A6D13EF606__INCLUDED_)
