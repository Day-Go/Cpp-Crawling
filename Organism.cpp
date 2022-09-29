#include "glm.hpp"
#include "Organism.hpp"

Organism::Organism(b2World* world, const glm::vec2& position, std::string genome)
{
	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(position.x, position.y);
    
    b2Body* body= world->CreateBody(&bodyDef);
    bodies.push_back(body);

    b2CircleShape circleShape;
    circleShape.m_radius = 12.0f;

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &circleShape;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.2f;
    fixtureDef.restitution = 0.0f;
    body->CreateFixture(&fixtureDef);
}

Organism::~Organism()
{

}

void Organism::randomInit()
{

}

void Organism::recombinationInit()
{

}

//void Organism::createHead(b2World* world, const glm::vec2& position)
//{
//	b2BodyDef bodyDef;
//	bodyDef.type = b2_dynamicBody;
//	bodyDef.position.Set(position.x, position.y);
//	body = world->CreateBody(&bodyDef);
//}

void Organism::createPart(char allele)
{

}

void Organism::assembleParts()
{

}

void Organism::render()
{

}

float Organism::evaluateFitness()
{
	return 0.0f;
}