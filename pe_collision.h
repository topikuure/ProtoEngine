#ifndef COLLISION_INCLUDED
 #define COLLISION_INCLUDED
namespace PE
{
struct BoundingBox
    {
    double x, y, width, height;
    };
class Collision
    {
    public:
    static bool detect(const BoundingBox &b1, const BoundingBox &b2);
    static void handle(BoundingBox &b1, const BoundingBox &b2);
    };
}
#endif