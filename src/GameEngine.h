#include <vector>
#include "GameState.h"

class GameEngine{

	public:
		void pushState(GameState *gs);
		void popState();
		void startGameLoop();


		GameEngine()
			:running(true) 
		{}

	private:
		bool running;  //tells if the game is running
		std::vector<GameState*> gameStates; //holds the states of a game

		void init();
		void update();
		void draw();
		void quit() {running = false;}

};
