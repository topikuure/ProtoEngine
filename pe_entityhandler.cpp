#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include "SDL/SDL.h"
#include "pe_entityhandler.h"
#include "fileutils.h"
namespace PE
{
EntityHandler::EntityHandler():entityId(0)
    {
    }
EntityHandler::~EntityHandler()
    {
    }
Entity& EntityHandler::addEntity(const Entity &e)
    {
    entities.push_back(e);
    entities.back().id = entityId++;
    return entities.back();
    }
void EntityHandler::removeEntity(int id)
    {
    for(unsigned int i = 0; i < entities.size(); ++i)
        {
        if(entities[i].id == id)
            entities.erase(entities.begin() + i);
        }
    }
Entity* EntityHandler::getEntity(int id)
    {
    for(unsigned int i = 0; i < entities.size(); ++i)
        {
        if(entities[i].id == id) return &entities[i];
        }
    return NULL;
    }
int EntityHandler::save(const std::string &filename)
    {
    if(!fileutils::saveBinary(filename, (char *)entities.data(), entities.size() * sizeof(Entity))) return 0;
    return 1;
    }
int EntityHandler::load(const std::string &filename)
    {
    //if(!fileutils::loadBinary(filename, (char *))) return 0;
    return 1;
    }
void EntityHandler::process(double time)
    {
    for(int i = 0; i < entities.size(); ++i)
        {
        entities[i].process(time);
        }
    }
void EntityHandler::render(SDL_Surface *screen)
    {
    for(int i = 0; i < this->entities.size(); ++i)
        {
        entities[i].render(screen);
        }
    }
void EntityHandler::render(SDL_Surface *screen, const std::vector<int> &ids)
    {
    for(int i = 0; i < ids.size(); ++i)
        {
        for(int j = 0; j < this->entities.size(); ++j)
            {
            if(this->entities[j].id == ids[i]) this->entities[j].render(screen);
            }
        }
    }
}