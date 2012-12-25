#include "Entity.h"
#include "ComponentNotFoundException.h"

void Entity::addComponent(Component *c)
{
    components.push_back(std::shared_ptr<Component>(c));
}

Component& Entity::getComponent(const std::string componentID)
{
    for(auto comp : components)
    {
        if(comp->getID() == componentID)
            return *comp;
    }

    throw ComponentNotFoundException(componentID);
}

void Entity::init()
{
    for(auto comp : components)
    {
        comp->init();
    }
}

void Entity::update(GameEngine &game, int deltaInMS)
{
    for(auto comp : components)
    {
        comp->update(game, deltaInMS);
    }
}

void Entity::draw(Canvas &mainScreen)
{

    for(auto comp : components)
    {
        comp->draw(mainScreen);
    }
}
