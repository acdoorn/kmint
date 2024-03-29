#pragma once
#include "State.h"
#include "Pill.h"
#include "Weapon.h"
class WanderState :
	public State
{
public:
	WanderState(Graph_A_star* graph);
	~WanderState();
	void Execute(Cow* c);
	void Execute(Bunny* b);
	static void Register(Graph_A_star* graph);
	sf::Color GetColor();
	void setWeapon(Weapon* weapon);
	void RegisterObjects(Pill*, Weapon*, Cow*, Bunny*);
private:
	Graph_A_star* g;
	Pill* p;
	Weapon* w;
	Cow* c;
	Bunny* b;
};

