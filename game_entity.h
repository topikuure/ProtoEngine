#ifndef GAME_ENTITY_INCLUDED
 #define GAME_ENTITY_INCLUDED
#include <string>
#include "SDL2/SDL.h"
#include "pe_entity.h"
namespace PE
{
class Player: public Entity
    {
    public:
    Player(double x = 0.0, double y = 0.0, const std::string &name = "player");
    };
}
#endif