#pragma once
#include "stdafx.h"
#include "Cow.h"
#include <iostream>
#include "StateFactory.h"
#include "SearchEnemyState.h"



Cow::Cow(Vertex* loc)
{
	location = loc;
	t.loadFromFile("Resources/cow-2.png");

	sprite.setTexture(t);
	sprite.scale(sf::Vector2f(1.4f, 1.4f));
	moveChance = 1;
	currentState = StateFactory::getInstance().getState("Wander");
}


Cow::~Cow()
{
}

void Cow::draw(sf::RenderWindow* window){
	sprite.setPosition(location->location.first - 20, location->location.second - 20);

	sprite.setColor(currentState->GetColor());


	window->draw(sprite);
}

bool Cow::hasConfidence() {
	return confidence;
}

void Cow::step(){
	std::cout << "cow steps" << std::endl;
	currentState->Execute(this);
}

void Cow::moveRandomDirection(){
	location = location->getRandomNeighbour();
}

void Cow::moveTo(Vertex* loc){
	if (loc != nullptr){
		location = loc;
	}
}

void Cow::Register(){
	((SearchEnemyState*)StateFactory::getInstance().getState("SearchEnemy"))->RegisterObjects(nullptr, nullptr, this, nullptr);
}