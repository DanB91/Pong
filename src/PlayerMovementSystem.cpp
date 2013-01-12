#include "PlayerMovementSystem.h"
#include "PongComponents.h"
#include "Engine/Keyboard.h"
#include <iostream>

namespace Pong{

    namespace Systems{
        

        static void processMovement(Engine::Entity &e, Engine::GameEngine &engine, int delta)
        {
            auto spatial = e.getComponent<Components::SpatialComponent>("sprite");

            
            if(Engine::Keyboard::isKeyDown(SDLK_UP) && spatial->y > 0)
            {
                spatial->moveUp(delta);
            }
            else if(Engine::Keyboard::isKeyDown(SDLK_DOWN) && spatial->y < engine.getViewPortHeight() - spatial->height)
            {
                spatial->moveDown(delta);
            }

        }

        void PlayerMovementSystem::process(const std::vector<std::tr1::shared_ptr<Engine::Entity>> &entities, Engine::GameEngine &engine, int deltaInMS)
        {
            for(auto e : entities)
            {
               if(e->getID() == "player")
               {
                   processMovement(*e, engine, deltaInMS);
               }
            }
        }
    }
}
