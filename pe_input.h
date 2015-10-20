#ifndef PE_INPUT_INCLUDED
 #define PE_INPUT_INCLUDED
#include "SDL2/SDL.h"
#include "pe_entity.h"
#include "pe_entityselector.h"
#include "pe_level.h"
#include "pe_grid.h"
namespace PE
{
class Input
    {
    protected:
    SDL_Event event;

    public:
    virtual ~Input();
    virtual int handle() = 0;
    };
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