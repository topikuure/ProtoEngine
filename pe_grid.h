#ifndef PE_GRID_INCLUDED
 #define PE_GRID_INCLUDED
#include "SDL2/SDL.h"
#include "vector2d.h"
namespace PE
{
class Grid
    {
    public:
    struct Coordinate
        {
        int x, y;
        };
    Uint32 color;
    SDL_Rect rect;
    int cellWidth, cellHeight, screenWidth, screenHeight;

    Grid(const SDL_Rect &rect, int cellWidth, int cellHeight, int screenWidth, int screenHeight);

    Vector2D convertCoordinate(const Coordinate &gridCoordinate);
    Coordinate convertCoordinate(const Vector2D &screenCoordinate);//Ei implementoitu
	int center(Vector2D &point);
    void render(SDL_Renderer *r);
    };
}
#endif