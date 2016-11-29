#pragma once
#include "stdafx.h"
#include "WanderState.h"
#include "Bunny.h"
#include "Cow.h"
#include "StateFactory.h"


WanderState::WanderState(Graph_A_star* graph) : State("Wander")
{
	srand(time(NULL));
	g = graph;
}


WanderState::~WanderState()
{
}

void WanderState::Execute(Bunny* b){
	double ran = rand() % 100 + 1;
	if (ran / 100 < b->moveChance){
		b->moveRandomDirection();
	}
	std::vector<std::pair<int, int>> locations = g->Graph_SearchAStar(c->location, b->location);
	if (locations.size() <= 3) {
		
		// TODO: keuze hier invoeren gebaseerd op basiskans & succes van vorige keuze, indien eerste keer alleen basiskans
		//b->currentState = StateFactory::getInstance().getState("SearchPill");
		//b->currentState = StateFactory::getInstance().getState("SearchWeapon");
		b->currentState = StateFactory::getInstance().getState("Flee");
	}
}

void WanderState::Execute(Cow* c){
	double ran = rand() % 100 + 1;
	if (ran/100 < c->moveChance){
		c->moveRandomDirection();
	}



	std::vector<std::pair<int, int>> locations = g->Graph_SearchAStar(c->location, b->location);
	if (locations.size() <= 3){
		c->currentState = StateFactory::getInstance().getState("SearchEnemy");
	}

}

void WanderState::Register(Graph_A_star* graph){
	StateFactory::getInstance().Register("Wander", new WanderState(graph));
}

sf::Color WanderState::GetColor(){
	return sf::Color(255, 255, 255);
}


void WanderState::setWeapon(Weapon* weapon){
	w = weapon;
}


void WanderState::RegisterObjects(Pill* pill, Weapon* weapon, Cow* cow, Bunny* bunny) {
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