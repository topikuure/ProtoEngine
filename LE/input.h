#ifndef LE_INPUT_INCLUDED
 #define LE_INPUT_INCLUDED
#include "../PE/input.h"
#include "../PE/level.h"
#include "entityselector.h"
#include "grid.h"
namespace LE
{
class LevelEditorInput: public PE::Input
    {
    private:
    PE::Level &level;
    Grid &grid;
    EntitySelector &entitySelector;

    public:
    LevelEditorInput(PE::Level &level, Grid &grid, EntitySelector &entitySelector);
    int handle();
    };
}
#endif