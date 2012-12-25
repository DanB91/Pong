#pragma once
#include <string>
#include <memory>
#include "GameEngine.h"
#include "Entity.h"

class Entity;

class Component{
    public:
        const std::string &getID() {return id;}
       
        virtual void init(){}
        virtual void update(GameEngine &game, int deltaInMS) = 0;
        virtual void draw(Canvas &mainScreen) {}

    protected:
        Component(const std::string id, Entity &owner) 
            : id(id), owner(owner)
        {}

        Entity &owner;
        const std::string id;

};
