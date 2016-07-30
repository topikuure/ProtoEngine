#ifndef ENTITY_INCLUDED
 #define ENTITY_INCLUDED
#include <string>
#include "SDL2/SDL.h"
#include "vector2d.h"
#include "sprite.h"
#include "collision.h"
namespace PE
{
//"root/sprite" -kansiossa pitää olla entityn nimeä vastaava .png-tiedosto, jos entitylle haluaa spriten.
class Entity
    {
    public:
    std::string name;
    int id;
    Sprite *sprite;
    Vector2D position, direction, velocity;//diretion = katseen suunta(unit vector), velocity = liikkeen suunta(unit vector) + nopeus(magnitude)
    double speed;
    BoundingBox *boundingBox;

    Entity(double x = 0.0, double y = 0.0, const std::string &name = "entity");
	Entity(const Entity &other);
    ~Entity();

    int loadSprite(SDL_Renderer *renderer);
    void loadBoundingBox(double width, double height);
    void move(double dirX, double dirY);
    void stop();
    bool detectCollision(const Entity &other);
    void handleCollision(const Entity &other);
    void process(double time);
    void render();
    };

class Ai: public Entity
    {
    public:
	//Brains brains;
    Ai(double x = 0.0, double y = 0.0, const std::string &name = "ai");
    };
}
#endif