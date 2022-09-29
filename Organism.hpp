#ifndef Organism_hpp
#define Organism_hpp

#include <string>
#include <vector>
#include "Box2D.h"

class Organism
{
public:
	Organism(b2World* world, const glm::vec2& position, std::string genome);
	~Organism();

	void randomInit();
	void recombinationInit();
	//void createHead(b2World* world, const glm::vec2& position);
	void createPart(char allele);
	void assembleParts();
	
	void render();

	float evaluateFitness();

private:
	//std::string genome;
	//
	std::vector<b2Body*> bodies;
	std::vector<b2Joint*> joints;
};

#endif // Organism_hpp
