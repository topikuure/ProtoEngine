#include "pe_paths.h"
#include "pe_entity.h"
#include "vector2d.h"
#include <string>
namespace PE
{
Entity::Entity(double x, double y, std::string name):
    id(-1), speed(0.0), position(Vector2D(x, y)), direction(Vector2D(0.0, -1.0)), velocity(Vector2D(0.0, 0.0)), name(name)
    {
    }
Entity::~Entity()
    {
    }
int Entity::loadSprite()
    {
    if(sprite.load(PE_Paths::root + PE_Paths::sprites + this->name + ".bmp")) return 1;
    if(sprite.load(PE_Paths::root + PE_Paths::sprites + "default_entity.bmp")) return 1;
    return 0;
    }
void Entity::move(double dirX, double dirY)
    {
    this->velocity.x += dirX;
    this->velocity.y += dirY;

    //feikkinormalisaatio-> Kusee jos painaa vastakkaisiin suuntiin
    if(velocity.x > 0)
        {
        if(velocity.y > 0) velocity = Vector2D(0.777, 0.777);
        else if(velocity.y < 0) velocity = Vector2D(0.777, -0.777);
        }
    else if(velocity.x < 0)
        {
        if(velocity.y > 0) velocity = Vector2D(-0.777, 0.777);
        else if(velocity.y < 0) velocity = Vector2D(-0.777, -0.777);
        }
    //<-feikkinormalisaatio

    this->velocity *= speed;
    }
void Entity::stop()
    {
    this->velocity.x = 0.0;
    this->velocity.y = 0.0;
    }
void Entity::process(double time)
    {
    this->position += this->velocity * time;
    }
void Entity::render(SDL_Surface *screen)
    {
    this->sprite.blit(screen, this->position.x - this->sprite.rect.w / 2, this->position.y - this->sprite.rect.h / 2);
    }
//Player
Player::Player(double x, double y):Entity(x, y, "player")
    {
    this->speed = 60.0;
    }
//Enemy
Enemy::Enemy(double x, double y):Entity(x, y, "enemy")
    {
    this->speed = 50.0;
    }
}