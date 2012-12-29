#include <iostream>
#include <exception>
#include "Engine/GameEngine.h"
#include "GameplayState.h"



int main(int argc, char **argv)
{
    Engine::GameEngine engine(640, 480);
    
    engine.pushState(new Pong::GameplayState("gameplay"));

    try{
		engine.startGameLoop();
	}	
	catch(std::exception &e){
		std::cerr << e.what() << '\n';
	}

	return 0;
}
