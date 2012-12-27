#pragma once
#include <tr1/memory>
#include <map>
#include <string>
#include "Component.h"
#include "ComponentNotFoundException.h"

namespace Engine{
    class Entity{
        public:
            //component is stored in shared pointer
            void addComponent(const std::string &componentID, Component *component);

            //throws ComponentNotFoundException if component is not found
            Component &getComponent(const std::string &componentID) const;  

        private:
            std::map<std::string, std::tr1::shared_ptr<Component>> components;


    };
}
