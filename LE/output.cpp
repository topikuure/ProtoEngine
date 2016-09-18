#include "SDL2/SDL.h"
#include "output.h"
namespace LE
{
LevelEditorOutput::LevelEditorOutput(EntitySelector &entitySelector, Grid &grid, int width, int height, PE::EntityHandler &eHandler)
    :Output(width, height, eHandler), entitySelector(entitySelector), grid(grid)
    {
    }
void LevelEditorOutput::renderBackground()
    {
    SDL_RenderClear(renderer);

    std::vector<int> ids;
    ids.push_back(entitySelector.selectedEntity->id);
    entitySelector.entityHandler.render(ids);
    ids.clear();

    grid.render(renderer);
    }
}