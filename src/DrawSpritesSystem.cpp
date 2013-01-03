#include "DrawSpritesSystem.h"
#include "PongComponents.h"

namespace Pong{

    namespace Systems{

        void DrawSpritesSystem::process(const std::vector<std::tr1::shared_ptr<Engine::Entity>> &entities, Engine::Canvas &mainScreen){

            for(auto entity : entities){
                auto component = entity->getComponent<Components::SpatialComponent>("sprite"); 
                mainScreen.drawDrawable(component->sprite, (int)component->x, (int)component->y);
            }

        }
    }
}
