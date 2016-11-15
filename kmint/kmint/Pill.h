#pragma once
#include "Vertex.h"
#include <SFML\Graphics.hpp>
class Pill
{
public:
	Pill(Vertex* loc);
	Vertex* location;
	~Pill();
	void draw(sf::RenderWindow* window);
	bool isEaten();
	void eatPill();
	void reSpawn();
	void Register();

private:
	bool eaten = false;
	sf::Sprite sprite;
	sf::Texture t;
};

