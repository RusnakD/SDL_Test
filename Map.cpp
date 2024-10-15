#include "Map.h"

Map::Map()
{
}

Map::~Map()
{
}

void Map::draw(Graphics& gfx, SDL_Point camOffset)
{
	mapBoundaries.x = worldX - camOffset.x;
	mapBoundaries.y = worldY - camOffset.y;
	
	gfx.drawRect(&mapBoundaries, color);
}

SDL_Rect Map::getMapBoundaries()
{
	return mapBoundaries;
}
