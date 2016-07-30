#include <string>
#include "game_entity.h"
namespace GAME
{
Player::Player(double x, double y, const std::string &name):PE::Entity(x, y, name)
    {
    speed = 70.0;
    }
}