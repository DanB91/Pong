#pragma once
#include <tr1/memory>
#include <vector>
#include "Entity.h"
#include "UpdateSystem.h"
#include "DrawSystem.h"

namespace Engine{

    class World{

        public:
            void addEntity(Entity *entity);

            //add system to be processed on update 
            void addUpdateSystem(UpdateSystem *system);

            //add system to be processed on draw
            void addDrawSystem(DrawSystem *system);

            //process all update systems
            void update(int deltaInMS);

            void draw(Canvas &mainScreen);


        private:
            std::vector<std::tr1::shared_ptr<Entity>> entities;
            std::vector<std::tr1::shared_ptr<UpdateSystem>> updateSystems;
            std::vector<std::tr1::shared_ptr<DrawSystem>> drawSystems;
    };

}
