#pragma once
#include "Bee.h"
#include "BeeStat.h"
class BeeGenerator
{
public:
	BeeGenerator();
	~BeeGenerator();
	std::shared_ptr<Bee> generateBee(BeeStat beeOne, BeeStat beeTwo);
};

