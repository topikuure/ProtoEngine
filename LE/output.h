#ifndef LE_OUTPUT_INCLUDED
 #define LE_OUTPUT_INCLUDED
#include "../PE/output.h"
#include "../PE/entityhandler.h"
#include "entityselector.h"
#include "grid.h"
namespace LE
{
class LevelEditorOutput: public PE::Output
    {
    public:
    Grid &grid;
    EntitySelector &entitySelector;

    LevelEditorOutput(EntitySelector &entitySelector, Grid &grid, int width, int height, PE::EntityHandler &eHandler);
    void renderBackground();
    };
}
#endif