#include "SDLException.h"
#include "Canvas.h"

void Canvas::init()
{
	Uint32 sdlFlags = SDL_HWSURFACE | SDL_DOUBLEBUF;



	if(isFullscreen) sdlFlags |= SDL_FULLSCREEN;

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		throw SDLException("SDL init failed");

	if((canvas = SDL_SetVideoMode(width, height, 32, sdlFlags)) == NULL)
		throw SDLException("Screen initialization failed");
}
