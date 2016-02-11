#ifndef PE_LEVEL_INCLUDED
 #define PE_LEVEL_INCLUDED
#include <string>
#include "pe_entityhandler.h"
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