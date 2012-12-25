#pragma once
#include <vector>
#include <memory>
#include <SDL/SDL.h>
#include "GameState.h"
#include "Canvas.h"

class GameEngine{

	public:
		void pushState(GameState *gs);
		void popState();
		void startGameLoop();
		void quit() {running = false;}	


		~GameEngine();
		GameEngine(int width, int height, bool fullscreen = false)
			:running(true), isFullscreen(fullscreen),
			mainScreen(width, height, fullscreen)
		{}

	private:
		Canvas mainScreen;
		bool running;  //tells if the game is running
		std::vector<std::shared_ptr<GameState>> gameStates; //holds the states of a game
		bool isFullscreen;

		void init();
		void handleEvents(SDL_Event &event);
		void update();
		void draw();
		

};
