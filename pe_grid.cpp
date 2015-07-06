#include <stdexcept>
#include "SDL/SDL.h"
#include "pe_grid.h"
#include "drawutils.h"
namespace PE
{
Grid::Grid(const SDL_Rect &rect, int cellWidth, int cellHeight, int screenWidth, int screenHeight)
    :rect(rect), cellWidth(cellWidth), cellHeight(cellHeight), screenWidth(screenWidth), screenHeight(screenHeight)
    {
    }
//Testaa
Vector2D Grid::convertCoordinate(const Coordinate &gridCoordinate)
    {
    Vector2D coordinate(gridCoordinate.x * cellWidth, gridCoordinate.y * cellHeight);
    return coordinate;
    }
//Implementoi
Grid::Coordinate Grid::convertCoordinate(const Vector2D &screenCoordinate)
    {
    Coordinate coordinate;
    return coordinate;
    }
Vector2D Grid::center(const Vector2D &point)
    {
    Vector2D centered;
    if(point.x < rect.x || point.x > rect.w + rect.x || point.y < rect.y || point.y > rect.h + rect.y)
        throw std::invalid_argument("point not inside bounds");

    int x = rect.x, y = rect.y;
    while(x < point.x)
        {
        x += cellWidth;
        }
    centered.x = (double)x - (double)cellWidth / 2;
    while(y < point.y)
        {
        y += cellHeight;
        }
    centered.y = (double)y - (double)cellHeight / 2;
    return centered;
    }
void Grid::render(SDL_Surface *screen)
    {
    color = SDL_MapRGB(screen->format, 50, 120, 200);
    SDL_LockSurface(screen);
    int x, y;
    for(x = rect.x + cellWidth; x <= rect.x + rect.w - cellWidth; x += cellWidth)
        {
        for(y = rect.y; y < rect.y + rect.h; ++y)
            {
            drawPixel(screen, x - 1, y, color);
            drawPixel(screen, x, y, color);
            }
        }
    for(y = rect.y + cellHeight; y <= rect.y + rect.h - cellHeight; y += cellHeight)
        {
        for(x = rect.x; x < rect.x + rect.w; ++x)
            {
            drawPixel(screen, x, y - 1, color);
            drawPixel(screen, x, y, color);
            }
        }
    SDL_UnlockSurface(screen);
    }
}