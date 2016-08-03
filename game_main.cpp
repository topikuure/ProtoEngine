#include "SDL2/SDL.h"
#include "game_input.h"
#include "game_entity.h"
#include "PE/output.h"
#include "PE/entity.h"
#include "PE/entityhandler.h"
/*
paths.h sisältää hardcodattuna tarvittavat polut ja kansioiden nimet. Tee siitä järkevämpi
*/
void showErrorMessage(const char *message)
    {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Error", message, NULL);
    }
int main(int argc, char **argv)
    {
    SDL_Init(0);
    Uint32 start, end;

    PE::EntityHandler entityHandler;
    PE::Output output(800, 600, entityHandler);

	int playerId = (entityHandler.addEntity(new GAME::Player(200, 200)))->id;
    int enemyId = (entityHandler.addEntity(new GAME::Enemy(300, 300)))->id;
    GAME::Player *player = (GAME::Player*)entityHandler.getEntity(playerId);    
    GAME::Enemy *enemy = (GAME::Enemy*)entityHandler.getEntity(enemyId);

	GAME::GameInput input(*player);

	if(!player->loadSprite(output.renderer))
		{
        showErrorMessage("player.loadSprite() failed");
        goto exit;
        }
    player->loadBoundingBox((double)player->sprite->rect.w, (double)player->sprite->rect.h);

    if(!enemy->loadSprite(output.renderer))
		{
        showErrorMessage("enemy.loadSprite() failed");
        goto exit;
        }
    enemy->loadBoundingBox((double)enemy->sprite->rect.w, (double)enemy->sprite->rect.h);

    enemy->initStateMachine(*player);

    start = SDL_GetTicks();

    while(input.handle())
        {
        end = SDL_GetTicks();
        entityHandler.process((double)(end - start) / 1000.0);
        output.render();
        start = end;
        }
    exit:
    SDL_Quit();
    }