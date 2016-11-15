#pragma once
#include "stdafx.h"
#include "Pill.h"
#include "StateFactory.h"
#include "SearchPillState.h"
#include "SearchEnemyState.h"


Pill::Pill(Vertex* loc)
{
	location = loc;
	t.loadFromFile("Resources/pill.png");

	sprite.setTexture(t);
	sprite.scale(sf::Vector2f(0.3f, 0.3f));
}

bool Pill::isEaten() {
	return eaten;
}

void Pill::eatPill() {
	eaten = true;
}

void Pill::reSpawn() {
	eaten = false;
}

Pill::~Pill()
{
}

void Pill::draw(sf::RenderWindow* window){
	if (!this->isEaten()) {
		sprite.setPosition(location->location.first - 20, location->location.second - 20);
		window->draw(sprite);
	}
}

void Pill::Register(){
	((SearchPillState*)StateFactory::getInstance().getState("SearchPill"))->setPill(this);
	((SearchEnemyState*)StateFactory::getInstance().getState("SearchEnemy"))->RegisterObjects(this, nullptr, nullptr, nullptr);
}