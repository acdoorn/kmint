#include "BeeGenerator.h"
#include "GameWorld.h"
#include "Helper.h"


BeeGenerator::BeeGenerator()
{
}


BeeGenerator::~BeeGenerator()
{
}

std::vector<std::shared_ptr<MovingEntity>> BeeGenerator::getNextGeneration(std::vector<BeeStruct> oldGeneration)
{
	std::vector<std::shared_ptr<MovingEntity>> returnVal = std::vector<std::shared_ptr<MovingEntity>>();
	for (int i = 0; i < 20; i++)
	{		
		//addBee(500, i * 30);
	}
	for (int i = 0; i < 20; i++)
	{

		//addBee(i * 30, 150);
	}

	for (int i = 0; i < 20; i++)
	{
		//addBee(i * 30, 450);
	}

	for (int i = 0; i < 20; i++)
	{
		//addBee(i * 30, 550);
	}

	for (int i = 0; i < 20; i++)
	{
		//addBee(550, i * 30);
	}



	return returnVal;
}

std::shared_ptr<Bee> BeeGenerator::generateBee(BeeStat beeOne, BeeStat beeTwo, GameWorld * world)
{


	int speed = beeOne.m_maxSpeed;
	int force = beeOne.m_maxForce;
	int distance = beeTwo.m_fleeDistance;	

	int splitPoint = Helper::getRandomInt(1, 2);

	if (splitPoint == 1)
	{
		force = beeTwo.m_maxForce;
	}

	//mutatie
	int mutation = Helper::getRandomInt(1, 1000);
	if (mutation == 500)
	{
		std::cout << "!!!!!!!!!!!!!!!!!!!!! Mutatie !!!!!!!!!!!!!!!!!!!!!" << std::endl;
		int mutationValue = Helper::getRandomInt(1, 3);
		switch (mutationValue)
		{
		case(1) :
			speed = Helper::getRandomDouble(minSpeed, maxSpeed);
			break;
		case(2) :
			force = Helper::getRandomDouble(minForce, maxForce);
			break;
		default:
			distance = Helper::getRandomDouble(minFleeDistance, maxFleeDistance);
			break;
		}
	}


	
	std::shared_ptr<Bee> returnVal = std::make_shared <Bee>(0,0 , beeSize, beeSize, 1,
		speed,
		force,
		maxTurnRate, 
		world,
		distance
		);
	return std::shared_ptr<Bee>();
}

std::shared_ptr<Bee> BeeGenerator::generateBee(int xPos, int yPos, GameWorld * world)
{

	

	return std::make_shared <Bee>(xPos, yPos, beeSize, beeSize, 1,
		Helper::getRandomDouble(minSpeed, maxSpeed),
		Helper::getRandomDouble(minForce, maxForce),
		maxTurnRate, world, 
		Helper::getRandomDouble(minFleeDistance, maxFleeDistance)
		);
}
