=#pragma once
#include <tr1/memory>
#include <vector>

namespace Engine{
    class System{
        virtual void process(std::vector<std::shared_ptr<Entity>> entities) = 0;
    };

}
