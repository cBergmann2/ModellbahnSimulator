///////////////////////////////////////////////////////////
//  Scales.h
//  Implementation of the Class Scales
//  Created on:      04-Jul-2016 09:47:38
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#if !defined(EA_3C335383_6EA5_4015_9842_385D47134873__INCLUDED_)
#define EA_3C335383_6EA5_4015_9842_385D47134873__INCLUDED_

#include ""
#include "Station.h"
#include "PathSection.h"

class Scales : public Station , public StateMachineContext
{

public:
	PathSection *m_PathSection;

	PathSection getPathSectionToStartArea();
	double scalingProcedure();
	void taskBehavior();

	/* Begin - EA generated code for Parts and Ports */

	PathSection  ;

	/* End - EA generated code for Parts and Ports */

	/* Begin - EA generated code for Activities and Interactions */

	void taskBehavior();


	/* End - EA generated code for Activities and Interactions */

	/* Begin - EA generated code for StateMachine */






public:
	enum StateMachineEnum 
	{
		NOSTATEMACHINE,
		Scales_ENUM_STMSCALES
	};

	enum StateEnum 
	{
		NOSTATE,
		Scales_VIRTUAL_SUBMACHINESTATE,
		Scales_ENUM_STMSCALES_SCALESFINISHED,
		Scales_ENUM_STMSCALES_SCALEUNLOADEDVEHICLE,
		Scales_ENUM_STMSCALES_ATLEASTONEDISCHARGINGAREAEMPTY,
		Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED,
		Scales_ENUM_STMSCALES_PATHSECTIONEMTPY,
		Scales_ENUM_STMSCALES_SCALESFINISHED,
		Scales_ENUM_STMSCALES_EMTPY,
		Scales_ENUM_STMSCALES_PATHSECTIONEMPTY,
		Scales_ENUM_STMSCALES_SCALELOADEDVEHICLE,
		Scales_ENUM_STMSCALES_INIT,
		Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED
	};

	enum TransitionEnum 
	{
		NOTRANSITION,
		Scales_ENUM_ATLEASTONEDISCHARGINGAREAEMPTY__TO__STOPACTORDEACTIVATED_196,
		Scales_ENUM_PATHSECTIONEMTPY__TO__STOPACTORDEACTIVATED_230,
		Scales_ENUM_SCALESFINISHED__TO__PATHSECTIONEMTPY_243,
		Scales_ENUM_EMTPY__TO__SCALEUNLOADEDVEHICLE_219,
		Scales_ENUM_INITIAL_833__TO__INIT_198,
		Scales_ENUM_SCALEUNLOADEDVEHICLE__TO__SCALESFINISHED_242,
		Scales_ENUM_INIT__TO__EMTPY_220,
		Scales_ENUM_PATHSECTIONEMPTY__TO__STOPACTORDEACTIVATED_203,
		Scales_ENUM_STOPACTORDEACTIVATED__TO__EMTPY_216,
		Scales_ENUM_EMTPY__TO__SCALELOADEDVEHICLE_218,
		Scales_ENUM_STOPACTORDEACTIVATED__TO__EMTPY_217,
		Scales_ENUM_SCALESFINISHED__TO__ATLEASTONEDISCHARGINGAREAEMPTY_228,
		Scales_ENUM_SCALELOADEDVEHICLE__TO__SCALESFINISHED_229
	};

	enum EntryEnum
	{
		NOENTRY,
		Scales_ENUM_STMSCALES_INITIAL_833
	};

	Scales();
	Scales(ContextManager* pManager, String sInstanceName);
	
	virtual ~Scales();
	
	StateMachineImpl* m_StateMachineImpl;
	
    String m_sInstanceName;
    String m_sType;
	StateEnum m_stmscales;
public:
	void TransitionProc(TransitionEnum transition, Signal* signal, StateData* submachineState);

	
	void atleastonedischargingAreaempty__TO__stopActordeactivated_196_effect(Signal* signal);
	void atleastonedischargingAreaempty__TO__stopActordeactivated_196(Signal* signal, StateData* submachineState);
	void pathsectionemtpy__TO__stopActordeactivated_230_effect(Signal* signal);
	void pathsectionemtpy__TO__stopActordeactivated_230(Signal* signal, StateData* submachineState);
	void scalesfinished__TO__pathsectionemtpy_243_effect(Signal* signal);
	void scalesfinished__TO__pathsectionemtpy_243(Signal* signal, StateData* submachineState);
	void emtpy__TO__scaleunloadedvehicle_219_effect(Signal* signal);
	void emtpy__TO__scaleunloadedvehicle_219(Signal* signal, StateData* submachineState);
	void Initial_833__TO__Init_198_effect(Signal* signal);
	void Initial_833__TO__Init_198(Signal* signal, StateData* submachineState);
	void scaleunloadedvehicle__TO__scalesfinished_242_effect(Signal* signal);
	void scaleunloadedvehicle__TO__scalesfinished_242(Signal* signal, StateData* submachineState);
	void Init__TO__emtpy_220_effect(Signal* signal);
	void Init__TO__emtpy_220(Signal* signal, StateData* submachineState);
	void pathSectionempty__TO__stopActordeactivated_203_effect(Signal* signal);
	void pathSectionempty__TO__stopActordeactivated_203(Signal* signal, StateData* submachineState);
	void stopActordeactivated__TO__emtpy_216_effect(Signal* signal);
	void stopActordeactivated__TO__emtpy_216(Signal* signal, StateData* submachineState);
	void emtpy__TO__scaleloadedvehicle_218_effect(Signal* signal);
	void emtpy__TO__scaleloadedvehicle_218(Signal* signal, StateData* submachineState);
	void stopActordeactivated__TO__emtpy_217_effect(Signal* signal);
	void stopActordeactivated__TO__emtpy_217(Signal* signal, StateData* submachineState);
	void scalesfinished__TO__atleastonedischargingAreaempty_228_effect(Signal* signal);
	void scalesfinished__TO__atleastonedischargingAreaempty_228(Signal* signal, StateData* submachineState);
	void scaleloadedvehicle__TO__scalesfinished_229_effect(Signal* signal);
	void scaleloadedvehicle__TO__scalesfinished_229(Signal* signal, StateData* submachineState);
	
	bool StateProc(StateEnum state, StateData* submachineState, StateBehaviorEnum behavior, Signal* signal, EntryTypeEnum enumEntryType = DefaultEntry, EntryEnum entryArray[] = NULL, int nArrayCount = 0);

	
	bool stmScales_scalesfinished(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmScales_scalesfinished_behavior(StateBehaviorEnum behavior);
	bool stmScales_scaleunloadedvehicle(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmScales_scaleunloadedvehicle_behavior(StateBehaviorEnum behavior);
	bool stmScales_atleastonedischargingAreaempty(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmScales_atleastonedischargingAreaempty_behavior(StateBehaviorEnum behavior);
	bool stmScales_stopActordeactivated(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmScales_stopActordeactivated_behavior(StateBehaviorEnum behavior);
	bool stmScales_pathsectionemtpy(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmScales_pathsectionemtpy_behavior(StateBehaviorEnum behavior);
	bool stmScales_scalesfinished(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmScales_scalesfinished_behavior(StateBehaviorEnum behavior);
	bool stmScales_emtpy(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmScales_emtpy_behavior(StateBehaviorEnum behavior);
	bool stmScales_pathSectionempty(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmScales_pathSectionempty_behavior(StateBehaviorEnum behavior);
	bool stmScales_scaleloadedvehicle(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmScales_scaleloadedvehicle_behavior(StateBehaviorEnum behavior);
	bool stmScales_Init(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmScales_Init_behavior(StateBehaviorEnum behavior);
	bool stmScales_stopActordeactivated(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount);
	bool stmScales_stopActordeactivated_behavior(StateBehaviorEnum behavior);
	
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
#endif // !defined(EA_3C335383_6EA5_4015_9842_385D47134873__INCLUDED_)
