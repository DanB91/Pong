#include "World.h"

namespace Engine{

    void World::addEntity(Entity *entity)
    {
        entities.push_back(std::tr1::shared_ptr<Entity>(entity));
    }


    std::tr1::shared_ptr<Entity> World::createEntity(const std::string id)
    {
        std::tr1::shared_ptr<Entity> ret = std::tr1::shared_ptr<Entity>(new Entity(id));

        entities.push_back(ret);

        return ret;
    }
    
    void World::addUpdateSystem(UpdateSystem *system)
    {
        updateSystems.push_back(std::tr1::shared_ptr<UpdateSystem>(system));
    }

    void World::addDrawSystem(DrawSystem *system)
    {
        drawSystems.push_back(std::tr1::shared_ptr<DrawSystem>(system));
    }


    void World::update(Engine::GameEngine &engine, int deltaInMS)
    {
        for(auto sys : updateSystems){
            sys->process(entities, engine, deltaInMS);
        }
    }

    void World::draw(Canvas &mainScreen)
    {
        for(auto sys : drawSystems){
            sys->process(entities, mainScreen);
        }
    }
}
