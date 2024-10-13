#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Texture
{
public:
	Texture() {}
	~Texture() {}
	Texture(const char* fileName, SDL_Renderer* ren);
	void load(const char* fileName, SDL_Renderer* ren);
	void draw(int x, int y, SDL_Renderer* ren);
	void setTransparency(int alpha);

	int getTextureWidth();
	int getTextureHeight();
	void setDimensions(int argWidth, int argHeight);

	double getRotationAngle();
	void setRotationAngle(double argAngle);
private:
	SDL_Texture* tex = nullptr;
	SDL_Surface* srf = nullptr;
	int texWidth = 0;
	int texHeight = 0;
	SDL_Rect srcRect = {};	// In case we wanted to draw only a part of the texture
	SDL_Rect dstRect = {};	// Position and dimensions of the output texture

	//Rotating options
	double rotAngle = 0;
	SDL_Point* rotCenter = NULL;
	SDL_RendererFlip rotFlip = SDL_FLIP_NONE;
};

