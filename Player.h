#pragma once
#include "Graphics.h"
#include "Texture.h"
#include "Camera.h"
#include "Map.h"

class Player
{
public:
	void draw(SDL_Renderer* argRen);
	void move(Camera &cam);
	void init(int x, int y, const char* textureName, SDL_Renderer* argRen);
	void setVelocity(int argXVel, int argYVel);
	void setMapBoundaries(SDL_Rect mapRect);
	int getXVelocity();
	int getYVelocity();
	int getSpeed();
	void updateWorldPosition(Camera &cam);
	void preventHittingEdgeOfMap(Camera &cam);
	SDL_Point getPosition();
	SDL_Point getScreenPosition();
	Texture getTexture();
private:
	int speed = 7;
	int xVel = 0;
	int yVel = 0;

	// Screen coords
	int xPos = 400;
	int yPos = 400;

	// World coords
	int xPosWorld = 400;
	int yPosWorld = 400;
	
	Texture playerTex;
	SDL_Rect currentMap = {};
};

