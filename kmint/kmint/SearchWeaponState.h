#pragma once
#include "State.h"
#include "Weapon.h"
class SearchWeaponState :
	public State
{
public:
	SearchWeaponState(Graph_A_star* graph);
	~SearchWeaponState();
	void Execute(Cow* c);
	void Execute(Bunny* b);
	static void Register(Graph_A_star* graph);
	sf::Color GetColor();
	void setWeapon(Weapon* w);
private:
	Weapon* w;
	Graph_A_star* g;
};

