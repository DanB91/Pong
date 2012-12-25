#include "SpriteDrawableComponent.h"

void SpriteDrawableComponent::init()
{
    sprite.load();
}

void SpriteDrawableComponent::draw(Canvas &mainScreen)
{
    sprite.draw(mainScreen, owner.getX(), owner.getY());
}
