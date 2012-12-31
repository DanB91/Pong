#include "Engine/DrawSystem.h"

namespace Pong{

    namespace Systems{

        class DrawSpritesSystem : public Engine::DrawSystem{

            virtual void process(const std::vector<std::tr1::shared_ptr<Engine::Entity>> &entities, Engine::Canvas &mainscreen);
        };
    }
}
