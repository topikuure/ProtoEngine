#ifndef GAME_INPUT_INCLUDED
 #define GAME_INPUT_INCLUDED
#include "SDL2/SDL.h"
#include "pe_input.h"
#include "pe_entity.h"
#include "pe_entityselector.h"
#include "pe_level.h"
#include "pe_grid.h"
namespace PE
{
class GameInput: public Input
    {
    private:
    Entity &player;

    public:
    GameInput(Entity &player);
    int handle();
    };
class LevelEditorInput: public Input
    {
    private:
    Level &level;
    Grid &grid;
    EntitySelector &entitySelector;

    public:
    LevelEditorInput(Level &level, Grid &grid, EntitySelector &entitySelector);
    int handle();
    };
}
#endif