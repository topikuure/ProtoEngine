#ifndef PE_SPRITE
 #define PE_SPRITE
#include "SDL2/SDL.h"
#include <string>
namespace PE
{
/*
texturen ja surfacen suhde?
surface roikkuu nyt koko olion eliniän viemässä resursseja.
*/
class Sprite
    {
    public:
    int frameCount, frame;
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Rect rect;

    Sprite();
    Sprite(const Sprite &other);
    ~Sprite();

    int load(SDL_Renderer *renderer, const std::string &filename, int frameCount = 1);
    void blit(int xCoordinate, int yCoordinate);
    };
}
#endif
