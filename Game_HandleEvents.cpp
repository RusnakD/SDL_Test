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
				player.setVelocity(player.getSpeed(), player.getYVelocity());
				break;
			case SDLK_LEFT:
				player.setVelocity(-player.getSpeed(), player.getYVelocity());
				break;
			case SDLK_UP:
				player.setVelocity(player.getXVelocity(), -player.getSpeed());
				break;
			case SDLK_DOWN:
				player.setVelocity(player.getXVelocity(), player.getSpeed());
				break;
			default:
				break;
			}
			break;

		case SDL_KEYUP:
			switch (ent.key.keysym.sym) {
			case SDLK_RIGHT:
				if (player.getXVelocity() > 0) { player.setVelocity(0, player.getYVelocity()); }
				break;
			case SDLK_LEFT:
				if (player.getXVelocity() < 0) { player.setVelocity(0, player.getYVelocity()); }
				break;
			case SDLK_UP:
				if (player.getYVelocity() < 0) { player.setVelocity(player.getXVelocity(), 0); }
				break;
			case SDLK_DOWN:
				if (player.getYVelocity() > 0) { player.setVelocity(player.getXVelocity(), 0); }
				break;
			case SDLK_t:
				printDebugInfo();
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