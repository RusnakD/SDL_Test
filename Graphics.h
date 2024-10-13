#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Windows.h>
#include <iostream>
#include "Colors.h"
#include "Texture.h"

#define scrWidth 800
#define scrHeight 600
#define scrFullscreen false

class Graphics
{
public:
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	SDL_Renderer* getRenderer();
	void clean();

	void setColor(Color col);
	void setBackground(Color col);
	void startDrawing();
	void finishDrawing();

	void drawLine(int x1, int y1, int x2, int y2, Color col);
	void drawRect(const SDL_Rect *rec, Color col);
	void drawCircle(int x, int y, int radius, Color col, bool fill);

	void drawSomething();
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	Texture testTex;
};

