#pragma once
#include "Vertex.h"
#include <SFML\Graphics.hpp>
#include "State.h"
class Bunny
{
public:
	Bunny(Vertex* loc);
	~Bunny();
	Vertex* location;
	void draw(sf::RenderWindow* window);
	State* currentState;
	double moveChance;
	void moveRandomDirection();
	void step();
	void Register();
	void moveTo(Vertex* loc);
private:
	sf::Sprite sprite;
	sf::Texture t;
};

