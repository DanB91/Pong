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
	Uint32 sdlFlags = SDL_HWSURFACE | SDL_DOUBLEBUF;

	if(isFullscreen) sdlFlags |= SDL_FULLSCREEN;

	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
		throw SDLException("SDL init failed");

	if((screen = SDL_SetVideoMode(resolution.first, resolution.second, 32, sdlFlags)) == NULL)
		throw SDLException("Screen initialization failed");	

	for(auto gs : gameStates)
		gs->init();
}

void  GameEngine::handleEvents(SDL_Event &event)
{
	while(SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
			quit();

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

	gameStates.back()->update();

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
