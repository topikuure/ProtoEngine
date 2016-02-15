#include "SDL2/SDL.h"
#include "pe_paths.h"
#include "pe_entity.h"
#include "pe_collision.h"
#include "vector2d.h"
#include <string>
#include <cstdlib>
#include <stdexcept>
namespace PE
{
Entity::Entity(double x, double y, const std::string &name):
    id(-1), speed(0.0), position(Vector2D(x, y)), direction(Vector2D(0.0, -1.0)), velocity(Vector2D(0.0, 0.0)), name(name), sprite(NULL), boundingBox(NULL)
    {
    }
Entity::Entity(const Entity &other)
	{
	name = other.name;
    id = other.id;
	position = other.position;
	direction = other.direction;
	velocity = other.velocity;
    speed = other.speed;
	if(other.sprite != NULL)
		{
		try
			{
			loadSprite(other.sprite->renderer);
			}
		catch(const std::invalid_argument &e)
			{
			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", std::string("Entity::copy-constructor: " + std::string(e.what())).c_str(), NULL);
			}
		}
    boundingBox = other.boundingBox;
	}
Entity::~Entity()
    {
	if(sprite != NULL) delete sprite;
    if(boundingBox != NULL) delete boundingBox;
    }
int Entity::loadSprite(SDL_Renderer *r)
    {
    try
		{
		this->sprite = new Sprite(r, PE_Paths::root + PE_Paths::sprites + this->name + ".bmp");
		return 1;
		}
	catch(const std::invalid_argument &e)
        {
        return 0;
        }
    }
void Entity::loadBoundingBox(double width, double height)
    {
    if(boundingBox != NULL) delete boundingBox;
    boundingBox = new BoundingBox;
    boundingBox->x = position.x - (width / 2);
    boundingBox->y = position.y - (height / 2);
    boundingBox->width = width;
    boundingBox->height = height;
    }
void Entity::move(double dirX, double dirY)
    {
    velocity.x += dirX;
    velocity.y += dirY;

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
    velocity *= speed;
    }
void Entity::stop()
    {
    velocity.x = 0.0;
    velocity.y = 0.0;
    }
bool Entity::detectCollision(const Entity &other)
    {
    if(Collision::detect(*boundingBox, *(other.boundingBox))) return true;
    return false;
    }
void Entity::handleCollision(const Entity &other)
    {
    Collision::handle(*boundingBox, *(other.boundingBox));
    position.x = boundingBox->x + (boundingBox->width / 2);
    position.y = boundingBox->y + (boundingBox->height / 2);
    }
void Entity::process(double time)
    {
    position += velocity * time;
    if(boundingBox != NULL)
        {
        boundingBox->x = position.x - (boundingBox->width / 2);
        boundingBox->y = position.y - (boundingBox->height / 2);
        }
    }
void Entity::render()
    {
    if(sprite != NULL) sprite->blit(position.x - ((double)sprite->rect.w) / 2.0, position.y - ((double)sprite->rect.h) / 2.0);
    }

Player::Player(double x, double y, const std::string &name):Entity(x, y, name)
    {
    speed = 60.0;
    }

Ai::Ai(double x, double y, const std::string &name):Entity(x, y, name)
    {
	speed = 50.0;
    }
}