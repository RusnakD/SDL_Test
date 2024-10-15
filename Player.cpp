#include "Player.h"

void Player::draw(SDL_Renderer* argRen)
{
	playerTex.draw(xPos, yPos, argRen);
}

void Player::move(Camera &cam)
{
	// Verify if the player's not going to go beyond the edge of the currently set "map" (map rectangle more specifically)
	preventHittingEdgeOfMap();

	// Moves RIGHT until reaches the camera screen edge
	if (xVel > 0 && xPos <= (cam.getZoneRect().x + cam.getZoneRect().w) - playerTex.getTextureWidth()) { xPos += xVel; }
	// Camera moves RIGHT if player reaches camera screen edge
	if (xVel > 0 && xPos >= (cam.getZoneRect().x + cam.getZoneRect().w) - playerTex.getTextureWidth()) { cam.move(xVel, 0); }

	// Moves LEFT until reaches the camera screen edge
	if (xVel < 0 && xPos >= cam.getZoneRect().x) { xPos += xVel; }
	// Camera moves LEFT if player reaches camera screen edge
	if (xVel < 0 && xPos <= cam.getZoneRect().x) { cam.move(xVel, 0); }

	// Moves DOWN until reaches the camera screen edge
	if (yVel > 0 && yPos <= cam.getZoneRect().y + cam.getZoneRect().h - playerTex.getTextureHeight()) { yPos += yVel; }
	// Camera moves DOWN if player reaches camera screen edge
	if (yVel > 0 && yPos >= cam.getZoneRect().y + cam.getZoneRect().h - playerTex.getTextureHeight()) { cam.move(0, yVel); }

	// Moves UP until reaches the camera screen edge
	if (yVel < 0 && yPos >= cam.getZoneRect().y) { yPos += yVel; }
	// Camera moves UP if player reaches camera screen edge
	if (yVel < 0 && yPos <= cam.getZoneRect().y) { cam.move(0, yVel); }

	updateWorldPosition(cam);
}

void Player::init(int x, int y, const char* textureName, SDL_Renderer* argRen)
{
	xPos = x;
	yPos = y;
	playerTex.load(textureName, argRen);
}

void Player::setVelocity(int argXVel, int argYVel)
{
	xVel = argXVel;
	yVel = argYVel;
}

void Player::setMapBoundaries(SDL_Rect mapRect)
{
	currentMap = mapRect;
}

int Player::getXVelocity()
{
	return xVel;
}

int Player::getYVelocity()
{
	return yVel;
}

int Player::getSpeed()
{
	return speed;
}

void Player::updateWorldPosition(Camera &cam)
{
	xPosWorld = xPos + cam.getOffset().x;
	yPosWorld = yPos + cam.getOffset().y;
}

SDL_Point Player::getPosition()
{
	return SDL_Point({ xPosWorld, yPosWorld });
}

SDL_Point Player::getScreenPosition()
{
	return SDL_Point({ xPos, yPos });
}

void Player::preventHittingEdgeOfMap()
{
	// LEFT edge
	if (xVel < 0 && (xPosWorld - speed) <= currentMap.x) { xVel = 0; }
	// RIGHT edge
	if (xVel > 0 && (xPosWorld + speed) >= currentMap.x + currentMap.w - playerTex.getTextureWidth()) { xVel = 0; }
	// UPPER edge
	if (yVel < 0 && (yPosWorld - speed) <= currentMap.y) { yVel = 0; }
	// BOTTOM edge
	if (yVel > 0 && (yPosWorld + speed) >= currentMap.y + currentMap.h - playerTex.getTextureHeight()) { yVel = 0; }
}
