#include <string>
#include "game_entity.h"
#include "game_statemachine.h"
#include "PE/vector2d.h"
namespace GAME
{
Player::Player(double x, double y, const std::string &name):PE::Entity(x, y, name)
    {
    speed = 70.0;
    }

Enemy::Enemy(double x, double y, const std::string &name):PE::Ai(x, y, name)
    {
    speed = 50.0;
    }

void Enemy::initStateMachine(const Player &p)
    {
    Patrol patrol(stateMachine, *this, p);
    Attack attack(stateMachine, *this, p);

    patrol.addWayPoint(Vector2D(20, 20));
    patrol.addWayPoint(Vector2D(300, 20));
    patrol.addWayPoint(Vector2D(20, 300));
    patrol.addWayPoint(Vector2D(300, 300));

    stateMachine.addState(&patrol);
    stateMachine.addState(&attack);

    stateMachine.changeState(ATTACK_ID);
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