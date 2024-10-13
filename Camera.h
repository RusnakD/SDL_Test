#pragma once
#include <SDL.h>
#include "Graphics.h"

class Camera
{
public:
	Camera();
	~Camera();

	void move(int diffX, int diffY);
	void setRenderer(SDL_Renderer* argRen);
	void drawDeadZone();

	SDL_Point getOffset();
private:
	// This will be used to calculate drawing position of objects on the screen
	SDL_Point offset = { 0, 0 };

	// Place where player can move freely before the camera starts shifting
	SDL_Rect deadZone = {};

	// Margin between the dead zone rectangle and the edge of the screen / window
	const int deadZoneMargin = 100;		

	// Used for drawing the deadzone rectangle - testing purposes only
	SDL_Renderer* ren = nullptr;
};

