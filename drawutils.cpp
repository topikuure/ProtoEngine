#include "SDL/SDL.h"
#include "drawutils.h"
#include "vector2d.h"
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
//EI TOIMI->
/*
void drawLine(SDL_Surface *screen, Uint32 x1, Uint32 y1, Uint32 x2, Uint32 y2, Uint32 color)
    {
    int dx  = x2 - x1,
        dy  = y2 - y1,
        y   = y1,
        eps = 0;
    for(int x = x1; x <= x2; x++)
        {
        drawPixel(screen, x, y, color);
        eps += dy;
        if((eps << 1) >= dx)
            {
            ++y;
            eps -= dx;
            }
        }
    }
void drawLineVector(SDL_Surface *screen, const Vector2D &point1, const Vector2D &point2, Uint32 color)
    {
    Vector2D pixelPos = Vector2D(point1.x, point1.y);
    Vector2D direction = Vector2D(point2.x - point1.x, point2.y - point1.y);
    double magnitude = direction.getMagnitude();
    direction.normalize();

    while(pixelPos.getMagnitude() < magnitude)
        {
        pixelPos += direction;
        drawPixel(screen, pixelPos.x, pixelPos.y, color);
        }
    }
*/