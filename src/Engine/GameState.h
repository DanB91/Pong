#pragma once
#include <string>
#include "Canvas.h"

namespace Engine{
    
    class GameEngine;
    
    class GameState
    {
        public:

            GameState(){}

            GameState(const std::string &id)
                :id(id)
            {}

            const std::string &getId(){ return id; }

            virtual ~GameState(){};
            virtual void init() = 0;
            virtual void handleEvent(const SDL_Event &event, GameEngine &engine){};
            virtual void update(GameEngine &engine, int deltaInMS) = 0;
            virtual void draw(Canvas &mainScreen) = 0;


        private:
            std::string id;
    };
}
