#include <stdexcept>
#include "pe_input.h"
#include "pe_entity.h"
#include "pe_entityselector.h"
#include "pe_level.h"
#include "pe_grid.h"
namespace PE
{
Input::~Input()
    {
    }
GameInput::GameInput(Entity &player):player(player)
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
        if(keyState[SDL_SCANCODE_RIGHT]) player.move(1.0, 0.0);
        if(keyState[SDL_SCANCODE_UP]) player.move(0.0, -1.0);
        if(keyState[SDL_SCANCODE_DOWN]) player.move(0.0, 1.0);
       /*if(event.type == SDL_KEYDOWN)
            {
            if(event.key.keysym.sym == SDLK_LEFT)
                player.move(-1.0, 0.0);
            else if(event.key.keysym.sym == SDLK_RIGHT)
                player.move(1.0, 0.0);
            else if(event.key.keysym.sym == SDLK_UP)
                player.move(0.0, -1.0);
            else if(event.key.keysym.sym == SDLK_DOWN)
                player.move(0.0, 1.0);
            else if(event.key.keysym.sym == SDLK_ESCAPE)
                return 0;
            }*/
        if(event.type == SDL_QUIT)
            {
            return 0;
            }
        }
    return 1;
    }
LevelEditorInput::LevelEditorInput(Level &level, Grid &grid, EntitySelector &entitySelector)
    :level(level), grid(grid), entitySelector(entitySelector)
    {
    }
int LevelEditorInput::handle()
    {
    Uint32 mouseState = 0;
    int mouseX = 0, mouseY = 0;
    static bool mouseLeftDown = false;
    //Uint8 *keyState;
    while(SDL_PollEvent(&event))
        {
        /*keyState = SDL_GetKeyState(NULL);

        camera.stop();
        if(keyState[SDLK_ESCAPE]) return 0;
        if(keyState[SDLK_LEFT]) camera.move(-1.0, 0.0);
        if(keyState[SDLK_RIGHT]) camera.move(1.0, 0.0);
        if(keyState[SDLK_UP]) camera.move(0.0, -1.0);
        if(keyState[SDLK_DOWN]) camera.move(0.0, 1.0);*/
       if(event.type == SDL_KEYDOWN)
            {
            if(event.key.keysym.sym == SDLK_q) entitySelector.browse(-1);
            else if(event.key.keysym.sym == SDLK_w) entitySelector.browse(1);
            else if(event.key.keysym.sym == SDLK_ESCAPE) return 0;
            }
        else if(event.type == SDL_QUIT) return 0;

        mouseState = SDL_GetMouseState(&mouseX, &mouseY);
        if(mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))
                {
                if(mouseLeftDown == false)
                    {
                    Entity newEntity = *(entitySelector.selectedEntity);
                    Vector2D position;
                    try
                        {
                        position = grid.center(Vector2D(mouseX, mouseY));
                        newEntity.position = position;
                        level.entityHandler.addEntity(newEntity);
                        }
                    catch(std::exception &e){}
                    mouseLeftDown = true;
                    }
                }
        else if(mouseState | SDL_BUTTON(SDL_BUTTON_LEFT)) mouseLeftDown = false;
        }
    return 1;
    }
}