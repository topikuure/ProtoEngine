#ifndef GAME_INPUT_INCLUDED
 #define GAME_INPUT_INCLUDED
#include "SDL2/SDL.h"
#include "PE/input.h"
#include "PE/entity.h"
namespace GAME
{
class GameInput: public PE::Input
    {
    private:
    PE::Entity &player;

    public:
    GameInput(PE::Entity &player);
    int handle();
    };
}
#endif