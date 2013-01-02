#pragma once
#include <tr1/memory>
#include <vector>
#include "Entity.h"
#include "GameEngine.h"

namespace Engine{
    
    class UpdateSystem{
        public:
            virtual void process(const std::vector<std::tr1::shared_ptr<Entity>> &entities, GameEngine &engine, int deltaInMS) = 0;
    };

}
