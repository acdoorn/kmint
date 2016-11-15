#pragma once
#include "stdafx.h"
#include "WanderState.h"
#include "Bunny.h"
#include "Cow.h"
#include "StateFactory.h"


WanderState::WanderState() : State("Wander")
{
	srand(time(NULL));
}


WanderState::~WanderState()
{
}

void WanderState::Execute(Bunny* b){
	double ran = rand() % 100 + 1;
	if (ran / 100 < b->moveChance){
		b->moveRandomDirection();
	}
	if (b->location == w->location) {
		w->pickUp();
		b->currentState = StateFactory::getInstance().getState("SearchEnemy");
	}
}

void WanderState::Execute(Cow* c){
	double ran = rand() % 100 + 1;
	if (ran/100 < c->moveChance){
		c->moveRandomDirection();
	}
	ran = rand() % 100 + 1;
	if (ran / 100 < c->changeToSearchChance){
		c->currentState = StateFactory::getInstance().getState("SearchPill");
	}

}

void WanderState::Register(Graph_A_star* graph){
	StateFactory::getInstance().Register("Wander", new WanderState());
}

sf::Color WanderState::GetColor(){
	return sf::Color(255, 255, 255);
}


void WanderState::setWeapon(Weapon* weapon){
	w = weapon;
}
