#include "Texture.h"

Texture::Texture(const char* fileName, SDL_Renderer* ren)
{
	load(fileName, ren);
}

void Texture::load(const char* fileName, SDL_Renderer* ren)
{
	// Loading the image
	srf = IMG_Load(fileName);

	// Loading the surface into the texture, releasing the surface
	tex = SDL_CreateTextureFromSurface(ren, srf);
	SDL_FreeSurface(srf);

	// Notification / error handling
	std::cout << fileName;
	if (srf == NULL or tex == NULL) {
		std::cout << " couldn't be loaded" << std::endl;
	}
	else {
		std::cout << " loaded successfully" << std::endl;
	}

	// Getting the image's dimensions
	SDL_QueryTexture(tex, NULL, NULL, &texWidth, &texHeight);

	// Updating the destination rectangle where texture will be drawn
	dstRect.w = texWidth;
	dstRect.h = texHeight;
}

void Texture::draw(int x, int y, SDL_Renderer* ren)
{
	// Setting the position where will the texture be displayed
	dstRect.x = x;
	dstRect.y = y;

	// Rendering the texture itself
	SDL_RenderCopyEx(ren, tex, NULL, &dstRect, rotAngle, rotCenter, rotFlip);
}

void Texture::setTransparency(int alpha)
{
	SDL_SetTextureBlendMode(tex, SDL_BLENDMODE_BLEND);
	SDL_SetTextureAlphaMod(tex, alpha);
}

int Texture::getTextureWidth()
{
	texWidth = dstRect.w;
	return texWidth;
}

int Texture::getTextureHeight()
{
	texHeight = dstRect.h;
	return texHeight;
}

void Texture::setDimensions(int argWidth, int argHeight)
{
	dstRect.w = argWidth;
	dstRect.h = argHeight;
}

double Texture::getRotationAngle()
{
	return rotAngle;
}

void Texture::setRotationAngle(double argAngle)
{
	rotAngle = argAngle;
}
