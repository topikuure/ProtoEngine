#ifndef GAME_ENTITY_INCLUDED
 #define GAME_ENTITY_INCLUDED
#include <string>
#include "SDL2/SDL.h"
#include "PE/entity.h"
namespace GAME
{
class Player: public PE::Entity
    {
    public:
    Player(double x = 0.0, double y = 0.0, const std::string &name = "player");
    };
}
#endif