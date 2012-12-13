#pragma once
#include "GameEngineException.h"
#include <SDL/SDL.h>

class SDLException : public GameEngineException{

	public:
		SDLException(std::string msg)
			: GameEngineException()
		{
			GameEngineException::message = msg + ": " + SDL_GetError();
		}
};
