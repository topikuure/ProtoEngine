#include "SDL2/SDL.h"
#include "pe_sprite.h"
#include <stdexcept>
namespace PE
{
Sprite::Sprite(SDL_Renderer *r, const std::string &filename, int frameCount)
    {
	if((surface = SDL_LoadBMP(filename.c_str()))== NULL) throw std::invalid_argument("could not open " + filename);

    rect.x = 0;
    rect.y = 0;
    rect.w = surface->w;
    rect.h = surface->h;

	renderer = r;
    texture = SDL_CreateTextureFromSurface(r, surface);

    frameCount = frameCount;
    frame = 1;
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
    SDL_DestroyTexture(texture);
    SDL_FreeSurface(surface);
    }
void Sprite::blit(int xCoordinate, int yCoordinate)
    {
	SDL_Rect dest;
	dest.x = xCoordinate;
	dest.y = yCoordinate;
	dest.w = rect.w;
	dest.h = rect.h;
	SDL_RenderCopy(renderer, texture, &rect, &dest);
    }
}
