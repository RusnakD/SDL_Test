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