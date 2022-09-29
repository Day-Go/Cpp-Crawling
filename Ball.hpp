#ifndef Ball_hpp
#define Ball_hpp

#include "SDL.h"
#include "Box2D.h"
#include "glm.hpp"

struct Circle
{
	float x, y;
	float r;
};

class Ball
{
public:
	Ball();
	~Ball();

	void init(b2World* world, const glm::vec2& position, const float radius);
	
	void render(SDL_Renderer* renderer);
	void update();
	
	b2Body* getBody() { return body; }
	b2Fixture* getFixture() { return fixture; }

private:
	Circle props;

	b2Body* body = nullptr;
	b2Fixture* fixture = nullptr;
};

#endif // !Ball_hpp

