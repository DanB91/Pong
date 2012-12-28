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

    void Canvas::drawSprite(Sprite &sprite, int posX, int posY)
    {
        SDL_Surface *spriteSurface = sprite.getSDLSurface();
        SDL_Rect screenPos;

        screenPos.x = posX;
        screenPos.y = posY;

        SDL_BlitSurface(spriteSurface, NULL, canvas, &screenPos);


    }

    void Canvas::flip()
    {
        SDL_Flip(canvas);
    }
}
