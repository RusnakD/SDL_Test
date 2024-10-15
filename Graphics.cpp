#include "Graphics.h"

bool Graphics::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen) { flags = SDL_WINDOW_FULLSCREEN; }

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "SDL initialised." << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window) {
			std::cout << "Window created." << std::endl;
		}
		else {
			std::cout << "WINDOW CREATION FAILED" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (renderer) {
			std::cout << "Renderer created." << std::endl;
		}
		else {
			std::cout << "RENDERER CREATION FAILED" << std::endl;
		}

		return true;
	}
	else {
		std::cout << "SDL INIT FAILED" << std::endl;
	}

	return false;
}

SDL_Renderer* Graphics::getRenderer()
{
	return renderer;
}

void Graphics::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Graphics::setColor(Color col)
{
	SDL_SetRenderDrawColor(renderer, col.red, col.green, col.blue, 255);
}

void Graphics::setBackground(Color col)
{
	setColor(col);
	SDL_RenderClear(renderer);
}

void Graphics::startDrawing()
{
	setBackground(Black);
}

void Graphics::finishDrawing()
{
	// Display everything
	SDL_RenderPresent(renderer);
}

void Graphics::drawLine(int x1, int y1, int x2, int y2, Color col)
{
	setColor(col);
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void Graphics::drawRect(const SDL_Rect *rec, Color col)
{
	setColor(col);
	SDL_RenderDrawRect(renderer, rec);
}

void Graphics::drawCircle(int x, int y, int radius, Color col, bool fill)
{
	setColor(col);
	int i = 0, j = 0, dist = 0;

	for (i = (x - radius) ; i <= (x + radius); i++)
	{
		for (j = (y - radius) ; j <= (y + radius); j++)
		{
			// Distance between two points on a plane
			dist = int(sqrt((i - x) * (i - x) + (j - y) * (j - y)));	

			// If the distance equals our radius, it means that point belongs to the circle
			if (dist == radius || (fill == true && dist < radius)) {
				SDL_RenderDrawPoint(renderer, i, j);
			}				
		}
	}
}

void Graphics::drawSomething(SDL_Point camOffset)
{
	// Triangle
	drawLine(100 - camOffset.x, 200 - camOffset.y, 250 - camOffset.x, 350 - camOffset.y, Green);
	drawLine(250 - camOffset.x, 350 - camOffset.y, 100 - camOffset.x, 350 - camOffset.y, Green);
	drawLine(100 - camOffset.x, 350 - camOffset.y, 100 - camOffset.x, 200 - camOffset.y, Green);

	// Circle
	drawCircle(400 - camOffset.x, 280 - camOffset.y, 80, Red, false);

	// Rectangle
	SDL_Rect rect = { 580 - camOffset.x, 200 - camOffset.y, 170, 250 }; //x1, y1, w, h
	drawRect(&rect, Blue);
}
