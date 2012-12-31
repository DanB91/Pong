#include "GameplayState.h"
#include "Engine/Keyboard.h"
#include "PongComponents.h"
#include "DrawSpritesSystem.h"

namespace Pong{


    static Engine::Entity *createPlayer()
    {
        Engine::Entity *ret = new Engine::Entity("player");
        ret->addComponent("sprite", new Components::SpatialComponent(0, 0, "../res/BallAndPaddle.png"));

        return ret;
    }

    

    void GameplayState::init()
    {
        world.addEntity(createPlayer());
        world.addDrawSystem(new Systems::DrawSpritesSystem()); 
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
