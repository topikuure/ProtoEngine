#include <string>
#include "game_entity.h"
#include "game_statemachine.h"
#include "PE/vector2d.h"
namespace GAME
{
Player::Player(double x, double y, const std::string &name):
    PE::Entity(x, y, name)
    {
    speed = 70.0;
    }
Player::Player(const Player &other)
    :Entity(other)
    {
    }
PE::Entity* Player::clone() const
    {
    return (Entity*) new Player(*this);
    }

Enemy::Enemy(double x, double y, const std::string &name):
    PE::Ai(x, y, name)
    {
    speed = 50.0;
    stateMachine.addState(Idle(stateMachine, *this));
    stateMachine.changeState(IDLE_ID);
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Debug", "initStateMachine done", NULL);
    }
Enemy::Enemy(const Enemy &other)
    :Ai(other)
    {
    }
PE::Entity* Enemy::clone() const
    {
    return (Entity*) new Enemy(*this);
    }
void Enemy::initStateMachine(const Player &p)
    {
    //stateMachine.addState(Idle(stateMachine, *this));
    //stateMachine.changeState(IDLE_ID);
    //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Debug", "initStateMachine done", NULL);
    }
void Enemy::process(double time)
    {
    stateMachine.process();
    position += velocity * time;
    if(boundingBox != NULL)
        {
        boundingBox->x = position.x - (boundingBox->width / 2.0);
        boundingBox->y = position.y - (boundingBox->height / 2.0);
        }
    }
}