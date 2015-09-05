#ifndef DRAW_UTILS_INCLUDED
 #define DRAW_UTILS_INCLUDED
#include "SDL/SDL.h"
#include "vector2d.h"
namespace drawutils
{
void drawPixel(SDL_Surface *screen, Uint32 x, Uint32 y, Uint32 color);
void drawGrid(SDL_Surface *screen, const SDL_Rect &rect, int cellWidth, int cellHeight, Uint32 color);
}
#endif