#pragma once
#include "stdafx.h"
#include "Bunny.h"
#include "StateFactory.h"
#include "SearchEnemyState.h"
#include "WanderState.h"


Bunny::Bunny(Vertex* loc)
{
	location = loc;
	t.loadFromFile("Resources/rabbit-2.png");
	sprite.setTexture(t);
	sprite.scale(sf::Vector2f(0.3f, 0.3f));
	moveChance = 0.9;
	currentState = StateFactory::getInstance().getState("Wander");
}


Bunny::~Bunny()
{
}

void Bunny::draw(sf::RenderWindow* window){
	sprite.setPosition(location->location.first - 38, location->location.second - 35);
	sprite.setColor(currentState->GetColor());
	window->draw(sprite);
}

void Bunny::moveRandomDirection(){
	location = location->getRandomNeighbour();
}

void Bunny::step(){
	currentState->Execute(this);
}

void Bunny::moveTo(Vertex* loc){
	if (loc != nullptr){
		location = loc;
	}
}

void Bunny::Register(){
	((WanderState*)StateFactory::getInstance().getState("Wander"))->RegisterObjects(nullptr, nullptr, nullptr, this);
	((SearchEnemyState*)StateFactory::getInstance().getState("SearchEnemy"))->RegisterObjects(nullptr, nullptr, nullptr, this);
}