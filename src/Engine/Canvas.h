#pragma once
#include <SDL/SDL.h>
#include "IDrawable.h"

namespace Engine{

    class Canvas{
        public:
            Canvas(int width, int height, bool fullscreen)
                : width(width), height(height), isFullscreen(fullscreen), canvas(NULL)
            {}

            void init();	
            void drawDrawable(IDrawable &surface, int posX, int posY);
            
            //flip the buffered to sprites to the screen
            void flip();

        private:
            SDL_Surface *canvas;

            int width;
            int height;
            bool isFullscreen;
    };
}
