#pragma once
#include <memory>
#include <vector>
#include <utility>
#include <string>
#include "Component.h"
#include "GameEngine.h"

class Component;

class Entity{
    public:

        Entity(const std::string id, double posX, double posY)
            : id(id), posX(posX), posY(posY)
        {}

        const std::string &getID() const { return id; } 

        double getX() const { return posX; } 
        double getY() const { return posY; } 

        void setX(double x) { posX = x; }
        void setY(double y) { posY = y; }

        void init();
        void update(GameEngine &game, int deltaInMS);
        void draw(Canvas &mainScreen);

        void addComponent(Component *component);
        Component &getComponent(const std::string componentID);
        
    private:
        std::vector<std::shared_ptr<Component>> components;
        const std::string id;
        double posX;
        double posY;


};
