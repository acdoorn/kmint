#pragma once
#include "stdafx.h"
#include "SearchPillState.h"
#include "StateFactory.h"
#include "Cow.h"
#include "Bunny.h"



SearchPillState::SearchPillState(Graph_A_star* graph) : State("SearchPill")
{
	g = graph;
}


SearchPillState::~SearchPillState()
{
}

void SearchPillState::Execute(Bunny* b){
	b->moveTo(g->GetNextVertex(b->location, p->location));
	if (p->location == b->location) {
		p->eatPill();
		b->currentState = StateFactory::getInstance().getState("SearchEnemy");
	}

}

void SearchPillState::Execute(Cow* c){
	
}

void SearchPillState::Register(Graph_A_star* graph){
	StateFactory::getInstance().Register("SearchPill", new SearchPillState(graph));
}

sf::Color SearchPillState::GetColor(){
	return sf::Color(255, 239, 0);
}

void SearchPillState::setPill(Pill* pill){
	p = pill;
}