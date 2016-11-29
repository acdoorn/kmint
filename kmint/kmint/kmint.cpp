// kmint.cpp : Defines the entry point for the console application.
//
#pragma once
#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include "Graph.h"
#include "Graph_A_star.h"
#include "Pill.h"
#include "Weapon.h"
#include "FleeState.h"
#include "WanderState.h"
#include "SearchPillState.h"
#include "SearchEnemyState.h"
#include "SearchWeaponState.h"
#include "Bunny.h"
#include "Cow.h"


int _tmain(int argc, _TCHAR* argv[])
{

	
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(600,600), "KUnsTmatiGE inTELligentie!");
	Graph_A_star* g = new Graph_A_star();
	std::vector<Vertex*> busyVertices;
	FleeState::Register(g);
	WanderState::Register(g);
	SearchWeaponState::Register(g);
	SearchPillState::Register(g);
	SearchEnemyState::Register(g);

	Pill* p = new Pill(g->GetRandomVertixNot(nullptr));
	busyVertices.push_back(p->location);
	p->Register();

	Weapon* w = new Weapon(g->GetRandomVertixNot(busyVertices));
	busyVertices.push_back(w->location);
	w->Register();

	Bunny* b = new Bunny(g->GetRandomVertixNot(busyVertices));
	busyVertices.push_back(b->location);
	b->Register();
	Cow* c = new Cow(g->GetRandomVertixNot(busyVertices));
	busyVertices.push_back(c->location);
	c->Register();

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
			if (event.type == sf::Event::EventType::KeyPressed && event.key.code == sf::Keyboard::Space){
				// cow->doMove();
				// bunny->doMove();
				c->step();
				b->step();




				//if (c->location == b->location){
				//	b->location = g->GetRandomVertixNot(c->location);
				//	p->reSpawn();
				//	p->location = g->GetRandomVertixNot(c->location);
				//	c->loseConfidence();
				//}
				//else if (c->location == p->location) {
				//	c->eatPill();
				//	p->eatPill();
				//}
				//	if (c->hasConfidence()) {
				//		if (g->GetNextVertex(c->location, b->location) != NULL) {
				//			c->location = g->GetNextVertex(c->location, b->location);
				//		}
				//	}
				//	else {
				//		if (g->GetNextVertex(c->location, p->location) != NULL) {
				//			c->location = g->GetNextVertex(c->location, p->location);
				//		}
				//	}

			}
		}

		window->clear();
		g->drawGraph(window);
		w->draw(window);
		p->draw(window);
		b->draw(window);
		c->draw(window);
		window->display();
	}
	return 0;
}

