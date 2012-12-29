#pragma once
#include <tr1/memory>
#include <vector>
#include "Canvas.h"

namespace Engine{
    
    class DrawSystem{
        public:
            virtual void process(const std::vector<std::tr1::shared_ptr<Entity>> &entities, Canvas &mainScreen) = 0;
    };

}
