#ifndef GAME_ENTITY_INCLUDED
 #define GAME_ENTITY_INCLUDED
#include <string>
#include "SDL2/SDL.h"
#include "PE/entity.h"
#include "game_statemachine.h"
namespace GAME
{
class Patrol;

class Player: public PE::Entity
    {
    public:
    Player(double x = 0.0, double y = 0.0, const std::string &name = "player");
    Player(const Player &other);
    };

class Enemy: public PE::Ai
    {
    public:
    Enemy(double x = 0.0, double y = 0.0, const std::string &name = "enemy");
    Enemy(const Enemy &other);
    ~Enemy();
    void initStateMachine(const Player &p);
    void process(double time);
    };
}
#endif