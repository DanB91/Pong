#pragma once

#include <SDL/SDL.h>
#include<string>


namespace Engine{
    class Sprite{

        public:
            ~Sprite();
            Sprite(const std::string &textureFileName)
                : fileName(textureFileName), texture(NULL)
            {}

            void load();
            
            SDL_Surface *getSDLSurface() { return texture; }




        protected:
            const std::string fileName;	
            SDL_Surface *texture;
    };

}
