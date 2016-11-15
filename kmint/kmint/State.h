#pragma once
class Cow;
class Bunny;
#include "Graph_A_star.h"
#include <string>
#include <SFML\Graphics.hpp>
class State
{
public:
	State(std::string name);
	~State();
	virtual void Execute(Cow* c) = 0;
	virtual void Execute(Bunny* b) = 0;
	static void Register(Graph_A_star* graph);
	virtual sf::Color GetColor() = 0;
protected:
	std::string stateName;
};

