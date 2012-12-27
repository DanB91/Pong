#include "Keyboard.h"

namespace Engine{
    namespace Keyboard{

        static SDL_KeyboardEvent keyboardState;
        static SDL_KeyboardEvent previousKeyboardState;



        void setState(SDL_KeyboardEvent state)
        {
            previousKeyboardState = keyboardState;
            keyboardState = state;
        }	

        bool isKeyTyped(SDLKey key)
        {
            if(keyboardState.state == SDL_RELEASED && keyboardState.keysym.sym == key &&
                    previousKeyboardState.state == SDL_PRESSED && previousKeyboardState.keysym.sym == key)

                return true;

            return false;	
        }

        bool isKeyUp(SDLKey key)
        {
            if(keyboardState.state == SDL_RELEASED && keyboardState.keysym.sym == key)
                return true;

            return false;			
        }

        bool isKeyDown(SDLKey key)
        {
            if(keyboardState.state == SDL_PRESSED && keyboardState.keysym.sym == key)
                return true;

            return false;		
        }

    }
}
