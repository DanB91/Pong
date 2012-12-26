#include "Entity.h"
#include "ComponentNotFoundException.h"

void Entity::addComponent(const std::string &componentID, Component *c)
{
    components[componentID] = std::shared_ptr<Component>(c);
}

Component& Entity::getComponent(const std::string &componentID)
{
    try{
        return *components.at(componentID);
    }
    catch(std::out_of_range &){
        throw ComponentNotFoundException(componentID);
    }
}




