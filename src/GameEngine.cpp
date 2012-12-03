#include "GameEngine.h"
void GameEngine::popState()
{
	delete gameStates.back();
	gameStates.pop_back();

	//if there are no more gamestates, quit the game
	if(gameStates.empty())
		quit();
}

void GameEngine::init()
{
	for(auto gs : gameStates)
		gs->init();
}

void GameEngine::update()
{
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
