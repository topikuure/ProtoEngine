#ifndef GAME_INPUT_INCLUDED
 #define GAME_INPUT_INCLUDED
#include "SDL2/SDL.h"
#include "pe_input.h"
#include "pe_entity.h"
#include "pe_entityselector.h"
#include "pe_level.h"
#include "pe_grid.h"
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
class LevelEditorInput: public PE::Input
    {
    private:
    PE::Level &level;
    PE::Grid &grid;
    PE::EntitySelector &entitySelector;

    public:
    LevelEditorInput(PE::Level &level, PE::Grid &grid, PE::EntitySelector &entitySelector);
    int handle();
    };
}
#endif