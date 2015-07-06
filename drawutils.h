#ifndef DRAW_UTILS_INCLUDED
 #define DRAW_UTILS_INCLUDED
#include "SDL/SDL.h"
#include "vector2d.h"
void drawPixel(SDL_Surface *screen, Uint32 x, Uint32 y, Uint32 color);
void drawGrid(SDL_Surface *screen, const SDL_Rect &rect, int cellWidth, int cellHeight, Uint32 color);
//EI TOIMI->
/*
void drawLine(SDL_Surface *screen, Uint32 x1, Uint32 y1, Uint32 x2, Uint32 y2, Uint32 color);
void drawLineVector(SDL_Surface *screen, const Vector2D &point1, const Vector2D &point2, Uint32 color);
*/
#endif