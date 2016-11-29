#pragma once
#include "stdafx.h"
#include "SearchWeaponState.h"
#include "StateFactory.h"
#include "Cow.h"
#include "Bunny.h"



SearchWeaponState::SearchWeaponState(Graph_A_star* graph) : State("SearchWeapon")
{
	g = graph;
}


SearchWeaponState::~SearchWeaponState()
{
}

void SearchWeaponState::Execute(Bunny* b) {
	b->moveTo(g->GetNextVertex(b->location, w->location));
	if (w->location == b->location) {
		w->pickUp();
		b->currentState = StateFactory::getInstance().getState("SearchEnemy");
	}

}

void SearchWeaponState::Execute(Cow* c) {

}

void SearchWeaponState::Register(Graph_A_star* graph) {
	StateFactory::getInstance().Register("SearchWeapon", new SearchWeaponState(graph));
}

sf::Color SearchWeaponState::GetColor() {
	return sf::Color(255, 239, 0);
}

void SearchWeaponState::setWeapon(Weapon* weapon) {
	w = weapon;
}