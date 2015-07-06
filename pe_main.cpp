#include "SDL/SDL.h"
#include "pe_input.h"
#include "pe_output.h"
#include "pe_entity.h"
#include "pe_entityhandler.h"
int main(int argc, char **argv)
    {
    SDL_Init(0);
    Uint32 start, end;

    PE::EntityHandler entityHandler;
    PE::Output output(800, 600, entityHandler);
    PE::Input input;

    PE::Player player(200.0, 200.0);
    if(!player.loadSprite()) goto exit;
    entityHandler.addEntity(player);

    start = SDL_GetTicks();
    while(input.handle(entityHandler.entities[0]))
        {
        end = SDL_GetTicks();
        entityHandler.process((double)(end - start) / 1000.0);
        output.render();
        start = end;
        }
    exit:
    SDL_Quit();
    }