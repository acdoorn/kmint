#include "GameWorld.h"
#include "Vehicle.h"
#include "Hare.h"
#include "Cow.h"
#include <algorithm>


GameWorld::GameWorld()
{
}

void GameWorld::addObject()
{
	//Vehicle(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world);
	hare = std::make_shared < Hare>(500, 350, 40, 40, 1, 130, 130, 150, this);
	gameObjects.push_back(hare);

	for (int i = 0; i < 20; i++)
	{
		std::shared_ptr<Cow> cow = std::make_shared < Cow>(i*30, 10, 30, 30, 1, 40, 30, 150, this);
		gameObjects.push_back(cow);
		cows.push_back(cow);
	}
	
	std::shared_ptr<Cow> cow2 = std::make_shared < Cow>(990, 10, 30, 30, 1, 40, 30, 150, this);
	std::shared_ptr<Cow> cow3 = std::make_shared < Cow>(10, 690, 30, 30, 1, 40, 30, 150, this);
	std::shared_ptr<Cow> cow4 = std::make_shared < Cow>(990, 690, 30, 30, 1, 40, 30, 150, this);
	
	gameObjects.push_back(cow2);
	gameObjects.push_back(cow3);
	gameObjects.push_back(cow4);
	
	cows.push_back(cow2);
	cows.push_back(cow3);
	cows.push_back(cow4);
}

void GameWorld::update(double deltaTime, int command)
{
	for (const auto &value : gameObjects)
	{
		value->update(deltaTime, command);
	}
}

void GameWorld::update(double deltaTime)
{
	for (const auto &value : gameObjects)
	{
		value->update(deltaTime);
	}
}

void GameWorld::draw()
{
	for (const auto &value : gameObjects)
	{
		value->draw();
	}
}


std::shared_ptr<MovingEntity> GameWorld::getHare()
{
	return hare;
}

std::vector<std::shared_ptr<MovingEntity>> GameWorld::getCows()
{
	return cows;
}
