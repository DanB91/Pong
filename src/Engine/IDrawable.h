#pragma once
#include <SDL/SDL.h>

/*
 * This interface is implemented in classes that have SDL_Surface that wants
 * to be drawn to a Canvas object (i.e. normally the main screen)
 */


class IDrawable{

    public:
        virtual SDL_Surface *getSDLSurface() = 0;
};
