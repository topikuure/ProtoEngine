#ifndef PE_OUTPUT_INCLUDED
 #define PE_OUTPUT_INCLUDED
#include <vector>
#include "SDL2/SDL.h"
#include "pe_entityhandler.h"
#include "pe_entityselector.h"
#include "pe_grid.h"
namespace PE
{
class Output
    {
    public:
    int screenWidth;
    int screenHeight;

    SDL_Window *window;
    SDL_Renderer *renderer;
    EntityHandler &entityHandler;

    Output(int width, int height, EntityHandler &eHandler);
    ~Output();
    void render();
    void render(const std::vector<int> &ids);
    virtual void renderBackground();
    };

class GameOutput: public Output
    {
    public:
    void renderBackground(){};
    };

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