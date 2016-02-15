#include "pe_collision.h"
#include "vector2d.h"
namespace PE
{
bool Collision::detect(const BoundingBox &b1, const BoundingBox &b2)
    {
    if(b1.x < b2.x + b2.width &&
       b1.x + b1.width > b2.x &&
       b1.y < b2.y + b2.height &&
       b1.y + b1.height > b2.y) return true;
    return false;
    }
void Collision::handle(BoundingBox &b1, const BoundingBox &b2)
    {
    Vector2D direction = Vector2D(b2.x - b1.x, b2.y - b1.y);
    direction.normalize();
    if(direction.x >= 0.7) b1.x--;
    else if(direction.x <= -0.7) b1.x++;
    else if(direction.y >= 0.7) b1.y--;
    else if(direction.y <= -0.7) b1.y++;
    }
}