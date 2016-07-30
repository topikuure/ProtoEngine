#include <cstdlib>
#include <cstring>
#include <vector>
#include "SDL2/SDL.h"
#include "input.h"
#include "output.h"
#include "entity.h"
#include "entityhandler.h"
#include "entityselector.h"
#include "level.h"
/*
paths.h sisältää hardcodattuna tarvittavat polut ja kansioiden nimet. Tee siitä järkevämpi
*/
void showErrorMessage(const std::string &msg)
    {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", msg.c_str(), NULL);
    }
int main(int argc, char **argv)
    {
    SDL_Init(0);
	atexit(SDL_Quit);

    bool load = false, save = false;
	for(int i = 0; i < argc; ++i)
        {
        if(!strcmp(argv[i], "load")) load = true;
        else if(!strcmp(argv[i], "save")) save = true;
        }

    int screenWidth = 800, screenHeight = 600;

    PE::Level level;
    PE::EntitySelector entitySelector(200, 200);

    SDL_Rect gridRect;
    gridRect.x = 24;
    gridRect.y = 24;
    gridRect.w = 24 * 16;
    gridRect.h = 24 * 16;
    PE::Grid grid(gridRect, 24, 24, screenWidth, screenHeight);

    PE::LevelEditorOutput output(entitySelector, grid, screenWidth, screenHeight, level.entityHandler);
    PE::LevelEditorInput input(level, grid, entitySelector);

    std::vector<int> ids;
/*
    PE::Entity &player = entitySelector.addEntity(PE::Player());
    PE::Entity &ai = entitySelector.addEntity(PE::Ai());

	if(!player.loadSprite(output.renderer))
        {
        showErrorMessage("player.loadSprite() failed");
        }
    if(!ai.loadSprite(output.renderer))
        {
        showErrorMessage("ai.loadSprite() failed");
        }
	player.position = Vector2D(player.position.x + player.sprite->rect.w / 2, player.position.y + player.sprite->rect.h / 2);
    ai.position = Vector2D(ai.position.x + ai.sprite->rect.w / 2, ai.position.y + ai.sprite->rect.h / 2);
*/
	PE::Entity *entity = &(entitySelector.addEntity(PE::Player()));

	if(!entity->loadSprite(output.renderer))
        {
        showErrorMessage("player.loadSprite() failed");
        }
    entity->position = Vector2D(entity->position.x + entity->sprite->rect.w / 2, entity->position.y + entity->sprite->rect.h / 2);

    entity = &(entitySelector.addEntity(PE::Ai()));
    if(!entity->loadSprite(output.renderer))
        {
        showErrorMessage("ai.loadSprite() failed");
        }
    entity->position = Vector2D(entity->position.x + entity->sprite->rect.w / 2, entity->position.y + entity->sprite->rect.h / 2);

    if(load == true)
        {
        if(!level.load("level1", output.renderer))
            {
            showErrorMessage("level.load() failed");
			return 0;
            }
        }
    while(input.handle())
        {
        ids.push_back(entitySelector.selectedEntity->id);
        for(unsigned int i = 0; i < level.entityHandler.entities.size(); ++i)
            {
            ids.push_back(level.entityHandler.entities[i].id);
            }
        output.render(ids);
        ids.clear();
        }
    if(save == true)
        {
        if(!level.save("level1"))
            {
            showErrorMessage("level.save() failed");
			return 0;
            }
        }
    return 0;
    }