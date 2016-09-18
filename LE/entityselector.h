#ifndef ENTITY_SELECTOR_INCLUDED
 #define ENTITY_SELECTOR_INCLUDED
#include <vector>
#include "SDL2/SDL.h"
#include "../PE/vector2d.h"
#include "../PE/entityhandler.h"
#include "../PE/entity.h"
namespace LE
{
class EntitySelector
    {
    public:
    Vector2D position;
    PE::EntityHandler entityHandler;
    PE::Entity *selectedEntity;
    std::vector<int> ids;
    int selectedId;

    EntitySelector(double x = 0.0, double y = 0.0);
    PE::Entity& addEntity(PE::Entity *e);
    void browse(int direction);
    };
}
#endif