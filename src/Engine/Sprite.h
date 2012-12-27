#pragma once

#include <SDL/SDL.h>
#include<string>

#include "Canvas.h"

namespace Engine{
    class Sprite{

        public:
            ~Sprite();
            Sprite(const std::string &textureFileName)
                : fileName(textureFileName), texture(NULL)
            {}

            void load();
            void draw(Canvas &mainScreen, int x, int y);




        protected:
            const std::string fileName;	
            SDL_Surface *texture;
    };

}
