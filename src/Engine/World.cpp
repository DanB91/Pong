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
        for(auto sys : updateSystems){
            sys->process(entities, deltaInMS);
        }
    }

    void World::draw(Canvas &mainScreen)
    {
        for(auto sys : drawSystems){
            sys->process(entities, mainScreen);
        }
    }

}
