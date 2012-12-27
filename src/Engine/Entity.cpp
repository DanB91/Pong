#include "Entity.h"

#include <stdexcept>

namespace Engine{
    void Entity::addComponent(const std::string &componentID, Component *c)
    {
        components[componentID] = std::tr1::shared_ptr<Component>(c);
    }

    template <class T>
        std::tr1::shared_ptr<T> Entity::getComponent(const std::string &componentID) const
    {
        try{
            return std::tr1::static_pointer_cast<T>(components.at(componentID));
        }
        catch(std::out_of_range &){
            throw ComponentNotFoundException(componentID);
        }
    }



}
