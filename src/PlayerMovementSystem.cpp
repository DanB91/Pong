#include "PlayerMovementSystem.h"
#include "PongComponents.h"
#include "Engine/Keyboard.h"
#include <iostream>

namespace Pong{

    namespace Systems{
        

        static void processMovement(Engine::Entity &e)
        {
            auto spatial = e.getComponent<Components::SpatialComponent>("sprite");

            
            if(Engine::Keyboard::isKeyDown(SDLK_UP))
            {
                spatial->moveUp();
            }
            else if(Engine::Keyboard::isKeyDown(SDLK_DOWN))
            {
                spatial->moveDown();
            }

        }

        void PlayerMovementSystem::process(const std::vector<std::tr1::shared_ptr<Engine::Entity>> &entities, Engine::GameEngine &engine, int deltaInMS)
        {
            for(auto e : entities)
            {
               if(e->getID() == "player")
               {
                   processMovement(*e);
               }
            }
        }
    }
}
