#include <SDL/SDL.h>
#include "GameEngine.h"
#include "SDLException.h"
#include "Keyboard.h"
namespace Engine{
    
    GameEngine::~GameEngine()
    {
        SDL_Quit();
    }

    void GameEngine::pushState(GameState *gs)
    {
        gameStates.push_back(std::tr1::shared_ptr<GameState>(gs));

    }

    void GameEngine::popState()
    {
        gameStates.pop_back();
    }

    void GameEngine::init()
    {
        mainScreen.init();

        for(auto gs : gameStates){
            gs->init();

        }
    }

    void  GameEngine::handleEvents(SDL_Event &event)
    {
        while(SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_QUIT:
                    quit();
                    return;
                case SDL_KEYDOWN:
                    Keyboard::setState(event.key);
                    break;
                case SDL_KEYUP:
                    Keyboard::setState(event.key);
                    break;
            }


            gameStates.back()->handleEvent(event, *this);		
        }
    }

    void GameEngine::update(int detlaInMS)
    {
        SDL_Event event;

        //if there are no more gamestates, quit the game
        if(gameStates.empty())
        {
            quit();
            return;
        }

        handleEvents(event);

        gameStates.back()->update(*this, detlaInMS);

    }

    void GameEngine::draw()
    {
        for(auto gs : gameStates)
            gs->draw(mainScreen);

        mainScreen.flip();

    }



    void GameEngine::startGameLoop()
    {
        int deltaInMS = 0;
        int startTime;


        init();

        startTime = SDL_GetTicks();
        while(running)
        {

            update(deltaInMS);
            draw();
            
            deltaInMS = SDL_GetTicks() - startTime;
            startTime = SDL_GetTicks();

            

        }
    }
}
