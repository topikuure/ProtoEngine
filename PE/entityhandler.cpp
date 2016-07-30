#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>
#include "SDL2/SDL.h"
#include "entityhandler.h"
#include "entity.h"
#include <iostream>
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
Entity& EntityHandler::getEntity(int id)
    {
    for(unsigned int i = 0; i < entities.size(); ++i)
        {
        if(entities[i].id == id) return entities[i];
        }
    }
void EntityHandler::clearEntities()
    {
    entities.clear();
    entityId = 0;
    }
//Ei implementoitu
int EntityHandler::save(const std::string &filename)
    {
    return 0;
    }
//Ei implementoitu
int EntityHandler::load(const std::string &filename, SDL_Renderer *r)
    {
    return 0;
    }
void EntityHandler::process(double time)
    {
    for(int i = 0; i < entities.size(); ++i)
        {
        entities[i].process(time);
        for(int j = 0; j < entities.size(); ++j)
            {
            if(i != j)
                {
                if(entities[i].boundingBox != NULL && entities[j].boundingBox != NULL)
                    {
                    if(entities[i].detectCollision(entities[j])) entities[i].handleCollision(entities[j]);
                    }
                }
            }
        }
    }
void EntityHandler::render()
    {
    for(int i = 0; i < this->entities.size(); ++i)
        {
        entities[i].render();
        }
    }
void EntityHandler::render(const std::vector<int> &ids)
    {
    for(int i = 0; i < ids.size(); ++i)
        {
        for(int j = 0; j < this->entities.size(); ++j)
            {
            if(this->entities[j].id == ids[i]) this->entities[j].render();
            }
        }
    }
}