#pragma once
#include <tr1/memory>
#include <vector>
#include "Entity.h"
#include "System.h"


namespace Engine{

    class World{

        public:
            void addEntity(Entity *entity);
            void addSystem(System *system);

            //process all systems
            void process(int deltaInMS);


        private:
            std::vector<std::tr1::shared_ptr<Entity>> entities;
            std::vector<std::tr1::shared_ptr<System>> systems;
    };

}
