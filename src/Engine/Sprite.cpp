#include "Sprite.h"
#include "SDLException.h"

namespace Engine{

    Sprite::~Sprite()
    {
        if(texture)
            SDL_FreeSurface(texture);
    }

    void Sprite::load()
    {
        SDL_Surface *temp;

        if((temp = IMG_Load(fileName.c_str())) == NULL)
            throw SDLException("Failed to load sprite");

        texture = SDL_DisplayFormat(temp);

        SDL_FreeSurface(temp);
    }

 

}
