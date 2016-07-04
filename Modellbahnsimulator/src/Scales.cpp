///////////////////////////////////////////////////////////
//  Scales.cpp
//  Implementation of the Class Scales
//  Created on:      04-Jul-2016 09:47:39
//  Original author: Christoph Bergmann
///////////////////////////////////////////////////////////

#include "Scales.h"

using namespace std;



PathSection Scales::getPathSectionToStartArea(){

	return  NULL;
}


double Scales::scalingProcedure(){

	return 0;
}


void Scales::taskBehavior(){

}


/* Begin - EA generated code for Activities and Interactions */


void Scales::taskBehavior()
{
	// behavior is a Interaction
	startWeighingProcess();
	occupiePlaceInDischargingArea();
	getDischragingStation(1);
	getThreeWaySwitch();
	ds1->occupieStation();
	if (occupieStation() == 0)
	{
		occupieThreeWaySwitch();
		setPosition(1);
	}
	else if (else)
	{
		getDischragingStation(2);
		ds2->occupieStation();
		if (occupieStation() == 0)
		{
			setPosition(3);
		}
		else if (else)
		{
			setPosition(2);
			getTwoWaySwitch();
			setPosition(1);
		}
	}
	setStopActor(Scales,false);
	setStopActor(Scales,true);
	startWeighingProcess();
	setStopActor(Scales,false);
	setStopActor(Scales,true);
}



/* End - EA generated code for Activities and Interactions */


/* Begin - EA generated code for StateMachine */








Scales::Scales()
{
	m_StateMachineImpl = NULL;
}

Scales::Scales(ContextManager* pManager, String sInstanceName)
{
	//Initialize Region Variables
	m_stmscales = NOSTATE;
    m_sInstanceName = sInstanceName;
    m_sType = "Scales";
	m_StateMachineImpl = new StateMachineImpl(this, pManager);
}

Scales::~Scales()
{
	if (m_StateMachineImpl)
	{
		delete m_StateMachineImpl;
	}
}

bool Scales::defer(Event* event, StateData* toState, bool bCheckOnly)
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


void Scales::TransitionProc(TransitionEnum transition, Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	switch (transition) {
		case Scales_ENUM_ATLEASTONEDISCHARGINGAREAEMPTY__TO__STOPACTORDEACTIVATED_196:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_atleastonedischargingAreaempty__TO__stopActordeactivated_196", "{3FA017F2-590C-45c1-ACB3-D623A671F9EB}", "{03E9B9DB-2860-45ab-9344-12A8D6A92000}");
			atleastonedischargingAreaempty__TO__stopActordeactivated_196(signal, submachineState); 
			break;

		case Scales_ENUM_PATHSECTIONEMTPY__TO__STOPACTORDEACTIVATED_230:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_pathsectionemtpy__TO__stopActordeactivated_230", "{C1E22A4F-8760-47f7-AEB0-770AF3B43C32}", "{470FF6F5-9AB1-4972-A508-78B6475D732F}");
			pathsectionemtpy__TO__stopActordeactivated_230(signal, submachineState); 
			break;

		case Scales_ENUM_SCALESFINISHED__TO__PATHSECTIONEMTPY_243:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_scalesfinished__TO__pathsectionemtpy_243", "{D4FE1BA9-E49B-4154-A729-31D3E963BBDA}", "{28F08E14-D8EA-49d2-B1DF-27016DD7EAE9}");
			scalesfinished__TO__pathsectionemtpy_243(signal, submachineState); 
			break;

		case Scales_ENUM_EMTPY__TO__SCALEUNLOADEDVEHICLE_219:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_emtpy__TO__scaleunloadedvehicle_219", "{BFDC17CD-2BDD-4c82-AAED-812BD36B94E5}", "{C098F7B1-F129-4700-9352-CCACA4F0B555}");
			emtpy__TO__scaleunloadedvehicle_219(signal, submachineState); 
			break;

		case Scales_ENUM_INITIAL_833__TO__INIT_198:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_Initial_833__TO__Init_198", "{556F92BE-B87C-4421-9364-D61CF11B4339}", "{E4F42CCA-0509-4f60-87BA-1979EA08F973}");
			Initial_833__TO__Init_198(signal, submachineState); 
			break;

		case Scales_ENUM_SCALEUNLOADEDVEHICLE__TO__SCALESFINISHED_242:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_scaleunloadedvehicle__TO__scalesfinished_242", "{4A605E6E-CFD2-4f72-9BEC-93A12F6817B7}", "{39FF3F98-58FD-49ab-BE64-8A91078AA192}");
			scaleunloadedvehicle__TO__scalesfinished_242(signal, submachineState); 
			break;

		case Scales_ENUM_INIT__TO__EMTPY_220:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_Init__TO__emtpy_220", "{B20F2B07-234C-4038-9856-8BD300AE0400}", "{4686A444-28B3-438e-B9CF-F5CED18AD9E7}");
			Init__TO__emtpy_220(signal, submachineState); 
			break;

		case Scales_ENUM_PATHSECTIONEMPTY__TO__STOPACTORDEACTIVATED_203:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_pathSectionempty__TO__stopActordeactivated_203", "{CBDF8756-A2A9-453b-AFA0-60AD9298788A}", "{03E9B9DB-2860-45ab-9344-12A8D6A92000}");
			pathSectionempty__TO__stopActordeactivated_203(signal, submachineState); 
			break;

		case Scales_ENUM_STOPACTORDEACTIVATED__TO__EMTPY_216:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_stopActordeactivated__TO__emtpy_216", "{852739FC-516B-4aa6-BB39-403FA79371CA}", "{4686A444-28B3-438e-B9CF-F5CED18AD9E7}");
			stopActordeactivated__TO__emtpy_216(signal, submachineState); 
			break;

		case Scales_ENUM_EMTPY__TO__SCALELOADEDVEHICLE_218:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_emtpy__TO__scaleloadedvehicle_218", "{6A76983E-8A6D-4296-9EC4-57855725E43E}", "{D096C08A-F5D9-4e90-86DE-8A4C084F1C9A}");
			emtpy__TO__scaleloadedvehicle_218(signal, submachineState); 
			break;

		case Scales_ENUM_STOPACTORDEACTIVATED__TO__EMTPY_217:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_stopActordeactivated__TO__emtpy_217", "{F29F696F-C19F-4a93-B752-71415A0A7109}", "{4686A444-28B3-438e-B9CF-F5CED18AD9E7}");
			stopActordeactivated__TO__emtpy_217(signal, submachineState); 
			break;

		case Scales_ENUM_SCALESFINISHED__TO__ATLEASTONEDISCHARGINGAREAEMPTY_228:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_scalesfinished__TO__atleastonedischargingAreaempty_228", "{1CF8D332-694F-4184-92DE-DA61506FC8F9}", "{F3ABCAD6-C7E4-4b06-B9DF-5E887D0273FE}");
			scalesfinished__TO__atleastonedischargingAreaempty_228(signal, submachineState); 
			break;

		case Scales_ENUM_SCALELOADEDVEHICLE__TO__SCALESFINISHED_229:
			m_StateMachineImpl->currentTransition.SetTransition(transition, submachineState, "Scales_scaleloadedvehicle__TO__scalesfinished_229", "{7A93511C-84F7-47b2-BAC6-EBE79B682C40}", "{4ACD3DE3-D09C-4926-BB4A-07FEBA22446B}");
			scaleloadedvehicle__TO__scalesfinished_229(signal, submachineState); 
			break;
	}
	m_StateMachineImpl->currentTransition.SetTransition(NOTRANSITION, NULL, "NOTRANSITION", "", "");
}

void Scales::atleastonedischargingAreaempty__TO__stopActordeactivated_196_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "atleastonedischargingAreaempty__TO__stopActordeactivated_196 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::atleastonedischargingAreaempty__TO__stopActordeactivated_196(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_ATLEASTONEDISCHARGINGAREAEMPTY)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_ATLEASTONEDISCHARGINGAREAEMPTY, submachineState, EXIT, 0);
	atleastonedischargingAreaempty__TO__stopActordeactivated_196_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::pathsectionemtpy__TO__stopActordeactivated_230_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "pathsectionemtpy__TO__stopActordeactivated_230 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::pathsectionemtpy__TO__stopActordeactivated_230(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_PATHSECTIONEMTPY)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_PATHSECTIONEMTPY, submachineState, EXIT, 0);
	pathsectionemtpy__TO__stopActordeactivated_230_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::scalesfinished__TO__pathsectionemtpy_243_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "scalesfinished__TO__pathsectionemtpy_243 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::scalesfinished__TO__pathsectionemtpy_243(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_SCALESFINISHED)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_SCALESFINISHED, submachineState, EXIT, 0);
	scalesfinished__TO__pathsectionemtpy_243_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_PATHSECTIONEMTPY, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::emtpy__TO__scaleunloadedvehicle_219_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "emtpy__TO__scaleunloadedvehicle_219 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::emtpy__TO__scaleunloadedvehicle_219(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_EMTPY)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_EMTPY, submachineState, EXIT, 0);
	emtpy__TO__scaleunloadedvehicle_219_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_SCALEUNLOADEDVEHICLE, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::Initial_833__TO__Init_198_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "Initial_833__TO__Init_198 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::Initial_833__TO__Init_198(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(submachineState)
		submachineState->IncrementActiveCount();
	Initial_833__TO__Init_198_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_INIT, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::scaleunloadedvehicle__TO__scalesfinished_242_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "scaleunloadedvehicle__TO__scalesfinished_242 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::scaleunloadedvehicle__TO__scalesfinished_242(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_SCALEUNLOADEDVEHICLE)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_SCALEUNLOADEDVEHICLE, submachineState, EXIT, 0);
	scaleunloadedvehicle__TO__scalesfinished_242_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_SCALESFINISHED, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::Init__TO__emtpy_220_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "Init__TO__emtpy_220 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::Init__TO__emtpy_220(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_INIT)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_INIT, submachineState, EXIT, 0);
	Init__TO__emtpy_220_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_EMTPY, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::pathSectionempty__TO__stopActordeactivated_203_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "pathSectionempty__TO__stopActordeactivated_203 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::pathSectionempty__TO__stopActordeactivated_203(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_PATHSECTIONEMPTY)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_PATHSECTIONEMPTY, submachineState, EXIT, 0);
	pathSectionempty__TO__stopActordeactivated_203_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::stopActordeactivated__TO__emtpy_216_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "stopActordeactivated__TO__emtpy_216 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::stopActordeactivated__TO__emtpy_216(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED, submachineState, EXIT, 0);
	stopActordeactivated__TO__emtpy_216_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_EMTPY, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::emtpy__TO__scaleloadedvehicle_218_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "emtpy__TO__scaleloadedvehicle_218 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::emtpy__TO__scaleloadedvehicle_218(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_EMTPY)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_EMTPY, submachineState, EXIT, 0);
	emtpy__TO__scaleloadedvehicle_218_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_SCALELOADEDVEHICLE, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::stopActordeactivated__TO__emtpy_217_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "stopActordeactivated__TO__emtpy_217 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::stopActordeactivated__TO__emtpy_217(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED, submachineState, EXIT, 0);
	stopActordeactivated__TO__emtpy_217_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_EMTPY, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::scalesfinished__TO__atleastonedischargingAreaempty_228_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "scalesfinished__TO__atleastonedischargingAreaempty_228 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::scalesfinished__TO__atleastonedischargingAreaempty_228(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_SCALESFINISHED)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_SCALESFINISHED, submachineState, EXIT, 0);
	scalesfinished__TO__atleastonedischargingAreaempty_228_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_ATLEASTONEDISCHARGINGAREAEMPTY, submachineState, ENTRY, signal, DefaultEntry);
}

void Scales::scaleloadedvehicle__TO__scalesfinished_229_effect(Signal* signal)
{
	StringStream ss;
	ss << m_sInstanceName << "[" << m_sType << "]." << "scaleloadedvehicle__TO__scalesfinished_229 " << "Effect" << endl;
	GlobalFuncs::trace(ss.str());
	
}

void Scales::scaleloadedvehicle__TO__scalesfinished_229(Signal* signal, StateData* submachineState) 
{
	if (!m_StateMachineImpl)
		return;
	
	if(!m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_SCALELOADEDVEHICLE)->IsActiveState())
	{
		return;
	}
	StateProc(Scales_ENUM_STMSCALES_SCALELOADEDVEHICLE, submachineState, EXIT, 0);
	scaleloadedvehicle__TO__scalesfinished_229_effect(signal);
	m_StateMachineImpl->currentTransition.SetActive(m_StateMachineImpl);
	StateProc(Scales_ENUM_STMSCALES_SCALESFINISHED, submachineState, ENTRY, signal, DefaultEntry);
}

bool Scales::StateProc(int state, StateData* submachineState, StateBehaviorEnum behavior, Signal* signal, EntryTypeEnum enumEntryType, int entryArray[], int nArrayCount) 
{
	EntryEnum entryEnumArray[MAX_STATES];
	for(int i = 0; i < nArrayCount; i++)
	{
		entryEnumArray[i] = (EntryEnum)entryArray[i];
	}
	
	return StateProc((StateEnum)state, submachineState, behavior, signal, enumEntryType, entryEnumArray, nArrayCount);
}
bool Scales::StateProc(StateEnum state, StateData* submachineState, StateBehaviorEnum behavior, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount) 
{
	switch (state) {
		case Scales_ENUM_STMSCALES_SCALESFINISHED:
			return stmScales_scalesfinished(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case Scales_ENUM_STMSCALES_SCALEUNLOADEDVEHICLE:
			return stmScales_scaleunloadedvehicle(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case Scales_ENUM_STMSCALES_ATLEASTONEDISCHARGINGAREAEMPTY:
			return stmScales_atleastonedischargingAreaempty(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED:
			return stmScales_stopActordeactivated(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case Scales_ENUM_STMSCALES_PATHSECTIONEMTPY:
			return stmScales_pathsectionemtpy(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case Scales_ENUM_STMSCALES_SCALESFINISHED:
			return stmScales_scalesfinished(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case Scales_ENUM_STMSCALES_EMTPY:
			return stmScales_emtpy(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case Scales_ENUM_STMSCALES_PATHSECTIONEMPTY:
			return stmScales_pathSectionempty(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case Scales_ENUM_STMSCALES_SCALELOADEDVEHICLE:
			return stmScales_scaleloadedvehicle(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case Scales_ENUM_STMSCALES_INIT:
			return stmScales_Init(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);

		case Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED:
			return stmScales_stopActordeactivated(behavior, submachineState, signal, enumEntryType, entryArray, nArrayCount);
	}
	return false;
}

bool Scales::stmScales_scalesfinished(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_SCALESFINISHED);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmscales = Scales_ENUM_STMSCALES_SCALESFINISHED;
			state->IncrementActiveCount();
			stmScales_scalesfinished_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmScales_scalesfinished_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmscales = NOSTATE;
			state->DecrementActiveCount();
			stmScales_scalesfinished_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool Scales::stmScales_scalesfinished_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scalesfinished " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scalesfinished " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scalesfinished " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool Scales::stmScales_scaleunloadedvehicle(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_SCALEUNLOADEDVEHICLE);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmscales = Scales_ENUM_STMSCALES_SCALEUNLOADEDVEHICLE;
			state->IncrementActiveCount();
			stmScales_scaleunloadedvehicle_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmScales_scaleunloadedvehicle_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmscales = NOSTATE;
			state->DecrementActiveCount();
			stmScales_scaleunloadedvehicle_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool Scales::stmScales_scaleunloadedvehicle_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scaleunloadedvehicle " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scaleunloadedvehicle " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scaleunloadedvehicle " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool Scales::stmScales_atleastonedischargingAreaempty(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_ATLEASTONEDISCHARGINGAREAEMPTY);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmscales = Scales_ENUM_STMSCALES_ATLEASTONEDISCHARGINGAREAEMPTY;
			state->IncrementActiveCount();
			stmScales_atleastonedischargingAreaempty_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmScales_atleastonedischargingAreaempty_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmscales = NOSTATE;
			state->DecrementActiveCount();
			stmScales_atleastonedischargingAreaempty_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool Scales::stmScales_atleastonedischargingAreaempty_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_atleastonedischargingAreaempty " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_atleastonedischargingAreaempty " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_atleastonedischargingAreaempty " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool Scales::stmScales_stopActordeactivated(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmscales = Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED;
			state->IncrementActiveCount();
			stmScales_stopActordeactivated_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmScales_stopActordeactivated_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmscales = NOSTATE;
			state->DecrementActiveCount();
			stmScales_stopActordeactivated_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool Scales::stmScales_stopActordeactivated_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_stopActordeactivated " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_stopActordeactivated " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_stopActordeactivated " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool Scales::stmScales_pathsectionemtpy(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_PATHSECTIONEMTPY);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmscales = Scales_ENUM_STMSCALES_PATHSECTIONEMTPY;
			state->IncrementActiveCount();
			stmScales_pathsectionemtpy_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmScales_pathsectionemtpy_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmscales = NOSTATE;
			state->DecrementActiveCount();
			stmScales_pathsectionemtpy_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool Scales::stmScales_pathsectionemtpy_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_pathsectionemtpy " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_pathsectionemtpy " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_pathsectionemtpy " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool Scales::stmScales_scalesfinished(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_SCALESFINISHED);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmscales = Scales_ENUM_STMSCALES_SCALESFINISHED;
			state->IncrementActiveCount();
			stmScales_scalesfinished_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmScales_scalesfinished_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmscales = NOSTATE;
			state->DecrementActiveCount();
			stmScales_scalesfinished_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool Scales::stmScales_scalesfinished_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scalesfinished " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scalesfinished " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scalesfinished " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool Scales::stmScales_emtpy(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_EMTPY);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmscales = Scales_ENUM_STMSCALES_EMTPY;
			state->IncrementActiveCount();
			stmScales_emtpy_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmScales_emtpy_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmscales = NOSTATE;
			state->DecrementActiveCount();
			stmScales_emtpy_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool Scales::stmScales_emtpy_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_emtpy " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_emtpy " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_emtpy " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool Scales::stmScales_pathSectionempty(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_PATHSECTIONEMPTY);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmscales = Scales_ENUM_STMSCALES_PATHSECTIONEMPTY;
			state->IncrementActiveCount();
			stmScales_pathSectionempty_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmScales_pathSectionempty_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmscales = NOSTATE;
			state->DecrementActiveCount();
			stmScales_pathSectionempty_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool Scales::stmScales_pathSectionempty_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_pathSectionempty " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_pathSectionempty " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_pathSectionempty " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool Scales::stmScales_scaleloadedvehicle(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_SCALELOADEDVEHICLE);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmscales = Scales_ENUM_STMSCALES_SCALELOADEDVEHICLE;
			state->IncrementActiveCount();
			stmScales_scaleloadedvehicle_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmScales_scaleloadedvehicle_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmscales = NOSTATE;
			state->DecrementActiveCount();
			stmScales_scaleloadedvehicle_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool Scales::stmScales_scaleloadedvehicle_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scaleloadedvehicle " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scaleloadedvehicle " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_scaleloadedvehicle " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool Scales::stmScales_Init(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_INIT);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmscales = Scales_ENUM_STMSCALES_INIT;
			state->IncrementActiveCount();
			stmScales_Init_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmScales_Init_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmscales = NOSTATE;
			state->DecrementActiveCount();
			stmScales_Init_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool Scales::stmScales_Init_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_Init " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_Init " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_Init " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool Scales::stmScales_stopActordeactivated(StateBehaviorEnum behavior, StateData* submachineState, Signal* signal, EntryTypeEnum enumEntryType, EntryEnum entryArray[], int nArrayCount)
{
	if (!m_StateMachineImpl)
		return false;
	
	StateData*  state = m_StateMachineImpl->GetStateObject(submachineState, Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED);
	switch (behavior) {
		case ENTRY:
			if(state->active_count > 0)
				return false;
			m_stmscales = Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED;
			state->IncrementActiveCount();
			stmScales_stopActordeactivated_behavior(ENTRY);
			
			if(enumEntryType == HistoryEntry)
			{
				return true;
			}
			stmScales_stopActordeactivated_behavior(DO);
			if((enumEntryType == EntryPointEntry || enumEntryType == DefaultEntry) && state->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, state);
			break;
		case EXIT:
			if(state->active_count == 0)
				return false;
			m_stmscales = NOSTATE;
			state->DecrementActiveCount();
			stmScales_stopActordeactivated_behavior(EXIT);
			m_StateMachineImpl->removeInternalEvent(state);
			break;
	}
	
	return true;
}

bool Scales::stmScales_stopActordeactivated_behavior(StateBehaviorEnum behavior) 
{
	switch (behavior) {
		case ENTRY:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_stopActordeactivated " << "ENTRY" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case DO:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_stopActordeactivated " << "DO" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
		case EXIT:
		{
			StringStream ss;
			ss << m_sInstanceName << "[" << m_sType << "]." << "stmScales_stopActordeactivated " << "EXIT" << endl;
			GlobalFuncs::trace(ss.str());
		}
			break;
	}
	
	return true;
}

bool Scales::dispatch(Event* event, StateData* toState, bool bCheckOnly) 
{
	if (!m_StateMachineImpl)
		return false;
	
	
	bool bDispatched = false;
	
	if(!toState || !toState->IsActiveState() && !bCheckOnly)
		return bDispatched;
	
	switch (toState->state_enum) {
		case Scales_VIRTUAL_SUBMACHINESTATE:
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
		case Scales_ENUM_STMSCALES_SCALESFINISHED:
	
			switch (event->eventEnum) {
				case ENUM_TAKESEMAPHOREPATHSECTIONSUCCESSFUL:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_SCALESFINISHED__TO__PATHSECTIONEMTPY_243, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case Scales_ENUM_STMSCALES_SCALEUNLOADEDVEHICLE:
	
			switch (event->eventEnum) {
				case ENUM_SCALESFINISHED:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_SCALEUNLOADEDVEHICLE__TO__SCALESFINISHED_242, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case Scales_ENUM_STMSCALES_ATLEASTONEDISCHARGINGAREAEMPTY:
	
			switch (event->eventEnum) {
				case ENUM_TAKESEMAPHOREFORPATHSECTIONSUCCESSFUL:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_ATLEASTONEDISCHARGINGAREAEMPTY__TO__STOPACTORDEACTIVATED_196, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED:
	
			switch (event->eventEnum) {
				case ENUM_PRESENCESENSORTODISCARGINGAREAEXITTRIGGERED:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_STOPACTORDEACTIVATED__TO__EMTPY_217, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case Scales_ENUM_STMSCALES_PATHSECTIONEMTPY:
	
			switch (event->eventEnum) {
		
				case COMPLETION:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_PATHSECTIONEMTPY__TO__STOPACTORDEACTIVATED_230, 0, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case Scales_ENUM_STMSCALES_SCALESFINISHED:
	
			switch (event->eventEnum) {
				case ENUM_TAKESEMAPHOREFORDISCHARGINGAREASUCCESSFUL&&TAKESEMAPHOREF:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_SCALESFINISHED__TO__ATLEASTONEDISCHARGINGAREAEMPTY_228, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case Scales_ENUM_STMSCALES_EMTPY:
	
			switch (event->eventEnum) {
				case ENUM_PRESENCESENSORTOSTARTAREAENTRYTRIGGERED:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_EMTPY__TO__SCALEUNLOADEDVEHICLE_219, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
				case ENUM_PRESENCESENSORTODISCHARGINGAREAENTRYTRIGGERED:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_EMTPY__TO__SCALELOADEDVEHICLE_218, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case Scales_ENUM_STMSCALES_PATHSECTIONEMPTY:
	
			switch (event->eventEnum) {
		
				case COMPLETION:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_PATHSECTIONEMPTY__TO__STOPACTORDEACTIVATED_203, 0, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case Scales_ENUM_STMSCALES_SCALELOADEDVEHICLE:
	
			switch (event->eventEnum) {
				case ENUM_SCALESFINIESHED:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_SCALELOADEDVEHICLE__TO__SCALESFINISHED_229, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case Scales_ENUM_STMSCALES_INIT:
	
			switch (event->eventEnum) {
				case ENUM_INITSUCCESSFUL:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_INIT__TO__EMTPY_220, event->signal, toState->submachine_state);
					bDispatched = true;
					break;
		
			}
	
			break;
		case Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED:
	
			switch (event->eventEnum) {
				case ENUM_PRESENCESENSORTOSTARTAREAEXITTRIGGERED:
					if(!bCheckOnly)
						TransitionProc(Scales_ENUM_STOPACTORDEACTIVATED__TO__EMTPY_216, event->signal, toState->submachine_state);
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

void Scales::runStateMachine(StateMachineEnum statemachine) 
{
	if (!m_StateMachineImpl)
		return;
	
	list<StateData*> activeStateArray;
	if(m_StateMachineImpl->GetCurrentStates(activeStateArray) > 0)
		return;
	
	switch (statemachine) {
		case Scales_ENUM_STMSCALES:
			{
				const int nArrayCount = 1;
				EntryEnum entryArray[nArrayCount] = {Scales_ENUM_STMSCALES_INITIAL_833};
				runStateMachine(statemachine, NULL, 0, entryArray, nArrayCount);	//submachineState is NULL if run standalone statemachine 
			}
			break;
	}
}

void Scales::runStateMachines()
{
	runStateMachine(Scales_ENUM_STMSCALES);
}

void Scales::runStateMachine(String statemachine)
{
	if(statemachine == "Scales_stmScales")
	{
		runStateMachine(Scales_ENUM_STMSCALES);
		return;
	}
}

void Scales::runStateMachine(StateMachineEnum statemachine, StateData* submachineState, Signal* signal, EntryEnum entryArray[], int nEntryCount) 
{
	if(!submachineState)
	{
		StateInitialData initialData(Scales_VIRTUAL_SUBMACHINESTATE, NOSTATE, 1, false, "Scales_VIRTUAL_SUBMACHINESTATE", ""); 
		submachineState = new StateData(m_StateMachineImpl, &initialData);
		
		submachineState->IncrementActiveCount();
		m_StateMachineImpl->lstStateData.push_back(submachineState);
	}
	switch (statemachine) {
		case Scales_ENUM_STMSCALES:
			{
				const int nArrayCount = 11;
				StateInitialData initialDataArray[nArrayCount] = 
					{
						StateInitialData(Scales_ENUM_STMSCALES_SCALESFINISHED, NOSTATE, 0, false, "Scales_stmScales_scalesfinished", "{39FF3F98-58FD-49ab-BE64-8A91078AA192}"),
						StateInitialData(Scales_ENUM_STMSCALES_SCALEUNLOADEDVEHICLE, NOSTATE, 0, false, "Scales_stmScales_scaleunloadedvehicle", "{C098F7B1-F129-4700-9352-CCACA4F0B555}"),
						StateInitialData(Scales_ENUM_STMSCALES_ATLEASTONEDISCHARGINGAREAEMPTY, NOSTATE, 0, false, "Scales_stmScales_atleastonedischargingAreaempty", "{F3ABCAD6-C7E4-4b06-B9DF-5E887D0273FE}"),
						StateInitialData(Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED, NOSTATE, 0, false, "Scales_stmScales_stopActordeactivated", "{03E9B9DB-2860-45ab-9344-12A8D6A92000}"),
						StateInitialData(Scales_ENUM_STMSCALES_PATHSECTIONEMTPY, NOSTATE, 0, false, "Scales_stmScales_pathsectionemtpy", "{28F08E14-D8EA-49d2-B1DF-27016DD7EAE9}"),
						StateInitialData(Scales_ENUM_STMSCALES_SCALESFINISHED, NOSTATE, 0, false, "Scales_stmScales_scalesfinished", "{4ACD3DE3-D09C-4926-BB4A-07FEBA22446B}"),
						StateInitialData(Scales_ENUM_STMSCALES_EMTPY, NOSTATE, 0, false, "Scales_stmScales_emtpy", "{4686A444-28B3-438e-B9CF-F5CED18AD9E7}"),
						StateInitialData(Scales_ENUM_STMSCALES_PATHSECTIONEMPTY, NOSTATE, 0, false, "Scales_stmScales_pathSectionempty", "{FF5527D3-D5AE-4db2-9B91-75261B37296E}"),
						StateInitialData(Scales_ENUM_STMSCALES_SCALELOADEDVEHICLE, NOSTATE, 0, false, "Scales_stmScales_scaleloadedvehicle", "{D096C08A-F5D9-4e90-86DE-8A4C084F1C9A}"),
						StateInitialData(Scales_ENUM_STMSCALES_INIT, NOSTATE, 0, false, "Scales_stmScales_Init", "{E4F42CCA-0509-4f60-87BA-1979EA08F973}"),
						StateInitialData(Scales_ENUM_STMSCALES_STOPACTORDEACTIVATED, NOSTATE, 0, false, "Scales_stmScales_stopActordeactivated", "{470FF6F5-9AB1-4972-A508-78B6475D732F}")
					};
		
				m_StateMachineImpl->CreateStateObjects(initialDataArray, nArrayCount, submachineState);
			}
			for(int i = 0; i < nEntryCount; i++)
			{
				switch(entryArray[i])
				{
				case Scales_ENUM_STMSCALES_INITIAL_833:
					TransitionProc(Scales_ENUM_INITIAL_833__TO__INIT_198, signal, submachineState);
					break;
				}
			}
			if(submachineState->IsActiveState())
				m_StateMachineImpl->deferInternalEvent(COMPLETION, 0, submachineState);
			break;
	}
}

String Scales::GetInstanceName()
{
	return m_sInstanceName;
}

String Scales::GetTypeName()
{
	return m_sType;
}







/* End - EA generated code for StateMachine */