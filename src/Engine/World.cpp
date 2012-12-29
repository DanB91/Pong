#include "World.h"

namespace Engine{

    void World::addEntity(Entity *entity)
    {
        entities.push_back(std::tr1::shared_ptr<Entity>(entity));
    }

    void World::addUpdateSystem(UpdateSystem *system)
    {
        updateSystems.push_back(std::tr1::shared_ptr<UpdateSystem>(system));
    }

    void World::addDrawSystem(DrawSystem *system)
    {
        drawSystems.push_back(std::tr1::shared_ptr<DrawSystem>(system));
    }


    void World::update(int deltaInMS)
    {
        for(auto proc : updateSystems){
            proc->process(entities, deltaInMS);
        }
    }

    void World::draw(Canvas &mainScreen)
    {
        for(auto proc : drawSystems){
            proc->process(entities, mainScreen);
        }
    }

}
