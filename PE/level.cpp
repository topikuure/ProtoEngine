#include "SDL2/SDL.h"
#include "level.h"
#include <string>
#include <fstream>
namespace PE
{
int Level::save(const std::string &filename)
    {
	//Tee filename niminen kansio? Sinne filename.entities jne.
    if(!entityHandler.save(filename + ".entities")) return 0;
    /*
    //Briefing:
    std::ofstream file(filename.c_str());
    if(file.fail()) return 0;
    file.close();*/
    return 1;
    }
int Level::load(const std::string &filename, SDL_Renderer *r)
    {
    if(!entityHandler.load(filename + ".entities", r)) return 0;
    /*std::ifstream file(filename.c_str(), std::ios_base::in | std::ios_base::binary);
    if(file.fail()) return 0;
    file.close();*/
    return 1;
    }
}