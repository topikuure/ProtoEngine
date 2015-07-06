#ifndef PE_GRID_INCLUDED
 #define PE_GRID_INCLUDED
#include "SDL/SDL.h"
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

    Vector2D convertCoordinate(const Coordinate &gridCoordinate);//Testaa
    Coordinate convertCoordinate(const Vector2D &screenCoordinate);//Implementoi
    Vector2D center(const Vector2D &vector);
    void render(SDL_Surface *screen);
    };
}
#endif