#include "PE/statemachine.h"
#include "game_statemachine.h"
#include "game_entity.h"
#include "PE/vector2D.h"
namespace GAME
{
Patrol::Patrol(PE::StateMachine &sm, Enemy &parent, const Player &p): State(PATROL_ID, sm), parent(parent), player(p)
    {
    nextWayPointIndex = 0;
    }
void Patrol::addWayPoint(const Vector2D &point)
    {
    wayPoints.push_back(point);
    }
void Patrol::process()
    {
    Vector2D parentToPlayer(player.position.x - parent.position.x,
                          player.position.y - parent.position.y);

    if(!wayPoints.empty())
        {
        Vector2D nextWayPoint = wayPoints[nextWayPointIndex];
        Vector2D parentToNextWayPoint(nextWayPoint.x - parent.position.x,
                                    nextWayPoint.y - parent.position.y);

        if(parentToNextWayPoint.getMagnitude() > 1)
            {
            parentToNextWayPoint.normalize();
            parent.moveAi(parentToNextWayPoint.x, parentToNextWayPoint.y);
            }
        else ++nextWayPointIndex;
        if(nextWayPointIndex >= wayPoints.size()) nextWayPointIndex = 0;
        }
    //if(parentToPlayer.getMagnitude() <= 40) stateMachine.changeState(ATTACK_ID);
    }

Attack::Attack(PE::StateMachine &sm, Enemy &parent, const Player &p): State(ATTACK_ID, sm), parent(parent), player(p)
    {
    }
void Attack::process()
    {
    Vector2D parentToPlayer(player.position.x - parent.position.x,
                          player.position.y - parent.position.y);
    parent.moveAi(10,0);
    if(parentToPlayer.getMagnitude() > 40) stateMachine.changeState(PATROL_ID);
    }
}