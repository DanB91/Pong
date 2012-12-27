#pragma once
#include "Canvas.h"

namespace Engine{
    
    class GameEngine;
    
    class GameState
    {
        public:
            virtual ~GameState(){};
            virtual void init() = 0;
            virtual void handleEvent(const SDL_Event &event, GameEngine &engine) = 0;
            virtual void update(GameEngine &engine) = 0;
            virtual void draw(Canvas &mainScreen) = 0;
    };
}
