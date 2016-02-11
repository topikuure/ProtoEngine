#ifndef COLLISION_INCLUDED
 #define COLLISION_INCLUDED
namespace PE
{
struct BoundingBox
    {
    //Mieti järkevät tyypit
    double x, y, width, height;
    };
class Collision
    {
    public:
    static bool detect(const BoundingBox &b1, const BoundingBox &b2);
    static void handle(BoundingBox &b1, const BoundingBox &b2);//Ei implementoitu
    };
}
#endif