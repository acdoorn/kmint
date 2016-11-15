#pragma once
#include "stdafx.h"
#include "SearchEnemyState.h"
#include "StateFactory.h"
#include "Cow.h"
#include "Bunny.h"
#include <vector>



SearchEnemyState::SearchEnemyState(Graph_A_star* graph) : State("SearchEnemy")
{
	g = graph;
}


SearchEnemyState::~SearchEnemyState()
{
}

void SearchEnemyState::Execute(Bunny* bunny){
	if (bunny->location == c->location){
		bunny->location = g->GetRandomVertixNot(c->location);
		c->currentState = StateFactory::getInstance().getState("Wander");
		bunny->currentState = StateFactory::getInstance().getState("Wander");
		w->reSpawn();
		p->reSpawn();
		std::vector<Vertex*> usedSpots;
		usedSpots.push_back(bunny->location);
		usedSpots.push_back(c->location);
		usedSpots.push_back(p->location);
		w->location = g->GetRandomVertixNot(usedSpots);
	}
	bunny->moveTo(g->GetNextVertex(bunny->location, c->location));

}

void SearchEnemyState::Execute(Cow* cow){
	if (b->location == cow->location){
		b->location = g->GetRandomVertixNot(cow->location);
		cow->currentState = StateFactory::getInstance().getState("Wander");
		b->currentState = StateFactory::getInstance().getState("Wander");
		p->reSpawn();
		w->reSpawn();
		std::vector<Vertex*> usedSpots;
		usedSpots.push_back(c->location);
		usedSpots.push_back(b->location);
		usedSpots.push_back(w->location);
		p->location = g->GetRandomVertixNot(usedSpots);
	}
	cow->moveTo(g->GetNextVertex(cow->location, b->location));
	
}

void SearchEnemyState::Register(Graph_A_star* graph){
	StateFactory::getInstance().Register("SearchEnemy", new SearchEnemyState(graph));
}

sf::Color SearchEnemyState::GetColor(){
	return sf::Color(255, 0, 0);
}

void SearchEnemyState::RegisterObjects(Pill* pill, Weapon* weapon, Cow* cow, Bunny* bunny){
	if (pill != nullptr){
		p = pill;
	}
	if (weapon != nullptr){
		w = weapon;
	}
	if (cow != nullptr){
		c = cow;
	}
	if (bunny != nullptr){
		b = bunny;
	}

}