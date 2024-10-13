#include "Game.h"

Game::Game(const char* title, int width, int height, bool fullscreen)
{
	// If the console is not allowed, hide it
	HWND windowHandle = GetConsoleWindow();
	ShowWindow(windowHandle, SW_SHOW);

	if (!showConsole) {
		ShowWindow(windowHandle, SW_HIDE);
	}

	// Initializing the renderer
	if (gfx.init(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, fullscreen)) {
		isRunning = true;
		std::cout << "Game is running." << std::endl;
	}
	else {
		isRunning = false;
		std::cout << "sOmEtHiNg HaPpEnEd (aka Microsoft error lol)" << std::endl;
	}

	// Initializing objects and textures
	camera.setRenderer(gfx.getRenderer());

	player.init(200, 200, "img/smile.png", gfx.getRenderer());

	lightTex.load("img/light.png", gfx.getRenderer());
	lightTex.setTransparency(lightTransparency);
}

Game::~Game()
{
	gfx.clean();
	std::cout << "Cleaning done." << std::endl;
}

bool Game::running()
{
	return isRunning;
}

void Game::update()
{
	player.move();
	//player.rotate();		// Was just testing texture rotations
}

void Game::capFramerate()
{
	// Handling the frame rate, capping the FPS
	frameTime = SDL_GetTicks() - frameStart;
	if (frameDelay > frameTime) {
		SDL_Delay(frameDelay - frameTime);
	}
}

void Game::go()
{
	// Saving current time
	frameStart = SDL_GetTicks();

	// Handling events, updating positions, rendering graphics
	handleEvents();
	update();
	render();

	// Handling the frame rate, capping the FPS
	capFramerate();
}

void Game::render()
{
	gfx.startDrawing();

	gfx.drawSomething();
	player.draw();
	lightTex.draw(lightPosX - (lightTex.getTextureWidth() / 2), lightPosY - (lightTex.getTextureHeight() / 2), gfx.getRenderer());

	camera.drawDeadZone();		// This should be drawn on the top of everything, but it is at the bottom

	gfx.finishDrawing();
}
