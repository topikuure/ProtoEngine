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
State* State::clone() const
    {
    return new State(*this);
    }

StateMachine::StateMachine()
    :currentState(NULL)
    {
    }
StateMachine::StateMachine(const StateMachine &other)
    {
    for(int i = 0; i < other.states.size(); ++i)
        {
        states.push_back(other.states[i]->clone());
        }
    for(int i = 0; i < states.size(); ++i)
        {
        if(other.currentState->id == states[i]->id)
            {
            currentState = states[i];
            break;
            }
        }
    }
StateMachine::~StateMachine()
    {
    for(int i = 0; i < states.size(); ++i)
        {
        if(states[i] != NULL) delete states[i];
        }
    states.clear();
    }

void StateMachine::addState(const State &s)
    {
    states.push_back(s.clone());
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