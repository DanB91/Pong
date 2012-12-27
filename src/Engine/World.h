#include <tr1/memory>
#include <map>
#include "Entity.h"
#include "System.h"


namespace Engine{

    class World{

        public:
            void addEntity(Entity *entity);
            void addSystem(System *system);


        private:
            
    };

}
