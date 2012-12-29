#include "GameplayState.h"
#include "Engine/Keyboard.h"

namespace Pong{

    void GameplayState::init()
    {

    }

    void GameplayState::update(Engine::GameEngine &engine, int deltaInMS)
    {
        if(Engine::Keyboard::isKeyUp(SDLK_ESCAPE)){
            engine.quit();
        }

        world.update(deltaInMS);
        
    }

    void GameplayState::draw(Engine::Canvas &mainScreen)
    {
        world.draw(mainScreen);
    }

}
