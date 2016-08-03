#include <vector>
#include "SDL2/SDL.h"
#include "output.h"
#include "entityhandler.h"
namespace PE
{
Output::Output(int width, int height, EntityHandler &eHandler):entityHandler(eHandler)
    {
    screenWidth = width;
    screenHeight = height;
    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    }
Output::~Output()
    {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    }
void Output::render()
    {
	SDL_SetRenderDrawColor(renderer, 0, 200, 0, 0);
    renderBackground();
    entityHandler.render();
    SDL_RenderPresent(renderer);
    }
void Output::render(const std::vector<int> &ids)
    {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    renderBackground();
    entityHandler.render(ids);
    SDL_RenderPresent(renderer);
    }
void Output::renderBackground()
    {
    SDL_Rect screenRect = {.x = 0, .y = 0, .w = screenWidth, .h = screenHeight};
    SDL_RenderFillRect(renderer, &screenRect);
    }
}