#include <cstddef>
#include <vector>
#include "statemachine.h"
namespace PE
{
State::State(int id, StateMachine &sm): id(id), stateMachine(sm)
    {
    //Kannattaisko tehdä näin?
    //sm.addState(this);
    };
State::State(const State &other): id(other.id), stateMachine(other.stateMachine)
    {
    };

StateMachine::StateMachine():currentState(NULL)
    {
    };
void StateMachine::addState(State *s)
    {
    states.push_back(s);
    };
void StateMachine::stop()
    {
    currentState = NULL;
    };
void StateMachine::changeState(int id)
    {
    for(int i = 0; i < states.size(); ++i)
        {
        if(states[i]->id == id) currentState = states[i];
        }
    };
int StateMachine::process()
    {
    if(currentState != NULL)
        {
        currentState->process();
        return 1;
        }
    return 0;
    };
}