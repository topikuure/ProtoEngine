#include "pe_collision.h"
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
//Ei implementoitu
void Collision::handle(BoundingBox &b1, const BoundingBox &b2)
    {
    }
}