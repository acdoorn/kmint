#include "BeeGenerator.h"
#include "GameWorld.h"
#include "Helper.h"


BeeGenerator::BeeGenerator()
{
}


BeeGenerator::~BeeGenerator()
{
}

std::vector<std::shared_ptr<MovingEntity>> BeeGenerator::getNextGeneration(std::vector<BeeStruct>)
{
	return std::vector<std::shared_ptr<MovingEntity>>();
}

std::shared_ptr<Bee> BeeGenerator::generateBee(BeeStat beeOne, BeeStat beeTwo)
{

	//create random split point

	//check random chance 1 in 1000 for a mutation
	// if mutation change one property with a random value

	//set propertys bases on split point.


	return std::shared_ptr<Bee>();
}

std::shared_ptr<Bee> BeeGenerator::generateBee(int xPos, int yPos, GameWorld * world)
{
	int beeSize = 20;
	int minSpeed = 60;
	int maxSpeed = 80;
	int minForce = 45;
	int maxForce = 55;
	int minFleeDistance = 100;
	int maxFleeDistance = 200;

	int maxTurnRate = 150;

	return std::make_shared <Bee>(xPos, yPos, beeSize, beeSize, 1,
		Helper::getRandomDouble(minSpeed, maxSpeed),
		Helper::getRandomDouble(minForce, maxForce),
		maxTurnRate, world, 
		Helper::getRandomDouble(minFleeDistance, maxFleeDistance)
		);
}
