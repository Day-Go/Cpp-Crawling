#ifndef Game_hpp
#define Game_hpp

#include "SDL.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Ball.hpp"
#include "Box2D.h"

class Game 
{
public:
	Game();
	~Game();

	// Initialising SDL
	void initSubsystems();
	void initWindow(const char* title, int xPos, int yPos, int w, int h, Uint32 flags);
	void initRenderer();
	void checkInitStatus();

	void createWorld();
	void createSubstrate();

	void render();
	void update();
	void handleEvents();
	void clean();

	bool isRunning() { return running; }
	std::vector<bool> isInitialised() { return initialised; }
	
private:
	bool running;
	std::vector<bool> initialised;

	SDL_Window* pWindow = 0;
	SDL_Renderer* pRenderer = 0;

	std::vector<Ball> balls;
	std::unique_ptr<b2World> mWorld;
};


#endif // !Game_hpp
