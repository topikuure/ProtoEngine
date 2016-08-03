#ifndef GAME_STATE_MACHINE_INCLUDED
 #define GAME_STATE_MACHINE_INCLUDED
#include <vector>
#include "PE/statemachine.h"
#include "PE/vector2D.h"
#include "game_entity.h"
namespace GAME
{
void showDebugMessage(const char *message);

class Enemy;
class Player;

enum StateId{IDLE_ID, PATROL_ID, ATTACK_ID};

class Idle: public PE::State
    {
    public:
    Enemy &parent;

    Idle(PE::StateMachine &sm, Enemy &parent);
    Idle(const Idle &other);
    void process();
    };

class Patrol: public PE::State
    {
    public:
    Enemy &parent;
    const Player &player;

    std::vector<Vector2D> wayPoints;
    int nextWayPointIndex;

    Patrol(PE::StateMachine &sm, Enemy &parent, const Player &p);
    void addWayPoint(const Vector2D &point);
    void process();
    };

class Attack: public PE::State
    {
    public:
    Enemy &parent;
    const Player &player;

    Attack(PE::StateMachine &sm, Enemy &parent, const Player &p);
    void process();
    };
}
#endif