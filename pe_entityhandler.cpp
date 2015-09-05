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
    /*Entity e;
    Data data[2];

    for(int i = 0; i < entities.size(); ++i)
        {
        e = entities[i];
        strcpy(data[i].name, e.name.c_str());
        data[i].id = e.id;
        data[i].posX = e.position.x;
        data[i].posY = e.position.y;
        data[i].dirX = e.direction.x;
        data[i].dirY = e.direction.y;
        data[i].velX = e.velocity.x;
        data[i].velY = e.velocity.y;
        data[i].speed = e.speed;
        }
    if(!fileutils::saveBinary(filename, (char *) data, sizeof(data))) return 0;*/
    if(!fileutils::saveBinary(filename, (char *)entities.data(), entities.size() * sizeof(Entity))) return 0;
    return 1;
    }
int EntityHandler::load(const std::string &filename)
    {
    Data data[2];
    Entity e;
    Player player;
    Enemy enemy;

    fileutils::loadBinary(filename, (char *) data, sizeof(data));
    for(int i = 0; i < 2; ++i)
        {
        if(data[i].name == "player")
            {
            entities.push_back(player);
            }
        else if(data[i].name == "enemy")
            {
            entities.push_back(enemy);
            }
        else
            {
            entities.push_back(e);
            }
        e = entities.back();
        e.name = std::string(data[i].name);
        e.id = data[i].id;
        e.position.x = data[i].posX;
        e.position.y = data[i].posY;
        e.direction.x = data[i].dirX;
        e.direction.y = data[i].dirY;
        e.velocity.x = data[i].velX;
        e.velocity.y = data[i].velY;
        e.speed = data[i].speed;

        if(e.id > entityId) entityId = e.id;
        }
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