#include <iostream>
#include <exception>
#include "GameEngine.h"


int main(int argc, char **argv)
{
	GameEngine engine(640, 480);

	try{
		engine.startGameLoop();
	}	
	catch(std::exception &e){
		std::cerr << e.what() << '\n';
	}

	return 0;
}
