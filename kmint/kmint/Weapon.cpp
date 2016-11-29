#pragma once
#include "stdafx.h"
#include "Weapon.h"
#include "StateFactory.h"
#include "SearchEnemyState.h"
#include "WanderState.h"


Weapon::Weapon(Vertex* loc)
{
	location = loc;
	t.loadFromFile("Resources/gun-metal.png");

	sprite.setTexture(t);
	sprite.scale(sf::Vector2f(0.4f, 0.4f));
}


Weapon::~Weapon()
{
}

void Weapon::draw(sf::RenderWindow* window){
	if (!this->isPickedUp()) {
		sprite.setPosition(location->location.first - 20, location->location.second - 20);
		window->draw(sprite);
	}
}

void Weapon::Register(){
	((WanderState*)StateFactory::getInstance().getState("Wander"))->RegisterObjects(nullptr, this, nullptr, nullptr);
	((SearchEnemyState*)StateFactory::getInstance().getState("SearchEnemy"))->RegisterObjects(nullptr,this,nullptr,nullptr);
}

void Weapon::pickUp() {
	pickedUp = true;
}

void Weapon::reSpawn() {
	pickedUp = false;
}