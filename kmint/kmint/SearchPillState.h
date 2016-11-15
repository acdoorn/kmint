#pragma once
#include "State.h"
#include "Pill.h"
class SearchPillState :
	public State
{
public:
	SearchPillState(Graph_A_star* graph);
	~SearchPillState();
	void Execute(Cow* c);
	void Execute(Bunny* b);
	static void Register(Graph_A_star* graph);
	sf::Color GetColor();
	void setPill(Pill* p);
private:
	Pill* p;
	Graph_A_star* g;
};

