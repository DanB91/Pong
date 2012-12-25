#include <SDL/SDL.h>
#include "GameEngine.h"
#include "SDLException.h"
#include "Keyboard.h"

GameEngine::~GameEngine()
{
	SDL_Quit();
}

void GameEngine::pushState(GameState *gs)
{
	gameStates.push_back(std::shared_ptr<GameState>(gs));

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

void GameEngine::update()
{
	SDL_Event event;

	//if there are no more gamestates, quit the game
	if(gameStates.empty())
	{
		quit();
		return;
	}

	handleEvents(event);

	gameStates.back()->update(*this);

}

void GameEngine::draw()
{
	for(auto gs : gameStates)
		gs->draw(mainScreen);
}



void GameEngine::startGameLoop()
{
	init();


	while(running)
	{
		update();
		draw();
	}
}
