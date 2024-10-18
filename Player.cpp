#include "Player.h"

void Player::draw(SDL_Renderer* argRen)
{
	playerTex.draw(xPos, yPos, argRen);
}

void Player::move(Camera &cam)
{
	// Verify if the player's not going to go beyond the edge of the currently set "map" (map rectangle more specifically)
	preventHittingEdgeOfMap(cam);

	// Defining edges of camera's dead zone where player moves freely. Colliding with the edges results in camera shift.
	int deadZoneRightEdge = cam.getZoneRect().x + cam.getZoneRect().w - playerTex.getTextureWidth();
	int deadZoneBottomEdge = cam.getZoneRect().y + cam.getZoneRect().h - playerTex.getTextureHeight();

	// Player movement
	if (xVel > 0 && xPos <= deadZoneRightEdge)		{ xPos += xVel; }
	if (xVel < 0 && xPos >= cam.getZoneRect().x)	{ xPos += xVel; }
	if (yVel > 0 && yPos <= deadZoneBottomEdge)		{ yPos += yVel; }
	if (yVel < 0 && yPos >= cam.getZoneRect().y)	{ yPos += yVel; }

	updateWorldPosition(cam);

	// Camera movement
	if (xPos <= cam.getZoneRect().x) { cam.move(xVel, 0); }
	if (xPos >= deadZoneRightEdge) { cam.move(xVel, 0); }
	if (yPos <= cam.getZoneRect().y) { cam.move(0, yVel); }
	if (yPos >= deadZoneBottomEdge) { cam.move(0, yVel); }
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

Texture Player::getTexture()
{
	return playerTex;
}

void Player::preventHittingEdgeOfMap(Camera &cam)
{
	// LEFT edge
	if (xVel < 0 && (xPosWorld - speed) <= currentMap.x) {
		xVel = 0;
		xPosWorld = currentMap.x;  
		xPos = xPosWorld - cam.getOffset().x;  
	}

	// RIGHT edge
	if (xVel > 0 && (xPosWorld + speed) >= currentMap.x + currentMap.w - playerTex.getTextureWidth()) {
		xVel = 0;
		xPosWorld = currentMap.x + currentMap.w - playerTex.getTextureWidth();  
		xPos = xPosWorld - cam.getOffset().x;  
	}

	// UPPER edge
	if (yVel < 0 && (yPosWorld - speed) <= currentMap.y) {
		yVel = 0;
		yPosWorld = currentMap.y;			   
		yPos = yPosWorld - cam.getOffset().y; 
	}

	// BOTTOM edge
	if (yVel > 0 && (yPosWorld + speed) >= currentMap.y + currentMap.h - playerTex.getTextureHeight()) {
		yVel = 0;
		yPosWorld = currentMap.y + currentMap.h - playerTex.getTextureHeight();  
		yPos = yPosWorld - cam.getOffset().y;  
	}
}
