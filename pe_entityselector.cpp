#include <vector>
#include "SDL2/SDL.h"
#include "pe_entityselector.h"
#include "vector2d.h"
#include "pe_entityhandler.h"
#include "pe_entity.h"
namespace PE
{
EntitySelector::EntitySelector(double x, double y):position(Vector2D(x, y)), selectedEntity(NULL), selectedId(0)
    {
    }
Entity& EntitySelector::addEntity(const Entity &entity)
    {
    this->selectedEntity = &(this->entityHandler.addEntity(entity));
    this->ids.push_back(this->selectedEntity->id);
    this->selectedId = this->ids.back();
    return *this->selectedEntity;
    }
void EntitySelector::browse(int direction)
    {
    if(direction > 0) ++this->selectedId;
    else if(direction < 0) --this->selectedId;

    if(this->selectedId < 0) this->selectedId = ids.size() - 1;
    else if(this->selectedId >= ids.size()) this->selectedId = 0;

    if(this->entityHandler.getEntity(ids[selectedId]) != NULL)
        this->selectedEntity = this->entityHandler.getEntity(ids[selectedId]);
    }
}