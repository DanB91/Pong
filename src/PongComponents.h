#include "Engine/Component.h"
#include "Engine/Sprite.h"
#include <string>

namespace Pong{

    namespace Components{

        struct SpatialComponent : public Engine::Component{     
        
            int x, y, width, height;
            Engine::Sprite sprite;

            SpatialComponent(int x, int y, const std::string &spriteFileName)
                : sprite(spriteFileName), x(x), y(y)
            {
                sprite.load();
                height = sprite.getSDLSurface()->h;
                width = sprite.getSDLSurface()->w;
            }
        };

    }
}
