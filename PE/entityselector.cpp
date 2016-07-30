#include <vector>
#include "SDL2/SDL.h"
#include "entityselector.h"
#include "vector2d.h"
#include "entityhandler.h"
#include "entity.h"
namespace PE
{
EntitySelector::EntitySelector(double x, double y):position(Vector2D(x, y)), selectedEntity(NULL), selectedId(0)
    {
    }
Entity& EntitySelector::addEntity(const Entity &e)
    {
    selectedEntity = &(entityHandler.addEntity(e));
    ids.push_back(selectedEntity->id);
    selectedId = selectedEntity->id;
    return *selectedEntity;
    }
void EntitySelector::browse(int direction)
    {
    if(direction > 0) ++selectedId;
    else if(direction < 0) --selectedId;

    if(selectedId < 0) selectedId = ids.size() - 1;
    else if(selectedId >= ids.size()) selectedId = 0;

    selectedEntity = &(entityHandler.getEntity(ids[selectedId]));
    }
}