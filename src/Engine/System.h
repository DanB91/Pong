#pragma once
#include <memory>
#include <vector>

class System{
    virtual void process(std::vector<std::shared_ptr<Entity>> entities) = 0;
};
