#include "Entity.h"
#include "ComponentNotFoundException.h"
#include <stdexcept>

void Entity::addComponent(const std::string &componentID, Component *c)
{
    components[componentID] = std::tr1::shared_ptr<Component>(c);
}

Component& Entity::getComponent(const std::string &componentID) const
{
    try{
        return *components.at(componentID);
    }
    catch(std::out_of_range &){
        throw ComponentNotFoundException(componentID);
    }
}




