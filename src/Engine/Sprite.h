#pragma once

#include <SDL/SDL.h>
#include<string>

#include "Canvas.h"
class Sprite{

	public:
		~Sprite();
		Sprite(int width, int height,  const std::string &textureFileName)
			: width(width), height(height), fileName(textureFileName)
		{}

		void load();
		void draw(Canvas &mainScreen, int x, int y);


	

	protected:
		int width;
		int height;
		const std::string fileName;	
		SDL_Surface *texture;
};
