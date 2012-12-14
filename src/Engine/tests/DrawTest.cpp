#include "../GameState.h"
#include "../Sprite.h"
#include "../GameEngine.h"

class TestGameState : public GameState{


	public:
		TestGameState(const char *fn)
			: s(20, 20, 0, 0, fn)
		{}

		virtual void init(){
			s.load();
		}

		virtual void handleEvent(const SDL_Event &event){}

		virtual void update(GameEngine &engine){}

		virtual void draw(Canvas &mainScreen)
		{
			s.draw(mainScreen);
		}

	private:
		Sprite s;
};

int main(int argc, char *argv[])
{
	GameEngine e(640, 480);

	e.pushState(new TestGameState(argv[1]));

	e.startGameLoop();


}
