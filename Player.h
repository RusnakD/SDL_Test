#pragma once
#include "Graphics.h"
#include "Texture.h"

class Player
{
public:
	void draw();
	void move();
	void init(int x, int y, const char* textureName, SDL_Renderer* argRen);
	void rotate();

	int speed = 5;
	int xvel = 0;
	int yvel = 0;
private:
	int xpos = 400;
	int ypos = 400;
	const int rotSpeed = 2;

	Texture playerTex;
	SDL_Renderer* ren;
};

