#include "SDLException.h"
#include "Canvas.h"

namespace Engine{
    void Canvas::init()
    {
        Uint32 sdlFlags = SDL_HWSURFACE | SDL_DOUBLEBUF;



        if(isFullscreen) sdlFlags |= SDL_FULLSCREEN;

        if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
            throw SDLException("SDL init failed");

        if((canvas = SDL_SetVideoMode(width, height, 32, sdlFlags)) == NULL)
            throw SDLException("Screen initialization failed");
    }

    void Canvas::drawDrawable(IDrawable &surface, int posX, int posY)
    {
        SDL_Surface *sdlSurface = surface.getSDLSurface();
        SDL_Rect screenPos;

        screenPos.x = posX;
        screenPos.y = posY;

        SDL_BlitSurface(sdlSurface, NULL, canvas, &screenPos);


    }

    void Canvas::flip()
    {
        SDL_Flip(canvas);
    }
}
