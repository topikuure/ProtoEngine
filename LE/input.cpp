#include <stdexcept>//Turha?
#include "leveleditor_input.h"
#include "PE/entityselector.h"
#include "PE/level.h"
#include "PE/grid.h"
namespace LE
{
LevelEditorInput::LevelEditorInput(PE::Level &level, PE::Grid &grid, PE::EntitySelector &entitySelector)
    :level(level), grid(grid), entitySelector(entitySelector)
    {
    }
int LevelEditorInput::handle()
    {
    Uint32 mouseState = 0;
    int mouseX = 0, mouseY = 0;
    static bool mouseLeftDown = false;
    //Uint8 *keyState = SDL_GetKeyboardState(NULL);
    while(SDL_PollEvent(&event))
        {
        /*camera.stop();
        if(keyState[SDL_SCANCODE_ESCAPE]) return 0;
        if(keyState[SDL_SCANCODE_LEFT]) camera.move(-1.0, 0.0);
        if(keyState[SDL_SCANCODE_RIGHT]) camera.move(1.0, 0.0);
        if(keyState[SDL_SCANCODE_UP]) camera.move(0.0, -1.0);
        if(keyState[SDL_SCANCODE_DOWN]) camera.move(0.0, 1.0);*/
       if(event.type == SDL_KEYDOWN)
            {
            if(event.key.keysym.sym == SDLK_LEFT) entitySelector.browse(-1);
            else if(event.key.keysym.sym == SDLK_RIGHT) entitySelector.browse(1);
            else if(event.key.keysym.sym == SDLK_ESCAPE) return 0;
            }
        else if(event.type == SDL_QUIT) return 0;

        mouseState = SDL_GetMouseState(&mouseX, &mouseY);
        if(mouseState & SDL_BUTTON(SDL_BUTTON_LEFT))
                {
                if(mouseLeftDown == false)
                    {
                    PE::Entity *newEntity = new PE::Entity();

                    //kopioi ARVO äläkä laita newEntityä osoittamaan muualle
                    *newEntity = *(entitySelector.selectedEntity);
                    Vector2D position(mouseX, mouseY);
                    if(grid.center(position))
                        {
                        newEntity->position = position;
                        level.entityHandler.addEntity(newEntity);
						}
                    mouseLeftDown = true;
                    }
                }
        else if(mouseState | SDL_BUTTON(SDL_BUTTON_LEFT)) mouseLeftDown = false;
        }
    return 1;
    }
}