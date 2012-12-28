#pragma once

#include <SDL/SDL.h>
#include<string>
#include "IDrawable.h"


namespace Engine{
    class Sprite : public IDrawable{

        public:
            ~Sprite();
            Sprite(const std::string &textureFileName)
                : fileName(textureFileName), texture(NULL)
            {}

            void load();
            
            virtual SDL_Surface *getSDLSurface() { return texture; }




        protected:
            const std::string fileName;	
            SDL_Surface *texture;
    };

}
