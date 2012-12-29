#include "Entity.h"


namespace Engine{
    void Entity::addComponent(const std::string &componentID, Component *c)
    {
        components[componentID] = std::tr1::shared_ptr<Component>(c);
    }




}
