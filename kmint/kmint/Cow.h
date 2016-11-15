#pragma once
#include "Vertex.h"
#include <SFML\Graphics.hpp>
#include "State.h"
class Cow
{
public:
	Cow(Vertex* loc);
	~Cow();
	Vertex* location;
	void draw(sf::RenderWindow* window);
	void step();
	bool hasConfidence();
	void loseConfidence() { this->confidence = false; };
	void eatPill() { this->confidence = true; }
	State* currentState;
	double moveChance;
	double changeToSearchChance = 0.20;
	void moveRandomDirection();
	void moveTo(Vertex* loc);
	void Register();

private:
	bool confidence = false;
	sf::Sprite sprite;
	sf::Texture t;
};

