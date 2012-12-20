#include "Sprite.h"
#include "SDLException.h"

Sprite::~Sprite()
{
	SDL_FreeSurface(texture);
}

void Sprite::load()
{
	SDL_Surface *temp;

	if((temp = SDL_LoadBMP(fileName.c_str())) == NULL)
		throw SDLException("Failed to load sprite");

	texture = SDL_DisplayFormat(temp);

	SDL_FreeSurface(temp);
}

void Sprite::draw(Canvas &mainScreen, int x, int y)
{
	SDL_Surface *screen = mainScreen.getSDLSurface();
	SDL_Rect screenPos;

	screenPos.x = x;
	screenPos.y = y;

	SDL_BlitSurface(texture, NULL, screen, &screenPos);
	SDL_Flip(screen);
}
