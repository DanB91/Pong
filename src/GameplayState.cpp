#include "GameplayState.h"
#include "Engine/Keyboard.h"
#include "PongComponents.h"
#include "DrawSpritesSystem.h"
#include "PlayerMovementSystem.h"

namespace Pong{


    static void createPlayer(Engine::World &world)
    {
        auto player = world.createEntity("player");
        player->addComponent("sprite", new Components::SpatialComponent(10, 0, 1, "../res/BallAndPaddle.png"));

       
    }

    

    void GameplayState::init()
    {
        createPlayer(world);
        world.addDrawSystem(new Systems::DrawSpritesSystem());
        world.addUpdateSystem(new Systems::PlayerMovementSystem());
     }

    void GameplayState::update(Engine::GameEngine &engine, int deltaInMS)
    {
        if(Engine::Keyboard::isKeyUp(SDLK_ESCAPE)){
            engine.quit();
        }

        world.update(engine, deltaInMS);
        
    }

    void GameplayState::draw(Engine::Canvas &mainScreen)
    {
        world.draw(mainScreen);
    }

}
