#include "game_input.h"
#include "PE/entity.h"
namespace GAME
{
GameInput::GameInput(PE::Entity &player):player(player)
    {
    }
int GameInput::handle()
    {
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&event))
        {
        player.stop();
        if(keyState[SDL_SCANCODE_ESCAPE]) return 0;
        if(keyState[SDL_SCANCODE_LEFT]) player.move(-1.0, 0.0);
        else if(keyState[SDL_SCANCODE_RIGHT]) player.move(1.0, 0.0);
        if(keyState[SDL_SCANCODE_UP]) player.move(0.0, -1.0);
        else if(keyState[SDL_SCANCODE_DOWN]) player.move(0.0, 1.0);
        if(event.type == SDL_QUIT)
            {
            return 0;
            }
        }
    return 1;
    }
}