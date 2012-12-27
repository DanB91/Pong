#pragma once
#include <tr1/memory>
#include <vector>

namespace Engine{
    class System{
        public:
            virtual void process(const std::vector<std::tr1::shared_ptr<Entity>> &entities, int deltaInMS) = 0;
    };

}
