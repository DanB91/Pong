#include <iostream>
#include <exception>
#include "Engine/GameEngine.h"


int main(int argc, char **argv)
{
    Engine::GameEngine engine(640, 480);
    
    try{
		engine.startGameLoop();
	}	
	catch(std::exception &e){
		std::cerr << e.what() << '\n';
	}

	return 0;
}
