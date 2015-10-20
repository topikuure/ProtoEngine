#include "SDL2/SDL.h"
#include "pe_level.h"
#include <string>
#include <fstream>
namespace PE
{
int Level::save(const std::string &filename)
    {
    if(!entityHandler.save(filename + ".entities")) return 0;
    /*
    //Briefing:
    std::ofstream file(filename.c_str());
    if(file.fail()) return 0;
    file.close();*/
    return 1;
    }
int Level::load(const std::string &filename)
    {
    if(!entityHandler.load(filename + ".entities")) return 0;
    /*std::ifstream file(filename.c_str(), std::ios_base::in | std::ios_base::binary);
    if(file.fail()) return 0;
    file.close();*/
    return 1;
    }
}