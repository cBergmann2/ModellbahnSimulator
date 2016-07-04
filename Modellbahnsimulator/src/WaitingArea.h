///////////////////////////////////////////////////////////
//  WaitingArea.h
//  Implementation of the Class WaitingArea
//  Created on:      04-Jul-2016 09:47:47
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_DE57F2FC_27AF_4922_8B4A_F14A1A88B272__INCLUDED_)
#define EA_DE57F2FC_27AF_4922_8B4A_F14A1A88B272__INCLUDED_

#include ""
#include "Station.h"

class WaitingArea : public Station , public StateMachineContext
{

	/* Begin - EA generated code for StateMachine */






public:
	enum StateMachineEnum 
	{
		NOSTATEMACHINE,
		WaitingArea_ENUM_STMWAITINGAREA
	};

	enum StateEnum 
	{
		NOSTATE,
		WaitingArea_VIRTUAL_SUBMACHINESTATE,
		WaitingArea_ENUM_STMWAITINGAREA_STOPACTORDEACTIVATED,
		WaitingArea_ENUM_STMWAITINGAREA_EMPTY,
		WaitingArea_ENUM_STMWAITINGAREA_SCALESEMPTY,
		WaitingArea_ENUM_STMWAITINGAREA_OCCUPIED
	};

	enum TransitionEnum 
	{
		NOTRANSITION,
		WaitingArea_ENUM_SCALESEMPTY__TO__STOPACTORDEACTIVATED_214,
		WaitingArea_ENUM_OCCUPIED__TO__SCALESEMPTY_215,
		WaitingArea_ENUM_INITIAL_828__TO__EMPTY_225,
		WaitingArea_ENUM_STOPACTORDEACTIVATED__TO__EMPTY_224,
		WaitingArea_ENUM_EMPTY__TO__OCCUPIED_223
	};

	enum EntryEnum
	{
		NOENTRY,
		WaitingArea_ENUM_STMWAITINGAREA_INITIAL_828
	};

	WaitingArea();
	WaitingArea(ContextManager* pManager, String sInstanceName);
	
	virtual ~WaitingArea();
	
	StateMachineImpl* m_StateMachineImpl;
	
    String m_sInstanceName;
    String m_sType;
	StateEnum m_stmwaitingarea;
public:
	void TransitionProc(TransitionEnum transition, Signal* signal, StateData* submachineState);

	
	void Scalesempty__TO__stopActordeactivated_214_effect(Signal* signal);
	void Scalesempty__TO__stopActordeactivated_214(Signal* signal, StateData* submachineState);
	void occupied__TO__Scalesempty_215_effect(Signal* signal);
	void occupied__TO__Scalesempty_215(Signal* signal, StateData* submachineState);
	void Initial_828__TO__empty_225_effect(Signal* signal);
	void Initial_828__TO__empty_225(Signal* signal, StateData* submachineState);
	void stopActordeactivated__TO__empty_224_effect(Signal* signal);
	void stopActordeactivated__TO__empty_224(Signal* signal, StateData* submachineState);
	void empty__TO__occupied_223_effect(Signal* signal);
	void empty__TO__occupied_223(Signal* signal, StateData* submachineState);
	
	bool StateProc(StateEnum state, StateData* submachineState, StateBehaviorEnum behavior, Signal* signal, EntryTypeEnum enumEntryType = DefaultEntry, EntryEnum entryArray[] = NULL, int nArrayCount = 0);

	
	bool stmWaitingArea_stopActordeactivated(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmWaitingArea_stopActordeactivated_behavior(StateBehaviorEnum behavior);
	bool stmWaitingArea_empty(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmWaitingArea_empty_behavior(StateBehaviorEnum behavior);
	bool stmWaitingArea_Scalesempty(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmWaitingArea_Scalesempty_behavior(StateBehaviorEnum behavior);
	bool stmWaitingArea_occupied(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmWaitingArea_occupied_behavior(StateBehaviorEnum behavior);
	
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
#endif // !defined(EA_DE57F2FC_27AF_4922_8B4A_F14A1A88B272__INCLUDED_)
