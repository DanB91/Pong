#include "../src/Engine/Keyboard.h"
#include "../src/Engine/SpriteDrawableComponent.h"

class TestGameState : public GameState{


	public:

        virtual ~TestGameState()
        {}

		TestGameState(const char *fn)
            : e("testEntity", 10, 100), fn(fn)
		{}

		virtual void init(){
             
           e.addComponent(new SpriteDrawableComponent("testSprite", e, fn));
           e.init();

		}

		virtual void handleEvent(const SDL_Event &event, GameEngine &engine){
		
            
		}

		virtual void update(GameEngine &engine){
			if(Keyboard::isKeyUp(SDLK_ESCAPE))
				engine.quit();
		}

		virtual void draw(Canvas &mainScreen)
		{
            e.draw(mainScreen);
		}

	private:
        Entity e;
        const std::string fn;
};

int main(int argc, char *argv[])
{
	GameEngine e(640, 480);

    if(argc > 1)
        e.pushState(new TestGameState(argv[1]));
    else
        e.pushState(new TestGameState("/Users/danielbokser/Downloads/lena.bmp"));


	e.startGameLoop();

    
    return 0;


}
