#pragma once
#include "Engine/GameState.h"
#include "Engine/GameEngine.h"
#include "Engine/World.h"

namespace Pong{

    class GameplayState : public Engine::GameState
    {
        public:

            GameplayState(const std::string &id)
                : GameState(id)
            {}

            virtual void init();
            virtual void update(Engine::GameEngine &engine, int updateInMS);
            virtual void draw(Engine::Canvas &mainScreen);


        private:
            Engine::World world;

    };
}
