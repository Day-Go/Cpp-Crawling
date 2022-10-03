#ifndef Ball_hpp
#define Ball_hpp

#include "SDL.h"
#include "Box2D.h"
#include "glm.hpp"

class Ball
{
public:
	Ball(b2World* world, const glm::vec2& position, const float radius);
	~Ball();

	void render(SDL_Renderer* renderer);
	
	b2Body* getBody() { return body; }

private:
	b2Body* body = nullptr;
};

#endif // !Ball_hpp

