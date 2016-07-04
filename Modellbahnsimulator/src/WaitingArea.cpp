///////////////////////////////////////////////////////////
//  WaitingArea.cpp
//  Implementation of the Class WaitingArea
//  Created on:      04-Jul-2016 09:47:47
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "WaitingArea.h"

using namespace std;
/* Begin - EA generated code for StateMachine */








WaitingArea::WaitingArea()
{
	m_StateMachineImpl = NULL;
}

WaitingArea::WaitingArea(ContextManager* pManager, String sInstanceName)
{
	//Initialize Region Variables
	m_stmwaitingarea = NOSTATE;
    m_sInstanceName = sInstanceName;
    m_sType = "WaitingArea";
	m_StateMachineImpl = new StateMachineImpl(this, pManager);
}

WaitingArea::~WaitingArea()
{
	if (m_StateMachineImpl)
	{
		delete m_StateMachineImpl;
	}
}

bool WaitingArea::defer(Event* event, StateData* toState, bool bCheckOnly)
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


void WaitingArea::TransitionProc(TransitionEnum transition, Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	switch (transition) {
		case WaitingArea_ENUM_SCALESEMPTY__TO__STOPACTORDEACTIVATED_214:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "WaitingArea_Scalesempty__TO__stopActordeactivated_214", "{EA45AFF5-28C9-47bd-BF43-AC75B0EDCB6F}", "{D5013893-1C5C-4790-8B95-9B5F9D45AE1E}");
			Scalesempty__TO__stopActordeactivated_214(signal, submachineState); 
			break;

		case WaitingArea_ENUM_OCCUPIED__TO__SCALESEMPTY_215:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "WaitingArea_occupied__TO__Scalesempty_215", "{6842B7DE-DDCC-481f-8BBC-4C2C56FD6330}", "{BE9F8419-8AFA-4197-9E62-5861EA75A266}");
			occupied__TO__Scalesempty_215(signal, submachineState); 
			break;

		case WaitingArea_ENUM_INITIAL_828__TO__EMPTY_225:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "WaitingArea_Initial_828__TO__empty_225", "{E4E9F882-9CD2-4445-8851-E43491366868}", "{99FA1C9F-958B-40df-984D-9D2E0AAB8BE7}");
			Initial_828__TO__empty_225(signal, submachineState); 
			break;

		case WaitingArea_ENUM_STOPACTORDEACTIVATED__TO__EMPTY_224:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "WaitingArea_stopActordeactivated__TO__empty_224", "{4FA445B4-03F7-49cc-A81A-DB91A5C44E71}", "{99FA1C9F-958B-40df-984D-9D2E0AAB8BE7}");
			stopActordeactivated__TO__empty_224(signal, submachineState); 
			break;

		case WaitingArea_ENUM_EMPTY__TO__OCCUPIED_223:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "WaitingArea_empty__TO__occupied_223", "{A4AE0D5B-DB3F-4d47-BA5C-DD6D74385F94}", "{3BB10644-49D5-4c82-9BCD-17BDAA893696}");
			empty__TO__occupied_223(signal, submachineState); 
			break;
	}
	m_StateMachineImpl->currentTransition.SetTransition(NOTRANSITION, NULL, "NOTRANSITION", "", "");
}

void WaitingArea::Scalesempty__TO__stopActordeactivated_214_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "Scalesempty__TO__stopActordeactivated_214 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void WaitingArea::Scalesempty__TO__stopActordeactivated_214(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, WaitingArea_ENUM_STMWAITINGAREA_SCALESEMPTY)->IsActiveState())
	{
		return;
	}
	StateProc(WaitingArea_ENUM_STMWAITINGAREA_SCALESEMPTY, submachineState, EXIT, 0);
	Scalesempty__TO__stopActordeactivated_214_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(WaitingArea_ENUM_STMWAITINGAREA_STOPACTORDEACTIVATED, submachineState, ENTRY, signal, DefaultEntry);
}

void WaitingArea::occupied__TO__Scalesempty_215_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "occupied__TO__Scalesempty_215 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void WaitingArea::occupied__TO__Scalesempty_215(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, WaitingArea_ENUM_STMWAITINGAREA_OCCUPIED)->IsActiveState())
	{
		return;
	}
	StateProc(WaitingArea_ENUM_STMWAITINGAREA_OCCUPIED, submachineState, EXIT, 0);
	occupied__TO__Scalesempty_215_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(WaitingArea_ENUM_STMWAITINGAREA_SCALESEMPTY, submachineState, ENTRY, signal, DefaultEntry);
}

void WaitingArea::Initial_828__TO__empty_225_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "Initial_828__TO__empty_225 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void WaitingArea::Initial_828__TO__empty_225(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(submachineState)
		submachineState->IncrementActiveCount();
	Initial_828__TO__empty_225_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(WaitingArea_ENUM_STMWAITINGAREA_EMPTY, submachineState, ENTRY, signal, DefaultEntry);
}

void WaitingArea::stopActordeactivated__TO__empty_224_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "stopActordeactivated__TO__empty_224 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void WaitingArea::stopActordeactivated__TO__empty_224(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, WaitingArea_ENUM_STMWAITINGAREA_STOPACTORDEACTIVATED)->IsActiveState())
	{
		return;
	}
	StateProc(WaitingArea_ENUM_STMWAITINGAREA_STOPACTORDEACTIVATED, submachineState, EXIT, 0);
	stopActordeactivated__TO__empty_224_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(WaitingArea_ENUM_STMWAITINGAREA_EMPTY, submachineState, ENTRY, signal, DefaultEntry);
}

void WaitingArea::empty__TO__occupied_223_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "empty__TO__occupied_223 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void WaitingArea::empty__TO__occupied_223(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, WaitingArea_ENUM_STMWAITINGAREA_EMPTY)->IsActiveState())
	{
		return;
	}
	StateProc(WaitingArea_ENUM_STMWAITINGAREA_EMPTY, submachineState, EXIT, 0);
	empty__TO__occupied_223_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(WaitingArea_ENUM_STMWAITINGAREA_OCCUPIED, submachineState, ENTRY, signal, DefaultEntry);
}

bool WaitingArea::StateProc(int state, StateData* submachineState, StateBehaviorEnum behavior, Signal* signal, EntryTypeEnum enumEntryType, int entryArray[], int nArrayCount) 
{
	EntryEnum entryEnumArray[MAX_STATES];
	for(int i = 0; i < nArrayCount; i++)
	{
		entryEnumArray[i] = (EntryEnum)entryArray[i];
	}
	
	return StateProc((StateEnum)state, submachineState, behavior, signal, enumEntryType, entryEnumArray, nArrayCount);
}
bool WaitingArea::StateProc(StateEnum state, StateData* submachineState, StateBehaviorEnum behavior, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount) 
{
	switch (state) {
		case WaitingArea_ENUM_STMWAITINGAREA_STOPACTORDEACTIVATED:
			return stmWaitingArea_stopActordeactivated(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case WaitingArea_ENUM_STMWAITINGAREA_EMPTY:
			return stmWaitingArea_empty(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case WaitingArea_ENUM_STMWAITINGAREA_SCALESEMPTY:
			return stmWaitingArea_Scalesempty(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case WaitingArea_ENUM_STMWAITINGAREA_OCCUPIED:
			return stmWaitingArea_occupied(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);
	}
	return false;
}

bool WaitingArea::stmWaitingArea_stopActordeactivated(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, WaitingArea_ENUM_STMWAITINGAREA_STOPACTORDEACTIVATED);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmwaitingarea = WaitingArea_ENUM_STMWAITINGAREA_STOPACTORDEACTIVATED;
			state->IncrementActiveCount();
			stmWaitingArea_stopActordeactivated_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmWaitingArea_stopActordeactivated_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmwaitingarea = NOSTATE;
			state->DecrementActiveCount();
			stmWaitingArea_stopActordeactivated_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool WaitingArea::stmWaitingArea_stopActordeactivated_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_stopActordeactivated " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_stopActordeactivated " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_stopActordeactivated " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool WaitingArea::stmWaitingArea_empty(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, WaitingArea_ENUM_STMWAITINGAREA_EMPTY);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmwaitingarea = WaitingArea_ENUM_STMWAITINGAREA_EMPTY;
			state->IncrementActiveCount();
			stmWaitingArea_empty_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmWaitingArea_empty_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmwaitingarea = NOSTATE;
			state->DecrementActiveCount();
			stmWaitingArea_empty_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool WaitingArea::stmWaitingArea_empty_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_empty " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_empty " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_empty " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool WaitingArea::stmWaitingArea_Scalesempty(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, WaitingArea_ENUM_STMWAITINGAREA_SCALESEMPTY);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmwaitingarea = WaitingArea_ENUM_STMWAITINGAREA_SCALESEMPTY;
			state->IncrementActiveCount();
			stmWaitingArea_Scalesempty_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmWaitingArea_Scalesempty_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmwaitingarea = NOSTATE;
			state->DecrementActiveCount();
			stmWaitingArea_Scalesempty_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool WaitingArea::stmWaitingArea_Scalesempty_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_Scalesempty " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_Scalesempty " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_Scalesempty " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool WaitingArea::stmWaitingArea_occupied(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, WaitingArea_ENUM_STMWAITINGAREA_OCCUPIED);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmwaitingarea = WaitingArea_ENUM_STMWAITINGAREA_OCCUPIED;
			state->IncrementActiveCount();
			stmWaitingArea_occupied_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmWaitingArea_occupied_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmwaitingarea = NOSTATE;
			state->DecrementActiveCount();
			stmWaitingArea_occupied_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool WaitingArea::stmWaitingArea_occupied_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_occupied " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_occupied " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmWaitingArea_occupied " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool WaitingArea::dispatch(Event* event, StateData* toState, bool bCheckOnly) 
{
	if (!m_StateMachineImpl)
		return false;
	
	
	bool bDispatched = false;
	
	if(!toState || !toState->IsActiveState() && !bCheckOnly)
		return bDispatched;
	
	switch (toState->state_enum) {
		case WaitingArea_VIRTUAL_SUBMACHINESTATE:
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
		case WaitingArea_ENUM_STMWAITINGAREA_STOPACTORDEACTIVATED:
	
			switch (event->eventEnum) {
		
				case COMPLETION:
					if(presence sensor exit triggered) {
						if(!bCheckOnly)
							TransitionProc(WaitingArea_ENUM_STOPACTORDEACTIVATED__TO__EMPTY_224, 0, toState->submachine_state);
						bDispatched = true;
						break;
					}
		
			}
	
			break;
		case WaitingArea_ENUM_STMWAITINGAREA_EMPTY:
	
			switch (event->eventEnum) {
		
				case COMPLETION:
					if(presence sensor entry triggered) {
						if(!bCheckOnly)
							TransitionProc(WaitingArea_ENUM_EMPTY__TO__OCCUPIED_223, 0, toState->submachine_state);
						bDispatched = true;
						break;
					}
		
			}
	
			break;
		case WaitingArea_ENUM_STMWAITINGAREA_SCALESEMPTY:
	
			switch (event->eventEnum) {
		
				case COMPLETION:
					if(take semaphore pathSection successful) {
						if(!bCheckOnly)
							TransitionProc(WaitingArea_ENUM_SCALESEMPTY__TO__STOPACTORDEACTIVATED_214, 0, toState->submachine_state);
						bDispatched = true;
						break;
					}
		
			}
	
			break;
		case WaitingArea_ENUM_STMWAITINGAREA_OCCUPIED:
	
			switch (event->eventEnum) {
		
				case COMPLETION:
					if(take semaphore scales successful) {
						if(!bCheckOnly)
							TransitionProc(WaitingArea_ENUM_OCCUPIED__TO__SCALESEMPTY_215, 0, toState->submachine_state);
						bDispatched = true;
						break;
					}
		
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

void WaitingArea::runStateMachine(StateMachineEnum statemachine) 
{
	if (!m_StateMachineImpl)
		return;
	
	list<StateData*> activeStateArray;
	if(m_StateMachineImpl->GetCurrentStates(activeStateArray) > 0)
		return;
	
	switch (statemachine) {
		case WaitingArea_ENUM_STMWAITINGAREA:
			{
				const int nArrayCount = 1;
				EntryEnum entryArray[nArrayCount] = {WaitingArea_ENUM_STMWAITINGAREA_INITIAL_828};
				runStateMachine(statemachine, NULL, 0, entryArray, nArrayCount);	//submachineState is NULL if run standalone statemachine 
			}
			break;
	}
}

void WaitingArea::runStateMachines()
{
	runStateMachine(WaitingArea_ENUM_STMWAITINGAREA);
}

void WaitingArea::runStateMachine(String statemachine)
{
	if(statemachine == "WaitingArea_stmWaitingArea")
	{
		runStateMachine(WaitingArea_ENUM_STMWAITINGAREA);
		return;
	}
}

void WaitingArea::runStateMachine(StateMachineEnum statemachine, StateData* submachineState, Signal* signal, EntryEnum entryArray[], int nEntryCount) 
{
	if(!submachineState)
	{
		StateInitialData initialData(WaitingArea_VIRTUAL_SUBMACHINESTATE, NOSTATE, 1, false, "WaitingArea_VIRTUAL_SUBMACHINESTATE", ""); 
		submachineState = new StateData(m_StateMachineImpl, &initialData);
		
		submachineState->IncrementActiveCount();
		m_StateMachineImpl->lstStateData.push_back(submachineState);
	}
	switch (statemachine) {
		case WaitingArea_ENUM_STMWAITINGAREA:
			{
				const int nArrayCount = 4;
				StateInitialData initialDataArray[nArrayCount] = 
					{
						StateInitialData(WaitingArea_ENUM_STMWAITINGAREA_STOPACTORDEACTIVATED, NOSTATE, 0, false, "WaitingArea_stmWaitingArea_stopActordeactivated", "{D5013893-1C5C-4790-8B95-9B5F9D45AE1E}"),
						StateInitialData(WaitingArea_ENUM_STMWAITINGAREA_EMPTY, NOSTATE, 0, false, "WaitingArea_stmWaitingArea_empty", "{99FA1C9F-958B-40df-984D-9D2E0AAB8BE7}"),
						StateInitialData(WaitingArea_ENUM_STMWAITINGAREA_SCALESEMPTY, NOSTATE, 0, false, "WaitingArea_stmWaitingArea_Scalesempty", "{BE9F8419-8AFA-4197-9E62-5861EA75A266}"),
						StateInitialData(WaitingArea_ENUM_STMWAITINGAREA_OCCUPIED, NOSTATE, 0, false, "WaitingArea_stmWaitingArea_occupied", "{3BB10644-49D5-4c82-9BCD-17BDAA893696}")
					};
		
				m_StateMachineImpl->CreateStateObjects(initialDataArray, nArrayCount, submachineState);
			}
			for(int i = 0; i < nEntryCount; i++)
			{
				switch(entryArray[i])
				{
				case WaitingArea_ENUM_STMWAITINGAREA_INITIAL_828:
					TransitionProc(WaitingArea_ENUM_INITIAL_828__TO__EMPTY_225, signal, submachineState);
					break;
				}
			}
			if(submachineState->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, submachineState);
			break;
	}
}

String WaitingArea::GetInstanceName()
{
	return m_sInstanceName;
}

String WaitingArea::GetTypeName()
{
	return m_sType;
}







/* End - EA generated code for StateMachine */