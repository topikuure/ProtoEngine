#include "SDL/SDL.h"
#include "drawutils.h"
#include "vector2d.h"
namespace drawutils
{
void drawPixel(SDL_Surface *screen, Uint32 x, Uint32 y, Uint32 color)
    {
    if(x >= 0 && x < screen->w && y >= 0 && y < screen->h)
        {
        Uint32 *pixelMemory;
        pixelMemory = (Uint32*) screen->pixels;
        pixelMemory[x + y * screen->w] = color;
        }
    }
void drawGrid(SDL_Surface *screen, const SDL_Rect &rect, int cellWidth, int cellHeight, Uint32 color)
    {
    SDL_LockSurface(screen);
    for(int x = rect.x; x < rect.x + rect.w + 1; x += cellWidth)
        {
        for(int y = rect.y; y < rect.y + rect.h; ++y)
            {
            drawPixel(screen, x, y, color);
            }
        }
    for(int y = rect.y; y < rect.y + rect.h + 1; y += cellHeight)
        {
        for(int x = rect.x; x < rect.x + rect.w; ++x)
            {
            drawPixel(screen, x, y, color);
            }
        }
    SDL_UnlockSurface(screen);
    }
}