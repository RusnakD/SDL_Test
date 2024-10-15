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

	// This will give the player the map's rect (edges) that are checked whenever player moves (to prevent going out of the map)
	player.setMapBoundaries(map.getMapBoundaries());

	lightTex.load("img/light.png", gfx.getRenderer());
	lightTex.setTransparency(lightTransparency);
}

Game::~Game()
{
	gfx.clean();
	std::cout << "Cleaning done." << std::endl;
}

void Game::printDebugInfo()
{
	using namespace std;
	cout << endl << endl;
	cout << "Player worldX: " << player.getPosition().x << endl;
	cout << "Player worldY: " << player.getPosition().y << endl;
	cout << "Player xPos: " << player.getScreenPosition().x << endl;
	cout << "Player yPos: " << player.getScreenPosition().y << endl;
}

bool Game::running()
{
	return isRunning;
}

void Game::update()
{
	player.move(camera);
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

	map.draw(gfx, camera.getOffset());
	gfx.drawSomething(camera.getOffset());
	player.draw(gfx.getRenderer());
	//lightTex.draw(lightPosX - (lightTex.getTextureWidth() / 2), lightPosY - (lightTex.getTextureHeight() / 2), gfx.getRenderer());
	//camera.drawDeadZone();

	gfx.finishDrawing();
}
