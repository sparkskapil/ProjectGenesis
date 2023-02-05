#include <iostream>
#include "SDL.h"
#include "spdlog/spdlog.h"

const int Width = 800, Height = 600;
int main()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("Genesis", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, Width, Height,
		SDL_WINDOW_ALLOW_HIGHDPI);
	if (window == nullptr)
	{
		spdlog::critical("Could not create SDL window.");
		return -1;
	}

	SDL_Event event;
	while (true)
	{
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				break;
		}
	}
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}