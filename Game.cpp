#include "Game.hpp"

Game::Game()
{
	running = false;
}

Game::~Game()
{

}

void Game::initSubsystems()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf(
			"SDL Initialisation has failed. Error : %s",
			SDL_GetError()
		);
		this->initialised.push_back(false);
	}
	else 
	{
		this->initialised.push_back(true);
	}
}

void Game::initWindow(const char* title, int xPos, int yPos, int w, int h, Uint32 flags)
{
	pWindow = SDL_CreateWindow(title, xPos, yPos, w, h, flags);

	if (pWindow == NULL)
	{
		printf(
			"Could not create a window. Error : %s",
			SDL_GetError()
		);
		this->initialised.push_back(false);
	}
	else
	{
		this->initialised.push_back(true);
	}
}

void Game::initRenderer()
{
	pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

	if (pRenderer == NULL)
	{
		printf(
			"Could not create a renderer. Error : %s",
			SDL_GetError()
		);
		this->initialised.push_back(false);
	}
	else
	{
		SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
		this->initialised.push_back(true);
	}
}

void Game::checkInitStatus()
{
	std::vector<bool> initState = this->isInitialised();

	if (!std::all_of(initState.cbegin(), initState.cend(), [](bool v) { return v; }))
	{
		printf("SDL was not initialised properly! Error : %s", SDL_GetError());
	}
	else
	{
		running = true;
	}
}

void Game::render()
{
	// set to black
	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);

	// clear the window to black
	SDL_RenderClear(pRenderer);

	SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);

	for (auto ball : balls)
	{
		ball.render(pRenderer);
	}

	// show the window
	SDL_RenderPresent(pRenderer);
}

void Game::update()
{
	mWorld->Step(1.0f / 60.0f, 10, 4);
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			running = false;
			break;
		default:
			break;
		}
	}
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
	SDL_Quit();
}

void Game::createWorld()
{
	b2Vec2 gravity(0.0f, 25.0f);
	mWorld = std::make_unique<b2World>(gravity);

	b2BodyDef groundBodyDef;
	groundBodyDef.position.Set(980.0f, 1000.0f);
	b2Body* groundBody = mWorld->CreateBody(&groundBodyDef);

	b2PolygonShape groundBox;
	groundBox.SetAsBox(1000.0f, 10.0f);
	//groundBody->CreateFixture(&groundBox, 0.0f);

	b2FixtureDef fixtureDef;

	fixtureDef.shape = &groundBox;
	fixtureDef.density = 0.0f;
	fixtureDef.friction = 1000.0f;

	groundBody->CreateFixture(&fixtureDef);
}

void Game::createSubstrate()
{

	for (int i = 1; i < 64; i++) {
		for (int j = 1; j < 30; j++) {
			float r = ((static_cast <float> (rand()) / 
				      static_cast <float> (RAND_MAX)) - 0.5f) * 5;

			float xPos = i * 30 + r;
			float yPos = j * 30;

			balls.push_back(Ball(mWorld.get(), glm::vec2(xPos, yPos), 10.0f));
		}
	}

}