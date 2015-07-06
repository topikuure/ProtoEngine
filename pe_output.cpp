#include <vector>
#include "SDL/SDL.h"
#include "pe_output.h"
#include "pe_entityhandler.h"
#include "pe_entityselector.h"
#include "pe_grid.h"
namespace PE
{
Output::Output(int width, int height, EntityHandler &eHandler):entityHandler(eHandler)
    {
    screen = SDL_SetVideoMode(width, height, 0, SDL_SWSURFACE);
    }
Output::~Output()
    {
    }
void Output::render()
    {
    renderBackground();
    entityHandler.render(screen);
    SDL_Flip(screen);
    }
void Output::render(const std::vector<int> &ids)
    {
    renderBackground();
    entityHandler.render(screen, ids);
    SDL_Flip(screen);
    }
void Output::renderBackground()
    {
    }
LevelEditorOutput::LevelEditorOutput(EntitySelector &entitySelector, Grid &grid, int width, int height, EntityHandler &eHandler)
    :Output(width, height, eHandler), entitySelector(entitySelector), grid(grid)
    {
    }
void LevelEditorOutput::renderBackground()
    {
    SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0, 0, 0));

    std::vector<int> ids;
    ids.push_back(entitySelector.selectedEntity->id);
    entitySelector.entityHandler.render(screen, ids);
    ids.clear();

    grid.render(screen);
    }
}