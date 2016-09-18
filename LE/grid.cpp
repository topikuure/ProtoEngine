#include <stdexcept>
#include "SDL2/SDL.h"
#include "grid.h"
namespace LE
{
Grid::Grid(const SDL_Rect &rect, int cellWidth, int cellHeight, int screenWidth, int screenHeight)
    :rect(rect), cellWidth(cellWidth), cellHeight(cellHeight), screenWidth(screenWidth), screenHeight(screenHeight)
    {
    }
Vector2D Grid::convertCoordinate(const Coordinate &gridCoordinate)
    {
    Vector2D coordinate(gridCoordinate.x * cellWidth, gridCoordinate.y * cellHeight);
    return coordinate;
    }
//Ei implementoitu
Grid::Coordinate Grid::convertCoordinate(const Vector2D &screenCoordinate)
    {
    Coordinate coordinate;
    return coordinate;
    }
int Grid::center(Vector2D &point)
	{
	Vector2D centered;
    if(point.x < rect.x || point.x > rect.w + rect.x || point.y < rect.y || point.y > rect.h + rect.y)
        return 0;

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
	point = centered;
    return 1;
    }
void Grid::render(SDL_Renderer *r)
    {
    SDL_SetRenderDrawColor(r, 50, 120, 200, 0);

    int x, y;
    for(x = rect.x + cellWidth; x <= rect.x + rect.w - cellWidth; x += cellWidth)
        {
        for(y = rect.y; y < rect.y + rect.h; ++y)
            {
            SDL_RenderDrawPoint(r, x - 1, y);
            SDL_RenderDrawPoint(r, x, y);
            }
        }
    for(y = rect.y + cellHeight; y <= rect.y + rect.h - cellHeight; y += cellHeight)
        {
        for(x = rect.x; x < rect.x + rect.w; ++x)
            {
            SDL_RenderDrawPoint(r, x, y - 1);
            SDL_RenderDrawPoint(r, x, y);
            }
        }
    }
}