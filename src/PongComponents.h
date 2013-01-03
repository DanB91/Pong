#include "Engine/Component.h"
#include "Engine/Sprite.h"
#include <string>

namespace Pong{

    namespace Components{

        struct SpatialComponent : public Engine::Component{     
        
            float x, y, velocity;
	    int width, height;
            Engine::Sprite sprite;

            SpatialComponent(int x, int y, int velocity, const std::string &spriteFileName)
                : sprite(spriteFileName), x(x), y(y), velocity(velocity)
            {
                sprite.load();
                height = sprite.getSDLSurface()->h;
                width = sprite.getSDLSurface()->w;
            }
            
            void moveUp(int delta){ y -= velocity * delta; }
            void moveDown(int delta) { y += velocity * delta; }


        };

       

    }
}
