#include <SDL/SDL.h>
#include "GameEngine.h"
#include "SDLException.h"

GameEngine::~GameEngine()
{
	SDL_Quit();
}

void GameEngine::pushState(GameState *gs)
{
	gameStates.push_back(gs);
}

void GameEngine::popState()
{
	delete gameStates.back();
	gameStates.pop_back();

}

void GameEngine::init()
{
	mainScreen.init();

	for(auto gs : gameStates)
		gs->init();
}

void  GameEngine::handleEvents(SDL_Event &event)
{
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			quit();
			return;
		}

		gameStates.back()->handleEvent(event);		
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
