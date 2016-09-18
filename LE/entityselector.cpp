#include <vector>
#include "SDL2/SDL.h"
#include "../PE/vector2d.h"
#include "../PE/entity.h"
#include "../PE/entityhandler.h"
#include "entityselector.h"
namespace LE
{
EntitySelector::EntitySelector(double x, double y):position(Vector2D(x, y)), selectedEntity(NULL), selectedId(0)
    {
    }
PE::Entity& EntitySelector::addEntity(PE::Entity *e)
    {
    selectedEntity = (entityHandler.addEntity(e));
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

    selectedEntity = entityHandler.getEntity(ids[selectedId]);
    }
}