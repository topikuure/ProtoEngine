#ifndef ENTITY_SELECTOR_INCLUDED
 #define ENTITY_SELECTOR_INCLUDED
#include <vector>
#include "SDL2/SDL.h"
#include "vector2d.h"
#include "pe_entityhandler.h"
#include "pe_entity.h"
namespace PE
{
class EntitySelector
    {
    public:
    Vector2D position;
    EntityHandler entityHandler;
    Entity *selectedEntity;
    std::vector<int> ids;
    int selectedId;

    EntitySelector(double x = 0.0, double y = 0.0);
    Entity& addEntity(const Entity &entity);
    void browse(int direction);
    };
}
#endif