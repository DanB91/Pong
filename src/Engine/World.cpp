#include "World.h"

namespace Engine{

    void World::addEntity(Entity *entity)
    {
        entities.push_back(std::tr1::shared_ptr<Entity>(entity));
    }

    void World::addSystem(System *system)
    {
        systems.push_back(std::tr1::shared_ptr<System>(system));
    }

    void World::process(int deltaInMS)
    {
        for(auto proc : systems){
            proc->process(entities, deltaInMS);
        }
    }

}
