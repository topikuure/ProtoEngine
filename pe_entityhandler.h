#ifndef PE_ENTITY_HANDLER_INCLUDED
 #define PE_ENTITY_HANDLER_INCLUDED
#include <vector>
#include <string>
#include "vector2d.h"
#include "pe_entity.h"
namespace PE
{
/*
entities ei pidä sisältöään järjestyksessä, joten
entityn tunnistaa sen id:llä eikä indeksillä.
*/
class EntityHandler
    {
    private:
    struct Data
        {
        char name[20];
        int id;
        double posX, posY, dirX, dirY, velX, velY, speed;
        };
    int entityId;

    public:
    std::vector<Entity> entities;

    EntityHandler();
    ~EntityHandler();

    Entity& addEntity(const Entity &e);
    void removeEntity(int id);
    Entity* getEntity(int id);

    int save(const std::string &filename);
    int load(const std::string &filename);

    void process(double time);
    void render();
    void render(const std::vector<int> &ids);
    };
}
#endif