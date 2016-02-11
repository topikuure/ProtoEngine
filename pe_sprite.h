#ifndef PE_SPRITE
 #define PE_SPRITE
#include "SDL2/SDL.h"
#include <string>
namespace PE
{
class Sprite
    {
    public:
    int frameCount, frame;//frame ja frameCount ei tee vielä mitään.
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    SDL_Surface *surface;
    SDL_Rect rect;

    Sprite(SDL_Renderer *renderer, const std::string &filename, int frameCount = 1);
    Sprite(const Sprite &other);
    ~Sprite();

    void blit(int xCoordinate, int yCoordinate);
    };
}
#endif
