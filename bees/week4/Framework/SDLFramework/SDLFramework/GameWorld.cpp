#include "GameWorld.h"
#include "Vehicle.h"
#include "Bee.h"
#include "Beekeeper.h"
#include <algorithm>


GameWorld::GameWorld()
{
	m_score = 0;
	bee_texture = FWApplication::GetInstance()->LoadTexture("../Resources/bee.png");
}

void GameWorld::addCatch()
{
	m_score++;
}

void GameWorld::addObject()
{
	//Vehicle(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world);
	
	int beeSize = 20;
	int maxSpeed = 45;
	int maxForce = 50;
	int maxTurnRate = 150;

	for (int i = 0; i < 20; i++)
	{
		std::shared_ptr<Bee> bee = std::make_shared <Bee>(500, i*30, beeSize, beeSize, 1, maxSpeed, maxForce, maxTurnRate, this, 150);
		gameObjects.push_back(bee);
		bees.push_back(bee);
	}
	for (int i = 0; i < 20; i++)
	{
		std::shared_ptr<Bee> bee = std::make_shared <Bee>(i * 30,150, beeSize, beeSize, 1, maxSpeed, maxForce, maxTurnRate, this, 150);
		gameObjects.push_back(bee);
		bees.push_back(bee);
	}

	for (int i = 0; i < 20; i++)
	{
		std::shared_ptr<Bee> bee = std::make_shared <Bee>(i * 30, 450, beeSize, beeSize, 1, maxSpeed, maxForce, maxTurnRate, this, 150);
		gameObjects.push_back(bee);
		bees.push_back(bee);
	}

	for (int i = 0; i < 20; i++)
	{
		std::shared_ptr<Bee> bee = std::make_shared <Bee>(i * 30, 550, beeSize, beeSize, 1, maxSpeed, maxForce, maxTurnRate, this, 150);
		gameObjects.push_back(bee);
		bees.push_back(bee);
	}

	for (int i = 0; i < 20; i++)
	{
		std::shared_ptr<Bee> bee = std::make_shared <Bee>(550, i * 30, beeSize, beeSize, 1, maxSpeed, maxForce, maxTurnRate, this, 150);
		gameObjects.push_back(bee);
		bees.push_back(bee);
	}


	m_beekeeper = std::make_shared<Beekeeper>(300, 300, 80, 80, 1, maxSpeed, maxForce, maxTurnRate, this);
	gameObjects.push_back(m_beekeeper);
}



void GameWorld::update(double deltaTime)
{
	for (const auto &value : gameObjects)
	{
		value->update(deltaTime);
	}
	catchBees();
}

void GameWorld::draw()
{
	for (const auto &value : gameObjects)
	{
		value->draw();
	}
}

SDL_Texture * GameWorld::getBeeTexture()
{
	return bee_texture;
}

void GameWorld::catchBees()
{
	
	auto q = std::remove_if(bees.begin(), bees.end(),
		[&](std::shared_ptr<MovingEntity> const& bee) { return beeToClose(bee); });
	bees.erase(q, bees.end());

	auto deleteGameObjects = std::remove_if(gameObjects.begin(), gameObjects.end(),
		[&](std::shared_ptr<MovingEntity> const& bee) { return beeToClose(bee); });
	gameObjects.erase(deleteGameObjects, gameObjects.end());
	
}

bool GameWorld::beeToClose( const std::shared_ptr<MovingEntity> & bee)
{
	std::shared_ptr<Beekeeper> keeper = std::static_pointer_cast<Beekeeper>(m_beekeeper);
	int distance = bee->getConstPosition().distanceTo(m_beekeeper->getPosition());
	if (bee->getID() != m_beekeeper->getID())
	{
		if (distance < keeper->getCatchDistance())
		{
			return true;
		}

	}
	
	return false;
}

int GameWorld::getScore()
{
	return m_score;
}





std::shared_ptr<MovingEntity> GameWorld::getBeekeeper()
{
	return m_beekeeper;
}

std::vector<std::shared_ptr<MovingEntity>> GameWorld::getBees()
{
	return bees;
}
