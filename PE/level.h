#ifndef LEVEL_INCLUDED
 #define LEVEL_INCLUDED
#include <string>
#include "entityhandler.h"
#include "SDL2/SDL.h"
namespace PE
{
class Level
    {
    public:
    EntityHandler entityHandler;
    //std::string briefing jne.

    int save(const std::string &filename);
    int load(const std::string &filename, SDL_Renderer *r);
    };
}
#endif