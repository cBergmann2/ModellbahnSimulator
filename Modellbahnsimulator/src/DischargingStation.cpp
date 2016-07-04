///////////////////////////////////////////////////////////
//  DischargingStation.cpp
//  Implementation of the Class DischargingStation
//  Created on:      04-Jul-2016 09:47:34
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "DischargingStation.h"

using namespace std;



DischargingStation::dischargingProcedure(){

}


ThreeWaySwitch DischargingStation::getThreeWaySwitch(){

	return  NULL;
}


void DischargingStation::taskBehavior(){

}


/* Begin - EA generated code for Activities and Interactions */


void DischargingStation::taskBehavior()
{
	// behavior is a Interaction
	unblockPathSection(0);
	if (station == 3)
	{
		unblockPathSection(1);
	}
	startDischargingProcess(this.stationID);
	occupieStation();
	if (station == 1 || station == 2)
	{
		occupiePathSection(1);
		setPosition(2);
		if (station == 1)
		{
			setStopActor(DischargingStation_1,false);
			setStopActor(DischargingStation_1,true);
		}
		else if (station == 2)
		{
			setStopActor(DischargingStation_2,false);
			setStopActor(DischargingStation_2,true);
		}
	}
	else if (station == 3)
	{
		occupiePathSection(1);
		setStopActor(DischargingStation_3,false);
		setStopActor(DischargingStation_3,true);
	}
}



/* End - EA generated code for Activities and Interactions */


/* Begin - EA generated code for StateMachine */








DischargingStation::DischargingStation()
{
	m_StateMachineImpl = NULL;
}

DischargingStation::DischargingStation(ContextManager* pManager, String sInstanceName)
{
	//Initialize Region Variables
	m_stmdischargingstation = NOSTATE;
    m_sInstanceName = sInstanceName;
    m_sType = "DischargingStation";
	m_StateMachineImpl = new StateMachineImpl(this, pManager);
}

DischargingStation::~DischargingStation()
{
	if (m_StateMachineImpl)
	{
		delete m_StateMachineImpl;
	}
}

bool DischargingStation::defer(Event* event, StateData* toState, bool bCheckOnly)
{
	if (!m_StateMachineImpl)
		return false;
	
	bool bDefer = false;
	if(event->eventEnum == COMPLETION)
		return bDefer;
		
	if(!bDefer)
	{
		if(toState->parent_state)
		{
			bDefer = defer(event, toState->parent_state, true);
			if(bDefer && !bCheckOnly)
			{
				defer(event, toState->parent_state, false);
			}
		}
	}
	else if(!bCheckOnly)
	{
		bool bExist = false;
		for (list<Event*>::iterator it = m_StateMachineImpl->deferredEvents.begin(); it != m_StateMachineImpl->deferredEvents.end(); it++)
		{
			if((*it) == event)
			{
				bExist = true;
				break;
			}
		}
		if(!bExist)
		{
			m_StateMachineImpl->deferredEvents.push_back(event);
		}
	}
	return bDefer;
}


void DischargingStation::TransitionProc(TransitionEnum transition, Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	switch (transition) {
		case DischargingStation_ENUM_OCCUPIED__TO__DISCHARGINGSTATIONFINISHED_195:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "DischargingStation_occupied__TO__dischargingStationfinished_195", "{9EBA40BD-07D2-4ba9-903F-0DBBC2AB27DD}", "{C3CD3EBC-4673-4ebd-815F-9E1D7714770D}");
			occupied__TO__dischargingStationfinished_195(signal, submachineState); 
			break;

		case DischargingStation_ENUM_EMPTY__TO__OCCUPIED_197:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "DischargingStation_empty__TO__occupied_197", "{D5866227-9220-4f2c-BF2D-3602CF8CDFCE}", "{9F2230A9-D233-41c3-9317-B3A10ECE7FBC}");
			empty__TO__occupied_197(signal, submachineState); 
			break;

		case DischargingStation_ENUM_STOPACTORDEACTIVATED__TO__EMPTY_206:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "DischargingStation_stopActordeactivated__TO__empty_206", "{18475F80-F71D-49e3-8B69-3B5D2711F545}", "{C7E2F208-AE62-49e6-B5A0-FF5C16FA2749}");
			stopActordeactivated__TO__empty_206(signal, submachineState); 
			break;

		case DischargingStation_ENUM_WAITINGAREAEMTPY__TO__STOPACTORDEACTIVATED_222:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "DischargingStation_waitingAreaemtpy__TO__stopActordeactivated_222", "{BCC3E6B0-8E5B-483d-B3AC-976AB2F8462A}", "{A3640BD3-CAD7-48b6-AD8A-340103FAD60F}");
			waitingAreaemtpy__TO__stopActordeactivated_222(signal, submachineState); 
			break;

		case DischargingStation_ENUM_INITIAL_820_820__TO__EMPTY_200:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "DischargingStation_initial_820_820__TO__empty_200", "{CE1314D3-19D5-4d31-955B-BDEB9DB18469}", "{C7E2F208-AE62-49e6-B5A0-FF5C16FA2749}");
			initial_820_820__TO__empty_200(signal, submachineState); 
			break;

		case DischargingStation_ENUM_DISCHARGINGSTATIONFINISHED__TO__WAITINGAREAEMTPY_221:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "DischargingStation_dischargingStationfinished__TO__waitingAreaemtpy_221", "{A5701E72-B590-401a-9803-B9D11D24E1E8}", "{0800599D-C647-445d-98DC-684AF6CE82E4}");
			dischargingStationfinished__TO__waitingAreaemtpy_221(signal, submachineState); 
			break;
	}
	m_StateMachineImpl->currentTransition.SetTransition(NOTRANSITION, NULL, "NOTRANSITION", "", "");
}

void DischargingStation::occupied__TO__dischargingStationfinished_195_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "occupied__TO__dischargingStationfinished_195 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void DischargingStation::occupied__TO__dischargingStationfinished_195(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, DischargingStation_ENUM_STMDISCHARGINGSTATION_OCCUPIED)->IsActiveState())
	{
		return;
	}
	StateProc(DischargingStation_ENUM_STMDISCHARGINGSTATION_OCCUPIED, submachineState, EXIT, 0);
	occupied__TO__dischargingStationfinished_195_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(DischargingStation_ENUM_STMDISCHARGINGSTATION_DISCHARGINGSTATIONFINISHED, submachineState, ENTRY, signal, DefaultEntry);
}

void DischargingStation::empty__TO__occupied_197_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "empty__TO__occupied_197 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void DischargingStation::empty__TO__occupied_197(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, DischargingStation_ENUM_STMDISCHARGINGSTATION_EMPTY)->IsActiveState())
	{
		return;
	}
	StateProc(DischargingStation_ENUM_STMDISCHARGINGSTATION_EMPTY, submachineState, EXIT, 0);
	empty__TO__occupied_197_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(DischargingStation_ENUM_STMDISCHARGINGSTATION_OCCUPIED, submachineState, ENTRY, signal, DefaultEntry);
}

void DischargingStation::stopActordeactivated__TO__empty_206_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "stopActordeactivated__TO__empty_206 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void DischargingStation::stopActordeactivated__TO__empty_206(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, DischargingStation_ENUM_STMDISCHARGINGSTATION_STOPACTORDEACTIVATED)->IsActiveState())
	{
		return;
	}
	StateProc(DischargingStation_ENUM_STMDISCHARGINGSTATION_STOPACTORDEACTIVATED, submachineState, EXIT, 0);
	stopActordeactivated__TO__empty_206_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(DischargingStation_ENUM_STMDISCHARGINGSTATION_EMPTY, submachineState, ENTRY, signal, DefaultEntry);
}

void DischargingStation::waitingAreaemtpy__TO__stopActordeactivated_222_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "waitingAreaemtpy__TO__stopActordeactivated_222 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void DischargingStation::waitingAreaemtpy__TO__stopActordeactivated_222(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, DischargingStation_ENUM_STMDISCHARGINGSTATION_WAITINGAREAEMTPY)->IsActiveState())
	{
		return;
	}
	StateProc(DischargingStation_ENUM_STMDISCHARGINGSTATION_WAITINGAREAEMTPY, submachineState, EXIT, 0);
	waitingAreaemtpy__TO__stopActordeactivated_222_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(DischargingStation_ENUM_STMDISCHARGINGSTATION_STOPACTORDEACTIVATED, submachineState, ENTRY, signal, DefaultEntry);
}

void DischargingStation::initial_820_820__TO__empty_200_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "initial_820_820__TO__empty_200 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void DischargingStation::initial_820_820__TO__empty_200(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(submachineState)
		submachineState->IncrementActiveCount();
	initial_820_820__TO__empty_200_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(DischargingStation_ENUM_STMDISCHARGINGSTATION_EMPTY, submachineState, ENTRY, signal, DefaultEntry);
}

void DischargingStation::dischargingStationfinished__TO__waitingAreaemtpy_221_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "dischargingStationfinished__TO__waitingAreaemtpy_221 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void DischargingStation::dischargingStationfinished__TO__waitingAreaemtpy_221(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, DischargingStation_ENUM_STMDISCHARGINGSTATION_DISCHARGINGSTATIONFINISHED)->IsActiveState())
	{
		return;
	}
	StateProc(DischargingStation_ENUM_STMDISCHARGINGSTATION_DISCHARGINGSTATIONFINISHED, submachineState, EXIT, 0);
	dischargingStationfinished__TO__waitingAreaemtpy_221_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(DischargingStation_ENUM_STMDISCHARGINGSTATION_WAITINGAREAEMTPY, submachineState, ENTRY, signal, DefaultEntry);
}

bool DischargingStation::StateProc(int state, StateData* submachineState, StateBehaviorEnum behavior, Signal* signal, EntryTypeEnum enumEntryType, int entryArray[], int nArrayCount) 
{
	EntryEnum entryEnumArray[MAX_STATES];
	for(int i = 0; i < nArrayCount; i++)
	{
		entryEnumArray[i] = (EntryEnum)entryArray[i];
	}
	
	return StateProc((StateEnum)state, submachineState, behavior, signal, enumEntryType, entryEnumArray, nArrayCount);
}
bool DischargingStation::StateProc(StateEnum state, StateData* submachineState, StateBehaviorEnum behavior, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount) 
{
	switch (state) {
		case DischargingStation_ENUM_STMDISCHARGINGSTATION_STOPACTORDEACTIVATED:
			return stmDischargingStation_stopActordeactivated(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case DischargingStation_ENUM_STMDISCHARGINGSTATION_EMPTY:
			return stmDischargingStation_empty(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case DischargingStation_ENUM_STMDISCHARGINGSTATION_DISCHARGINGSTATIONFINISHED:
			return stmDischargingStation_dischargingStationfinished(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case DischargingStation_ENUM_STMDISCHARGINGSTATION_WAITINGAREAEMTPY:
			return stmDischargingStation_waitingAreaemtpy(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case DischargingStation_ENUM_STMDISCHARGINGSTATION_OCCUPIED:
			return stmDischargingStation_occupied(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);
	}
	return false;
}

bool DischargingStation::stmDischargingStation_stopActordeactivated(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, DischargingStation_ENUM_STMDISCHARGINGSTATION_STOPACTORDEACTIVATED);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmdischargingstation = DischargingStation_ENUM_STMDISCHARGINGSTATION_STOPACTORDEACTIVATED;
			state->IncrementActiveCount();
			stmDischargingStation_stopActordeactivated_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmDischargingStation_stopActordeactivated_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmdischargingstation = NOSTATE;
			state->DecrementActiveCount();
			stmDischargingStation_stopActordeactivated_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool DischargingStation::stmDischargingStation_stopActordeactivated_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_stopActordeactivated " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_stopActordeactivated " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_stopActordeactivated " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool DischargingStation::stmDischargingStation_empty(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, DischargingStation_ENUM_STMDISCHARGINGSTATION_EMPTY);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmdischargingstation = DischargingStation_ENUM_STMDISCHARGINGSTATION_EMPTY;
			state->IncrementActiveCount();
			stmDischargingStation_empty_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmDischargingStation_empty_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmdischargingstation = NOSTATE;
			state->DecrementActiveCount();
			stmDischargingStation_empty_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool DischargingStation::stmDischargingStation_empty_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_empty " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_empty " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_empty " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool DischargingStation::stmDischargingStation_dischargingStationfinished(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, DischargingStation_ENUM_STMDISCHARGINGSTATION_DISCHARGINGSTATIONFINISHED);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmdischargingstation = DischargingStation_ENUM_STMDISCHARGINGSTATION_DISCHARGINGSTATIONFINISHED;
			state->IncrementActiveCount();
			stmDischargingStation_dischargingStationfinished_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmDischargingStation_dischargingStationfinished_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmdischargingstation = NOSTATE;
			state->DecrementActiveCount();
			stmDischargingStation_dischargingStationfinished_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool DischargingStation::stmDischargingStation_dischargingStationfinished_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_dischargingStationfinished " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_dischargingStationfinished " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_dischargingStationfinished " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool DischargingStation::stmDischargingStation_waitingAreaemtpy(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, DischargingStation_ENUM_STMDISCHARGINGSTATION_WAITINGAREAEMTPY);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmdischargingstation = DischargingStation_ENUM_STMDISCHARGINGSTATION_WAITINGAREAEMTPY;
			state->IncrementActiveCount();
			stmDischargingStation_waitingAreaemtpy_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmDischargingStation_waitingAreaemtpy_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmdischargingstation = NOSTATE;
			state->DecrementActiveCount();
			stmDischargingStation_waitingAreaemtpy_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool DischargingStation::stmDischargingStation_waitingAreaemtpy_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_waitingAreaemtpy " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_waitingAreaemtpy " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_waitingAreaemtpy " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool DischargingStation::stmDischargingStation_occupied(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, DischargingStation_ENUM_STMDISCHARGINGSTATION_OCCUPIED);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmdischargingstation = DischargingStation_ENUM_STMDISCHARGINGSTATION_OCCUPIED;
			state->IncrementActiveCount();
			stmDischargingStation_occupied_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmDischargingStation_occupied_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmdischargingstation = NOSTATE;
			state->DecrementActiveCount();
			stmDischargingStation_occupied_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool DischargingStation::stmDischargingStation_occupied_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_occupied " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_occupied " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmDischargingStation_occupied " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool DischargingStation::dispatch(Event* event, StateData* toState, bool bCheckOnly) 
{
	if (!m_StateMachineImpl)
		return false;
	
	
	bool bDispatched = false;
	
	if(!toState || !toState->IsActiveState() && !bCheckOnly)
		return bDispatched;
	
	switch (toState->state_enum) {
		case DischargingStation_VIRTUAL_SUBMACHINESTATE:
			if(event->eventEnum == COMPLETION)
			{
				if(!bCheckOnly)
				{
					m_StateMachineImpl->ReleaseSubmachineState(toState);
					for (list<StateData*>::iterator it = m_StateMachineImpl->lstStateData.begin(); it != m_StateMachineImpl->lstStateData.end(); )
					{
						StateData* state = *it;
						if (state == toState)
						{
							it = m_StateMachineImpl->lstStateData.erase(it);
							break;
						}
						else
							++it;
					}
					delete toState;
					toState = NULL;
				}				
				bDispatched = true;
			}
			break;
		case DischargingStation_ENUM_STMDISCHARGINGSTATION_STOPACTORDEACTIVATED:
	
			switch (event->eventEnum) {
				case ENUM_PRESENCESENSOREXITTRIGGERED:
					if(!bCheckOnly)
						TransitionProc(DischargingStation_ENUM_STOPACTORDEACTIVATED__TO__EMPTY_206, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case DischargingStation_ENUM_STMDISCHARGINGSTATION_EMPTY:
	
			switch (event->eventEnum) {
				case ENUM_PRESENCESENSORENTRYTRIGGERED:
					if(!bCheckOnly)
						TransitionProc(DischargingStation_ENUM_EMPTY__TO__OCCUPIED_197, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case DischargingStation_ENUM_STMDISCHARGINGSTATION_DISCHARGINGSTATIONFINISHED:
	
			switch (event->eventEnum) {
				case ENUM_TAKESEMAPHOREFORWAITINGAREASUCCESSFUL:
					if(!bCheckOnly)
						TransitionProc(DischargingStation_ENUM_DISCHARGINGSTATIONFINISHED__TO__WAITINGAREAEMTPY_221, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case DischargingStation_ENUM_STMDISCHARGINGSTATION_WAITINGAREAEMTPY:
	
			switch (event->eventEnum) {
				case ENUM_TAKESEMAPHOREPATHSECTIONSUCCESSFUL:
					if(!bCheckOnly)
						TransitionProc(DischargingStation_ENUM_WAITINGAREAEMTPY__TO__STOPACTORDEACTIVATED_222, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case DischargingStation_ENUM_STMDISCHARGINGSTATION_OCCUPIED:
	
			switch (event->eventEnum) {
				case ENUM_DISCHARGINGSTATIONFINISHED:
					if(!bCheckOnly)
						TransitionProc(DischargingStation_ENUM_OCCUPIED__TO__DISCHARGINGSTATIONFINISHED_195, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
	}
	
	if(!bDispatched && toState && toState->parent_state && event->eventEnum != COMPLETION)
	{
		bDispatched = dispatch(event, toState->parent_state, true);
		if(bDispatched && !bCheckOnly)
		{
			/*1. Exit the current state; 2. Decrement the active count of the parent state; 3. dispatch the event to parent state*/
			StateProc((StateEnum)toState->state_enum, toState->submachine_state, EXIT, 0);
			toState->parent_state->DecrementActiveCount();
			dispatch(event, toState->parent_state, false);
			event = 0;
		}
	}
	
	return bDispatched;
}

void DischargingStation::runStateMachine(StateMachineEnum statemachine) 
{
	if (!m_StateMachineImpl)
		return;
	
	list<StateData*> activeStateArray;
	if(m_StateMachineImpl->GetCurrentStates(activeStateArray) > 0)
		return;
	
	switch (statemachine) {
		case DischargingStation_ENUM_STMDISCHARGINGSTATION:
			{
				const int nArrayCount = 1;
				EntryEnum entryArray[nArrayCount] = {DischargingStation_ENUM_STMDISCHARGINGSTATION_INITIAL_820_820};
				runStateMachine(statemachine, NULL, 0, entryArray, nArrayCount);	//submachineState is NULL if run standalone statemachine 
			}
			break;
	}
}

void DischargingStation::runStateMachines()
{
	runStateMachine(DischargingStation_ENUM_STMDISCHARGINGSTATION);
}

void DischargingStation::runStateMachine(String statemachine)
{
	if(statemachine == "DischargingStation_stmDischargingStation")
	{
		runStateMachine(DischargingStation_ENUM_STMDISCHARGINGSTATION);
		return;
	}
}

void DischargingStation::runStateMachine(StateMachineEnum statemachine, StateData* submachineState, Signal* signal, EntryEnum entryArray[], int nEntryCount) 
{
	if(!submachineState)
	{
		StateInitialData initialData(DischargingStation_VIRTUAL_SUBMACHINESTATE, NOSTATE, 1, false, "DischargingStation_VIRTUAL_SUBMACHINESTATE", ""); 
		submachineState = new StateData(m_StateMachineImpl, &initialData);
		
		submachineState->IncrementActiveCount();
		m_StateMachineImpl->lstStateData.push_back(submachineState);
	}
	switch (statemachine) {
		case DischargingStation_ENUM_STMDISCHARGINGSTATION:
			{
				const int nArrayCount = 5;
				StateInitialData initialDataArray[nArrayCount] = 
					{
						StateInitialData(DischargingStation_ENUM_STMDISCHARGINGSTATION_STOPACTORDEACTIVATED, NOSTATE, 0, false, "DischargingStation_stmDischargingStation_stopActordeactivated", "{A3640BD3-CAD7-48b6-AD8A-340103FAD60F}"),
						StateInitialData(DischargingStation_ENUM_STMDISCHARGINGSTATION_EMPTY, NOSTATE, 0, false, "DischargingStation_stmDischargingStation_empty", "{C7E2F208-AE62-49e6-B5A0-FF5C16FA2749}"),
						StateInitialData(DischargingStation_ENUM_STMDISCHARGINGSTATION_DISCHARGINGSTATIONFINISHED, NOSTATE, 0, false, "DischargingStation_stmDischargingStation_dischargingStationfinished", "{C3CD3EBC-4673-4ebd-815F-9E1D7714770D}"),
						StateInitialData(DischargingStation_ENUM_STMDISCHARGINGSTATION_WAITINGAREAEMTPY, NOSTATE, 0, false, "DischargingStation_stmDischargingStation_waitingAreaemtpy", "{0800599D-C647-445d-98DC-684AF6CE82E4}"),
						StateInitialData(DischargingStation_ENUM_STMDISCHARGINGSTATION_OCCUPIED, NOSTATE, 0, false, "DischargingStation_stmDischargingStation_occupied", "{9F2230A9-D233-41c3-9317-B3A10ECE7FBC}")
					};
		
				m_StateMachineImpl->CreateStateObjects(initialDataArray, nArrayCount, submachineState);
			}
			for(int i = 0; i < nEntryCount; i++)
			{
				switch(entryArray[i])
				{
				case DischargingStation_ENUM_STMDISCHARGINGSTATION_INITIAL_820_820:
					TransitionProc(DischargingStation_ENUM_INITIAL_820_820__TO__EMPTY_200, signal, submachineState);
					break;
				}
			}
			if(submachineState->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, submachineState);
			break;
	}
}

String DischargingStation::GetInstanceName()
{
	return m_sInstanceName;
}

String DischargingStation::GetTypeName()
{
	return m_sType;
}







/* End - EA generated code for StateMachine */