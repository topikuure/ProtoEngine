#include <cstddef>
#include <vector>
#include "statemachine.h"
namespace PE
{
State::State(int id, StateMachine &sm)
    :id(id), stateMachine(sm)
    {
    }
State::State(const State &other):
    id(other.id), stateMachine(other.stateMachine)
    {
    }

StateMachine::StateMachine()
    :currentState(NULL)
    {
    }
//Miten vector<State*> kopioiminen onnistuu?
StateMachine::StateMachine(const StateMachine &other)
    :states(states)
    {
    currentState = other.currentState;
    }
StateMachine::~StateMachine()
    {
    for(int i = 0; i < states.size(); ++i)
        {
        if(states[i] != NULL) delete states[i];
        }
    states.clear();
    }

void StateMachine::addState(State *s)
    {
    states.push_back(s);
    }
void StateMachine::stop()
    {
    currentState = NULL;
    }
void StateMachine::changeState(int id)
    {
    for(int i = 0; i < states.size(); ++i)
        {
        if(states[i]->id == id) currentState = states[i];
        }
    }
int StateMachine::process()
    {
    if(currentState != NULL)
        {
        currentState->process();
        return 1;
        }
    return 0;
    }
}