#pragma once
#include <SDL.h>
#include "Graphics.h"

class Map
{
public:
	Map();
	~Map();

	void draw(Graphics& argGfx, SDL_Point camOffset);
	SDL_Rect getMapBoundaries();
private:
	SDL_Rect mapBoundaries = { 0, 0, 1000, 800 };
	const int worldX = 0;
	const int worldY = 0;
	const Color color = White;
};

