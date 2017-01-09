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
	std::vector<std::shared_ptr<MovingEntity>> getNextGeneration(std::vector<BeeStruct>);
	std::shared_ptr<Bee> generateBee(BeeStat beeOne, BeeStat beeTwo);
	std::shared_ptr<Bee> generateBee(int xPos, int yPos, GameWorld* world);
};

