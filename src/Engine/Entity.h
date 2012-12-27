#pragma once
#include <tr1/memory>
#include <map>
#include <string>
#include "Component.h"
#include "ComponentNotFoundException.h"

namespace Engine{
    class Entity{
        public:

            Entity(const std::string &id)
                : id(id)
            {}

            //component is stored in shared pointer
            void addComponent(const std::string &componentID, Component *component);

            //throws ComponentNotFoundException if component is not found
            //class T must be a subclass of component
            template <class T = Component> T &getComponent(const std::string &componentID) const;  

        private:
            std::map<std::string, std::tr1::shared_ptr<Component>> components;
            std::string id;

    };

}

#include "Entity.cpp"
