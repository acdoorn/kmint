#pragma once
#include "Bee.h"
#include "BeeStat.h"
#include "GameWorld.h"
#include "MovingEntity.h"
#include <vector>
#include <memory>

class BeeGenerator
{
private:	
public:
	BeeGenerator();
	~BeeGenerator();
	static const int beeSize = 20;
	static const int minSpeed = 60;
	static const int maxSpeed = 80;
	static const int minForce = 45;
	static const int maxForce = 55;
	static const int minFleeDistance = 100;
	static const int maxFleeDistance = 200;
	static const int maxTurnRate = 150;


	std::vector<std::shared_ptr<MovingEntity>> getNextGeneration(std::vector<BeeStruct>,GameWorld * world);
	std::shared_ptr<Bee> generateBee(BeeStruct beeOne, BeeStruct beeTwo, GameWorld * world);
	std::shared_ptr<Bee> generateBee(int xPos, int yPos, GameWorld* world);
};

