#include <vector>
#include "SDL/SDL.h"
#include "pe_input.h"
#include "pe_output.h"
#include "pe_entity.h"
#include "pe_entityhandler.h"
#include "pe_entityselector.h"
#include "pe_level.h"
#include "drawutils.h"
int main(int argc, char **argv)
    {
    SDL_Init(0);

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

    PE::Player player;
    PE::Enemy enemy;
    if(!player.loadSprite()) goto exit;
    if(!enemy.loadSprite()) goto exit;
    player.position = Vector2D(player.position.x + player.sprite.rect.w / 2, player.position.y + player.sprite.rect.h / 2);
    enemy.position = Vector2D(enemy.position.x + enemy.sprite.rect.w / 2, enemy.position.y + enemy.sprite.rect.h / 2);
    entitySelector.addEntity(player);
    entitySelector.addEntity(enemy);

    if(!level.load("level1")) goto exit;

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
    if(!level.save("level1")) goto exit;
    exit:
    SDL_Quit();
    return 0;
    }