#ifndef INPUT_INCLUDED
 #define INPUT_INCLUDED
#include "SDL2/SDL.h"
namespace PE
{
class Input
    {
    protected:
    SDL_Event event;

    public:
    virtual ~Input(){};
    virtual int handle() = 0;
    };
}
#endif