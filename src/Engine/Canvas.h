#pragma once
#include <SDL/SDL.h>

class Canvas{
	public:
		Canvas(int width, int height, bool fullscreen)
			: width(width), height(height), isFullscreen(fullscreen), canvas(NULL)
		{}

		void init();	
		SDL_Surface* getSDLSurface(){ return canvas; }

	
	private:
		SDL_Surface *canvas;
		
		int width;
		int height;
		bool isFullscreen;
};
