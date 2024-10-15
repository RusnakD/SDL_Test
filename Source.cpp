#include "Game.h"
#undef main

int main()
{
	Game game("some SDL test or whatever", scrWidth, scrHeight, scrFullscreen);

	while (game.running())
	{
		game.go();
	}

	return 0;
}

// BOUNDARIES COLLISION

// set camera to player's point at start
// 
// re-do camera movements from player to camera directly?
// camera - free mode / attach to player??