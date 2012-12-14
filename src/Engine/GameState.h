#pragma once
#include "Canvas.h"


class GameEngine;
class GameState
{
	public:
		virtual void init() = 0;
		virtual void handleEvent(const SDL_Event &event) = 0;
		virtual void update(GameEngine &engine) = 0;
		virtual void draw(Canvas &mainScreen) = 0;
};
