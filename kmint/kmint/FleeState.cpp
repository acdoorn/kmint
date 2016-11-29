#pragma once
#include "stdafx.h"
#include "FleeState.h"
#include "StateFactory.h"
#include "Cow.h"
#include "Bunny.h"
#include <vector>



FleeState::FleeState(Graph_A_star* graph) : State("Flee")
{
	g = graph;
}


FleeState::~FleeState()
{
}

void FleeState::Execute(Bunny* bunny) {
	if (bunny->location == c->location) {
		bunny->location = g->GetRandomVertixNot(c->location);
		c->currentState = StateFactory::getInstance().getState("Wander");
		bunny->currentState = StateFactory::getInstance().getState("Wander");
	}

	std::vector<Vertex*> noGoSpots;
	noGoSpots.push_back(c->location);
	noGoSpots.push_back(g->GetNextVertex(bunny->location, c->location));
	bunny->moveTo(g->GetNextVertex(bunny->location, g->GetRandomVertixNot(noGoSpots)));

}

void FleeState::Execute(Cow* cow) {
}

void FleeState::Register(Graph_A_star* graph) {
	StateFactory::getInstance().Register("Flee", new FleeState(graph));
}

sf::Color FleeState::GetColor() {
	return sf::Color(0, 0, 255);
}

void FleeState::RegisterObjects(Pill* pill, Weapon* weapon, Cow* cow, Bunny* bunny) {
	if (pill != nullptr) {
		p = pill;
	}
	if (weapon != nullptr) {
		w = weapon;
	}
	if (cow != nullptr) {
		c = cow;
	}
	if (bunny != nullptr) {
		b = bunny;
	}

}