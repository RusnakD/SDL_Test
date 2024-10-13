#pragma once
#include "Graphics.h"
#include "Player.h"
#include "Texture.h"
#include "Camera.h"

class Game
{
public:
	Game(const char* title, int width, int height, bool fullscreen);
	~Game();

	// Main loop
	void go();

	bool running();
private:
	bool showConsole = true;
	bool isRunning = false;

	// Main loop functions
	void handleEvents();
	void update();
	void render();
	void capFramerate();

	// Constants for capping the FPS / controling the game speed)
	UINT32 frameStart = 0, frameTime = 0;
	const int targetFPS = 60;
	const int frameDelay = 1000 / targetFPS;

	// Creating the system objects
	SDL_Event ent;
	Graphics gfx;
	Camera camera;

	// Game objects
	Player player;

	// Testing "light" texture which is attached to mouse movement
	Texture lightTex;
	int lightPosX = scrWidth / 2;		// Just initial position
	int lightPosY = scrHeight / 2;		// Just initial position 
	int lightTransparency = 60;
};

