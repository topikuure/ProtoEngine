#ifndef PE_SPRITE
 #define PE_SPRITE
#include "SDL/SDL.h"
#include <string>
namespace PE
{
class Sprite
    {
    public:
    int frameCount, frame;
    SDL_Surface *surface;
    SDL_Rect rect;

    Sprite();
    Sprite(const Sprite &other);
    ~Sprite();

    int load(const std::string &filename, int frameCount = 1);
    void blit(SDL_Surface *screen, int xCoordinate, int yCoordinate);
    };
}
#endif
