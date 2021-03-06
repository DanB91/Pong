#include <SDL/SDL.h>

namespace Engine{
    
    namespace Keyboard{

        bool isKeyDown(SDLKey key);
        bool isKeyUp(SDLKey key);
        bool isKeyTyped(SDLKey key);

        void setState(SDL_KeyboardEvent state);
    }
}
