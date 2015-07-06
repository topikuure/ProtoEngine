#include "SDL/SDL.h"
#include "pe_sprite.h"
namespace PE
{
Sprite::Sprite():surface(NULL)
    {
    }
Sprite::Sprite(const Sprite &other):frame(other.frame), frameCount(other.frameCount), rect(other.rect)
    {
    this->surface = SDL_CreateRGBSurface(0, other.surface->w, other.surface->h, other.surface->format->BitsPerPixel, 0, 0, 0, 0);
    SDL_BlitSurface(other.surface, NULL, this->surface, NULL);
    }
Sprite::~Sprite()
    {
    if(this->surface != NULL) SDL_FreeSurface(this->surface);
    }
int Sprite::load(const std::string &filename, int frameCount)
    {
    //Vanha kuva pois jos load-metodia kutsuttu aiemmin
    if(this->surface != NULL) SDL_FreeSurface(this->surface);

    SDL_Surface *temp;

    temp = SDL_LoadBMP(filename.c_str());
    if(temp == NULL) return 0;
    if((this->surface = SDL_DisplayFormat(temp))== NULL)
        {
        SDL_FreeSurface(temp);
        return 0;
        }
    SDL_FreeSurface(temp);

    this->rect.x = 0;
    this->rect.y = 0;
    this->rect.w = this->surface->w;
    this->rect.h = this->surface->h;
    this->frameCount = frameCount;
    this->frame = 1;
    return 1;
    }
//Kaatunee jos Sprite.surface == NULL
void Sprite::blit(SDL_Surface *screen, int xCoordinate, int yCoordinate)
    {
    if(this->surface != NULL)
        {
        SDL_Rect dest;
        dest.x = xCoordinate;
        dest.y = yCoordinate;
        SDL_BlitSurface(this->surface, &this->rect, screen, &dest);
        }
    }
}
