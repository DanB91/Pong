#include "Engine/GameState.h"
#include "Engine/Sprite.h"
#include "Engine/Keyboard.h"
#include "Engine/GameEngine.h"
#include <iostream>

using namespace Engine;

class TestGameState : public GameState{


	public:

        virtual ~TestGameState()
        {}

		TestGameState(const char *fn)
			: s(fn)
		{}

		virtual void init(){
			s.load();
		}

		virtual void handleEvent(const SDL_Event &event, GameEngine &engine){
		

		}

		virtual void update(GameEngine &engine, int deltaInMS){
			if(Keyboard::isKeyUp(SDLK_SPACE))
				engine.quit();

            std::cout << deltaInMS << '\n';


		}

		virtual void draw(Canvas &mainScreen)
		{
			mainScreen.drawDrawable(s, 100, 0);
		}

	private:
		Sprite s;
};

int main(int argc, char *argv[])
{
	GameEngine e(640, 480);

	e.pushState(new TestGameState(argv[1]));

	e.startGameLoop();
    
    return 0;


}
