#pragma once
#include <tr1/memory>
#include <map>
#include <string>
#include "Component.h"


class Entity{
    public:
        void addComponent(const std::string &componentID, Component *component);
        Component &getComponent(const std::string &componentID) const;
        
    private:
        std::map<std::string, std::tr1::shared_ptr<Component>> components;
        

};
