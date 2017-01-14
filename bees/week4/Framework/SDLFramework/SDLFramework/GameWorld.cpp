#include "GameWorld.h"
#include "Vehicle.h"
#include "Bee.h"
#include "Beekeeper.h"
#include <algorithm>
#include "BeeGenerator.h"
#include <string> 
void GameWorld::addBee( int x, int y )
{
	BeeGenerator m_beeGenerator;
	std::shared_ptr<Bee> bee = m_beeGenerator.generateBee(x,y, this);
	gameObjects.push_back(bee);
	bees.push_back(bee);
}

void GameWorld::nextGeneration()
{
	BeeGenerator m_beeGenerator;
	gameObjects = std::vector<std::shared_ptr<MovingEntity>>();
	
	m_beeGenerator.getNextGeneration(caught, this);

	caught = std::vector<BeeStruct>();

	//addObject();
	
	int maxSpeed = 50;
	int maxForce = 55;
	int maxTurnRate = 150;
	m_beekeeper = std::make_shared<Beekeeper>(0, 0, 80, 80, 1, maxSpeed, maxForce, maxTurnRate, this);
	gameObjects.push_back(m_beekeeper);

	m_score = 0;
	m_generation++;
	m_generationTime = 0;

}

void GameWorld::addBee(int x, int y, BeeStruct data)
{
	
}

void GameWorld::addBee(int x, int y, std::shared_ptr<MovingEntity> bee)
{
	gameObjects.push_back(bee);
	bees.push_back(bee);
	bee->setPosition(Vector2D(x, y));
}

GameWorld::GameWorld()
{
	graph = new Graph();
	m_score = 0;
	m_generation = 1;
	m_generationTime = 0;
	bee_texture = FWApplication::GetInstance()->LoadTexture("../Resources/bee.png");
}

void GameWorld::addCatch(BeeStruct bee)
{
	bee.m_timeAlive = m_generationTime;
	caught.push_back(bee);
	std::shared_ptr<Beekeeper> beekeeper = std::static_pointer_cast<Beekeeper>(m_beekeeper);
	beekeeper->addBee();
}



void GameWorld::addObject()
{
	//Vehicle(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world);
	BeeGenerator m_beeGenerator;
	for (int i = 0; i < 20; i++)
	{
		addBee(500, i * 30);
	}
	for (int i = 0; i < 20; i++)
	{

		addBee(i * 30, 150);
	}

	for (int i = 0; i < 20; i++)
	{
		addBee(i * 30, 450);
	}

	for (int i = 0; i < 20; i++)
	{
		addBee(i * 30, 550);
	}

	for (int i = 0; i < 20; i++)
	{
		addBee(550, i * 30);
	}
	int maxSpeed = 50;
	int maxForce = 55;
	int maxTurnRate = 150;
	m_beekeeper = std::make_shared<Beekeeper>(0, 0, 80, 80, 1, maxSpeed, maxForce, maxTurnRate, this);
	gameObjects.push_back(m_beekeeper);
}



void GameWorld::update(double deltaTime)
{
	if (m_score == 100)
	{		
		nextGeneration();
	}
	else
	{
		m_generationTime += deltaTime;
		for (const auto &value : gameObjects)
		{
			value->update(deltaTime);
		}
		catchBees();
	}
	
}

void GameWorld::draw()
{
	if (m_score != 100)
	{

		for (const auto &value : gameObjects)
		{
			value->draw();
		}
		FWApplication::GetInstance()->DrawText("generation : " + std::to_string(m_generation) , 100, 29);
	}
}

SDL_Texture * GameWorld::getBeeTexture()
{
	return bee_texture;
}

void GameWorld::catchBees()
{
	std::shared_ptr<Beekeeper> beekeeper = std::static_pointer_cast<Beekeeper>(m_beekeeper);
	if (beekeeper->isCatching()) {
		auto q = std::remove_if(bees.begin(), bees.end(),
			[&](std::shared_ptr<MovingEntity> const& bee) { return beeTooClose(bee); });
		bees.erase(q, bees.end());

		auto deleteGameObjects = std::remove_if(gameObjects.begin(), gameObjects.end(),
			[&](std::shared_ptr<MovingEntity> const& bee) { return beeTooClose(bee); });
		gameObjects.erase(deleteGameObjects, gameObjects.end());

	}
	
}

bool GameWorld::beeTooClose( const std::shared_ptr<MovingEntity>& bee)
{
	std::shared_ptr<Beekeeper> beekeeper = std::static_pointer_cast<Beekeeper>(m_beekeeper);
	int distance = bee->getConstPosition().distanceTo(m_beekeeper->getPosition());
	if (bee->getID() != m_beekeeper->getID() && beekeeper->isCatching())
	{
		if (distance < beekeeper->getCatchDistance())
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

Graph* GameWorld::getGraph() {
	return graph;
}

std::vector<BeeStruct> GameWorld::getCaughtBees() {
	return caught;
}

void GameWorld::upScore(int amount) {
	m_score = m_score + amount;
}