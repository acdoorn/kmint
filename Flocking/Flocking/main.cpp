// kmint.cpp : Defines the entry point for the console application.
//
#pragma once
#include <SFML/Graphics.hpp>


int main(int argc, const char* argv[])
{


	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(600, 600), "Flocking!");
	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type == sf::Event::EventType::KeyPressed && event.key.code == sf::Keyboard::Space) {
				
			}
			//move cows and bunny
		}

		window->clear();
		window->display();
	}
	return 0;
}

