#include "SDL2/SDL.h"
#include "game_input.h"
#include "game_entity.h"
#include "pe_output.h"
#include "pe_entity.h"
#include "pe_entityhandler.h"
/*
pe_paths.h sisältää hardcodattuna tarvittavat polut ja kansioiden nimet. Tee siitä järkevämpi
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

	int playerId = (entityHandler.addEntity(GAME::Player(200, 200))).id;
    int aiId = (entityHandler.addEntity(PE::Ai(300, 300))).id;
    PE::Entity &player = entityHandler.getEntity(playerId);
    PE::Entity &ai = entityHandler.getEntity(aiId);
	GAME::GameInput input(player);
	if(!player.loadSprite(output.renderer))
		{
        showErrorMessage("player.loadSprite() failed");
        goto exit;
        }
    player.loadBoundingBox((double)player.sprite->rect.w, (double)player.sprite->rect.h);
    if(!ai.loadSprite(output.renderer))
		{
        showErrorMessage("ai.loadSprite() failed");
        goto exit;
        }
    ai.loadBoundingBox((double)ai.sprite->rect.w, (double)ai.sprite->rect.h);

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