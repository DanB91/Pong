#pragma once
#include <vector>
#include <tr1/memory>
#include <SDL/SDL.h>
#include "GameState.h"
#include "Canvas.h"
namespace Engine{
    class GameEngine{

        public:
            void pushState(GameState *gs);
            void popState();
            void startGameLoop();
	    int getViewPortHeight() {return viewPortHeight;}
	    int getViewPortWidth() { return viewPortWidth; }
            void quit() {running = false;}	


            ~GameEngine();
            GameEngine(int width, int height, bool fullscreen = false)
                :running(true), isFullscreen(fullscreen),
                mainScreen(width, height, fullscreen), viewPortWidth(width), viewPortHeight(height)
        {}

        private:
            Canvas mainScreen;
            bool running;  //tells if the game is running
            std::vector<std::tr1::shared_ptr<GameState>> gameStates; //holds the states of a game
            bool isFullscreen;
	    int viewPortHeight, viewPortWidth;

            void init();
            void handleEvents(SDL_Event &event);
            void update(int deltaInMS);
            void draw();


    };
}
