#include "Engine/GameState.h"
#include "Engine/Sprite.h"
#include "Engine/GameEngine.h"

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
			if(event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
				engine.quit();


		}

		virtual void update(GameEngine &engine){}

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
