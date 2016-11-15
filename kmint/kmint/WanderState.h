#pragma once
#include "State.h"
#include "Weapon.h"
class WanderState :
	public State
{
public:
	WanderState();
	~WanderState();
	void Execute(Cow* c);
	void Execute(Bunny* b);
	static void Register(Graph_A_star* graph);
	sf::Color GetColor();
	void setWeapon(Weapon* weapon);
private:
	Weapon* w;
};

