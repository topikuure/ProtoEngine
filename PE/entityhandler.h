#ifndef ENTITY_HANDLER_INCLUDED
 #define ENTITY_HANDLER_INCLUDED
#include <vector>
#include <string>
#include "vector2d.h"
#include "entity.h"
namespace PE
{
class EntityHandler
    {
    private:
    int entityId;

    public:
    std::vector<Entity*> entities;

    EntityHandler();
    ~EntityHandler();

    Entity* addEntity(const Entity &e);
    void removeEntity(int id);
    Entity* getEntity(int id);
    void clearEntities();

    int save(const std::string &filename);//Ei implementoitu
    int load(const std::string &filename, SDL_Renderer *r);//Ei implementoitu

    void process(double time);
    void render();
    void render(const std::vector<int> &ids);
    };
}
#endif