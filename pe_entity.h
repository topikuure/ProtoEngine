#ifndef PE_ENTITY_INCLUDED
 #define PE_ENTITY_INCLUDED
#include "SDL/SDL.h"
#include "vector2d.h"
#include "pe_sprite.h"
#include <string>
namespace PE
{
/*
"root/sprite" -kansiossa pitää olla entityn nimeä vastaava .png-tiedosto
*/
class Entity
    {
    public:
    std::string name;
    int id;
    Sprite sprite;
    Vector2D position, direction, velocity;
    double speed;

    Entity(double x = 0.0, double y = 0.0, std::string name = "default_entity");
    ~Entity();

    int loadSprite();
    void move(double dirX, double dirY);
    void stop();
    void process(double time);
    void render(SDL_Surface *screen);
    };
class Player: public Entity
    {
    public:
    Player(double x = 0.0, double y = 0.0);
    };
class Enemy: public Entity
    {
    public:
    Enemy(double x = 0.0, double y = 0.0);
    };
}
#endif