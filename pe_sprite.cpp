#include "SDL2/SDL.h"
#include "pe_sprite.h"
#include <iostream>
namespace PE
{
Sprite::Sprite():texture(NULL)
    {
    }
Sprite::Sprite(const Sprite &other):frame(other.frame), frameCount(other.frameCount), rect(other.rect)
    {
    surface = SDL_CreateRGBSurface(0, other.surface->w, other.surface->h, other.surface->format->BitsPerPixel, 0, 0, 0, 0);
    SDL_BlitSurface(other.surface, NULL, surface, NULL);
    renderer = other.renderer;
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    }
Sprite::~Sprite()
    {
    if(texture != NULL) SDL_DestroyTexture(texture);
    if(surface != NULL) SDL_FreeSurface(surface);
    }
int Sprite::load(SDL_Renderer *renderer, const std::string &filename, int frameCount)
    {
    if((surface = SDL_LoadBMP(filename.c_str())) == NULL) return 0;
    if(texture != NULL) SDL_DestroyTexture(texture);
    this->renderer = renderer;

    rect.x = 0;
    rect.y = 0;
    rect.w = surface->w;
    rect.h = surface->h;

    texture = SDL_CreateTextureFromSurface(renderer, surface);

    frameCount = frameCount;
    frame = 1;
    return 1;
    }
void Sprite::blit(int xCoordinate, int yCoordinate)
    {
    if(texture != NULL)
        {
        SDL_Rect dest;
        dest.x = xCoordinate;
        dest.y = yCoordinate;
        dest.w = rect.w;
        dest.h = rect.h;
        SDL_RenderCopy(renderer, texture, &rect, &dest);
        }
    }
}
