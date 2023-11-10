#ifndef DFA_H
#define DFA_H
#endif

#define MAX_TRANSITION 50
#define MAX_STATES 100

using namespace std;

typedef struct
{
	int (*condition)(char);
	int stateId;
} dfaTransition;

typedef struct
{
	int id;
	bool actionable;
	int noOfTransitions; 
	std::string actionName;
	dfaTransition transitions[MAX_TRANSITIONS];
	int defaultToStateId;
} dfaState;

typedef struct
{
	int startStateId;
	int currentStateId;
	int noOfStates;
	dfaState* states[MAX_STATES];
} dfa;

dfa* dfa_createDFA();
void dfa_reset(dfa* dfa); //makes the dfa ready for consumption. i.e. sets the current state to start state.
void dfa_makeNextTransition(dfa* dfa, char c);
void dfa_addState(dfa* pDFA, dfaState* newState);
dfaState* dfa_createState(int hasAction, char* actionName);
void dfa_addTransition(dfa* dfa, int fromStateID, int(*condition)(char), int toStateID);
