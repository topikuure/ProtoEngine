#ifndef OUTPUT_INCLUDED
 #define OUTPUT_INCLUDED
#include <vector>
#include "SDL2/SDL.h"
#include "entityhandler.h"
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
}
#endif