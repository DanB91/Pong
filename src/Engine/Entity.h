#pragma once
#include <memory>
#include <unordered_map>
#include <string>
#include "Component.h"


class Entity{
    public:

        void addComponent(const std::string &componentID, Component *component);
        Component &getComponent(const std::string &componentID);
        
    private:
        std::unordered_map<std::string, std::shared_ptr<Component>> components;
        

};
