#ifndef PE_INPUT_INCLUDED
 #define PE_INPUT_INCLUDED
#include "SDL2/SDL.h"
#include "pe_entity.h"
#include "pe_entityselector.h"
#include "pe_level.h"
#include "pe_grid.h"
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