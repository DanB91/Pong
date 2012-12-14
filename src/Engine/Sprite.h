#pragma once

#include <SDL/SDL.h>
#include<string>

#include "Canvas.h"
class Sprite{

	public:
		~Sprite();
		Sprite(int width, int height, int x, int y, std::string textureFileName)
			: width(width), height(height), x(x), y(y), fileName(textureFileName)
		{}

		void load();
		void draw(Canvas &mainScreen);
	

	protected:
		int width;
		int height;
		int x;
		int y;
		std::string fileName;	
		SDL_Surface *texture;
};
