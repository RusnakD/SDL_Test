#include "Player.h"

void Player::draw()
{
	playerTex.draw(xpos, ypos, ren);
}

void Player::move()
{
	xpos += xvel;
	ypos += yvel;
}

void Player::init(int x, int y, const char* textureName, SDL_Renderer* argRen)
{
	xpos = x;
	ypos = y;
	ren = argRen;
	playerTex.load(textureName, ren);
	//playerTex.setTransparency(128);
}

void Player::rotate()
{
	playerTex.setRotationAngle(playerTex.getRotationAngle() + rotSpeed);
}
