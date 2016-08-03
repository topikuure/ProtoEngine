#ifndef LE_INPUT_INCLUDED
 #define LE_INPUT_INCLUDED
#include "PE/entityselector.h"
#include "PE/level.h"
#include "PE/grid.h"
namespace LE
{
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