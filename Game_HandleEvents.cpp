#include "Game.h"

void Game::handleEvents()
{
	while (SDL_PollEvent(&ent))
	{
		switch (ent.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (ent.key.keysym.sym) {
			case SDLK_RIGHT:
				player.xvel = player.speed;
				break;
			case SDLK_LEFT:
				player.xvel = -player.speed;
				break;
			case SDLK_UP:
				player.yvel = -player.speed;
				break;
			case SDLK_DOWN:
				player.yvel = player.speed;
				break;
			default:
				break;
			}
			break;

		case SDL_KEYUP:
			switch (ent.key.keysym.sym) {
			case SDLK_RIGHT:
				if (player.xvel > 0) { player.xvel = 0; }
				break;
			case SDLK_LEFT:
				if (player.xvel < 0) { player.xvel = 0; }
				break;
			case SDLK_UP:
				if (player.yvel < 0) { player.yvel = 0; }
				break;
			case SDLK_DOWN:
				if (player.yvel > 0) { player.yvel = 0; }
				break;

			default:
				break;
			}
			break;

		case SDL_MOUSEMOTION:
			lightPosX = ent.motion.x;
			lightPosY = ent.motion.y;
			break;

		default:
			break;
		}
	}
}