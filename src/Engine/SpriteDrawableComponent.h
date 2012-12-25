#include "Component.h"
#include "Sprite.h"

class SpriteDrawableComponent : public Component{
    
    public:
        SpriteDrawableComponent(const std::string id, Entity &owner, const std::string spriteFileName)
            :Component(id, owner), sprite(spriteFileName)
        {}
        virtual void init();
        virtual void update(GameEngine &game, int deltaInMS){}
        virtual void draw(Canvas &mainScreen);

    private:
        Sprite sprite;
};
