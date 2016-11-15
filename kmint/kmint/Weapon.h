#pragma once
#include "Vertex.h"
#include <SFML\Graphics.hpp>
class Weapon
{
public:
	Weapon(Vertex* loc);
	Vertex* location;
	~Weapon();
	void draw(sf::RenderWindow* window);
	void Register();
	void pickUp();
	void reSpawn();
	bool isPickedUp() {
		return pickedUp;
	}
private:
	bool pickedUp = false;
	sf::Sprite sprite;
	sf::Texture t;
};

