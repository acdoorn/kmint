#pragma once
#include "State.h"
#include "Pill.h"
#include "Weapon.h"
class FleeState :
	public State
{
public:
	FleeState(Graph_A_star* graph);
	~FleeState();
	void Execute(Cow* c);
	void Execute(Bunny* b);
	static void Register(Graph_A_star* graph);
	sf::Color GetColor();
	void RegisterObjects(Pill*, Weapon*, Cow*, Bunny*);

private:
	Graph_A_star* g;
	Pill* p;
	Weapon* w;
	Cow* c;
	Bunny* b;
};

