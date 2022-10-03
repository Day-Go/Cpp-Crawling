#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "Game.hpp"

Game* game = nullptr;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

int main(int argc, char** args)
{
	Uint32 frameStart, frameTime;

	game = new Game();
	
	game->initSubsystems();
	game->initWindow("Crawling", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_OPENGL);
	game->initRenderer();
	game->checkInitStatus();

	game->createWorld();
	game->createFloor();
	game->createSubstrate();
	game->createOrganism();

	while (game->isRunning())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;
		
		if (frameTime < DELAY_TIME)
		{
			SDL_Delay((int)(DELAY_TIME - frameTime));
		}
	}

	game->clean();

	SDL_Quit();

	return 0;
};