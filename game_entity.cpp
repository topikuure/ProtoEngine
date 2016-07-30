#include <string>
#include "game_entity.h"
namespace PE
{
Player::Player(double x, double y, const std::string &name):Entity(x, y, name)
    {
    speed = 70.0;
    }
}