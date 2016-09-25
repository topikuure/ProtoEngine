#ifndef STATE_MACHINE_INCLUDED
 #define STATE_MACHINE_INCLUDED
#include <vector>
namespace PE
{
class StateMachine;

class State
    {
    public:
    int id;
    StateMachine &stateMachine;

    State(int id, StateMachine &sm);
    State(const State &other);
    virtual ~State(){};
    virtual void process() = 0;
    };

class StateMachine
    {
    public:
    State *currentState;
    std::vector<State*> states;

    StateMachine();
    StateMachine(const StateMachine &other);
    virtual ~StateMachine();
    void addState(State *s);
    void stop();
    void changeState(int id);
    int process();
    };
}
#endif