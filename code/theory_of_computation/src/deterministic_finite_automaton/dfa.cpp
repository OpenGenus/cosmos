#include "dfa.hh"
#include <stdlib.h>
#include <string.h>

using namespace std;

void dfa_makeNextTransition(dfa* dfa, char symbol)
{
	int transitionID;
	DFAState* pCurrentState = dfa->states[dfa->currentStateID];
	for (transitionID = 0; transitionID < pCurrentState->numberOfTransitions; transitionID++)
	{
		if (pCurrentState->transitions[transitionID].condition(symbol))
		{
			dfa->currentStateID = pCurrentState->transitions[transitionID].toStateID;
			return;
		}
	}

	dfa->currentStateID = pCurrentState->defaultToStateID;
}

void dfa_addState(dfa* pDFA, dfaState* newState)
{	
	newState->id = pDFA->noOfStates;
	pDFA->states[pDFA->noOfStates] = newState;
	pDFA->noOfStates++;
}

void dfa_addTransition(DFA* dfa, int fromStateID, int(*condition)(char), int toStateID)
{
	DFAState* state = dfa->states[fromStateID];
	state->transitions[state->noOfTransitions].condition = condition;
	state->transitions[state->noOfTransitions].toStateID = toStateID;
	state->noOfTransitions++;
}

dfaState* dfa_createState(bool actionable, std::string actionName)
{
	dfaState* newState = (dfaState*)malloc(sizeof(dfaState));
	strcpy(newState->actionName, actionName);
	newState->defaultToStateID = -1;
	newState->actionable = actionable;
	newState->id = -1;
	newState->noOfTransitions = 0;

	return newState;
	
}

dfa* dfa_createDFA()
{
	dfa* dfa = (dfa*)malloc(sizeof(dfa));
	dfa->noOfStates = 0;
	dfa->startStateID = -1;
	dfa->currentStateID = -1;
	return dfa;
}

void dfa_reset(dfa* dfa)
{
	dfa->currentStateID = dfa->startStateID;
}