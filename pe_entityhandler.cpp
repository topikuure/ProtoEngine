#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include "SDL/SDL.h"
#include "pe_entityhandler.h"
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
    std::ofstream file(filename.c_str(), std::ios_base::out | std::ios_base::binary);
    if(file.fail())
        {
        file.close();
        return 0;
        }
    Entity e;
    Data data;

    //KUSEE ehkä->
    file.seekp(0);
    for(int i = 0; i < entities.size(); ++i)
        {
        e = entities[i];
        strcpy(data.name, e.name.c_str());
        data.id = e.id;
        data.posX = e.position.x;
        data.posY = e.position.y;
        data.dirX = e.direction.x;
        data.dirY = e.direction.y;
        data.velX = e.velocity.x;
        data.velY = e.velocity.y;
        data.speed = e.speed;
        file.write((char*)&data, sizeof(data));
        }
    if(file.fail())
        {
        file.close();
        return 0;
        }
    file.close();
    return 1;
    }
int EntityHandler::load(const std::string &filename)
    {
    std::ifstream file(filename.c_str(), std::ios_base::in | std::ios_base::binary);
    if(file.fail())
        {
        file.close();
        return 0;
        }
    Data data;
    Entity e;
    Player player;
    Enemy enemy;

    file.seekg(0);
    //KUSEE->
    while(!file.eof())
        {
        file.read((char*)&data, sizeof(data));
        if(data.name == "player")
            {
            entities.push_back(player);
            }
        else if(data.name == "enemy")
            {
            entities.push_back(enemy);
            }
        else
            {
            entities.push_back(e);
            }
        e = entities.back();
        e.name = std::string(data.name);
        e.id = data.id;
        e.position.x = data.posX;
        e.position.y = data.posY;
        e.direction.x = data.dirX;
        e.direction.y = data.dirY;
        e.velocity.x = data.velX;
        e.velocity.y = data.velY;
        e.speed = data.speed;

        if(e.id > entityId) entityId = e.id;
        }
    if(file.fail())
        {
        file.close();
        return 0;
        }
    file.close();
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