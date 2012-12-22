#include "Engine/GameState.h"
#include "Engine/Sprite.h"
#include "Engine/Keyboard.h"
#include "Engine/GameEngine.h"

class TestGameState : public GameState{


	public:

        virtual ~TestGameState()
        {}

		TestGameState(const char *fn)
			: s(20, 20, fn)
		{}

		virtual void init(){
			s.load();
		}

		virtual void handleEvent(const SDL_Event &event, GameEngine &engine){
		

		}

		virtual void update(GameEngine &engine){
			if(Keyboard::isKeyUp(SDLK_SPACE))
				engine.quit();
		}

		virtual void draw(Canvas &mainScreen)
		{
			s.draw(mainScreen, 100, 0);
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
