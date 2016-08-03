#ifndef LE_OUTPUT_INCLUDED
 #define LE_OUTPUT_INCLUDED
#include "PE/output.h"
#include "entityhandler.h"
#include "entityselector.h"
#include "grid.h"
namespace LE
{
class LevelEditorOutput: public Output
    {
    public:
    Grid &grid;
    EntitySelector &entitySelector;

    LevelEditorOutput(EntitySelector &entitySelector, Grid &grid, int width, int height, EntityHandler &eHandler);
    void renderBackground();
    };
}
#endif