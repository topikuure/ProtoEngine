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

    //Kutsujan pitää muistaa vapauttaa muisti palautetusta Entity-pointterista.
    virtual State* clone() const;

    virtual void process(){};
    };

class StateMachine
    {
    public:
    State *currentState;
    std::vector<State*> states;

    StateMachine();
    StateMachine(const StateMachine &other);
    virtual ~StateMachine();
    void addState(const State &s);
    void stop();
    void changeState(int id);
    int process();
    };
}
#endif