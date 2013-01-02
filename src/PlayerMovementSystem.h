#include "Engine/UpdateSystem.h"

namespace Pong{

    namespace Systems {
        
        class PlayerMovementSystem : public Engine::UpdateSystem {

            virtual void process(const std::vector<std::tr1::shared_ptr<Engine::Entity>> &entities, Engine::GameEngine &engine, int deltaInMS); 

        };

    }
}
