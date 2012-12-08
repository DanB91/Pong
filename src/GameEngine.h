#pragma once
#include <vector>
#include <utility>
#include <SDL/SDL.h>
#include "GameState.h"

class GameEngine{

	public:
		void pushState(GameState *gs);
		void popState();
		void startGameLoop();


		~GameEngine();
		GameEngine(int width, int height, bool fullscreen = false)
			:running(true), resolution(width, height), isFullscreen(fullscreen)
		{}

	private:
		bool running;  //tells if the game is running
		std::vector<GameState*> gameStates; //holds the states of a game
		std::pair<int, int> resolution; //the resolution of the gamescreen
		bool isFullscreen;
		SDL_Surface *screen;

		void init();
		void handleEvents(SDL_Event &event);
		void update();
		void draw();
		void quit() {running = false;}

};
