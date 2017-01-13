#include "BeeGenerator.h"
#include "GameWorld.h"
#include "Helper.h"
#include <algorithm>
#include <string>
BeeGenerator::BeeGenerator()
{
}


BeeGenerator::~BeeGenerator()
{
}

void BeeGenerator::getNextGeneration(std::vector<BeeStruct> oldGeneration, GameWorld * world)
{
	double total = 0;

	//aantal members van de nieuwe generatie;
	const int expectedTotal = 100;

	//Het totaal aan getallen achter de comma/punt
	double totalBehindDot = 0;

	std::vector<BeeStruct> genSurvivers;

	try {
		for each (BeeStruct bee in oldGeneration)
		{
			total += bee.m_timeAlive;
		}
		double totalDistance = 0;
		double totalSpeed = 0; 
		double totalForce = 0;
		for (auto &value : oldGeneration)
		{
			//de fractie berkenen maal het aantal nieuwe waardes
			value.fraction = (value.m_timeAlive / total) * expectedTotal;

			//getal achter de comma berekenen.
			int addAmount = value.fraction;
			totalBehindDot += value.fraction - addAmount;
			totalDistance += value.m_distance;
			totalSpeed += value.m_speed;
			totalForce += value.m_force;
		}
		totalForce = totalForce / oldGeneration.size();
		totalDistance = totalDistance / oldGeneration.size();
		totalSpeed = totalSpeed / oldGeneration.size();

		std::cout << "------------------ Generation stats ------------------" << std::endl;
		std::cout << "Distance "<<std::to_string(totalDistance) << std::endl ;
		std::cout << "Speed " << std::to_string(totalSpeed) << std::endl;
		std::cout << "Force " << std::to_string(totalForce) << std::endl;
		std::cout << "------------------------------------------------------" << std::endl;

		//het anatal voor de punt gebruiken om toe te voegen
		int added = 0;
		for (auto const &value : oldGeneration)
		{
			//zorgt ervoor dat je alleen het getal voor de punt hebt
			int addAmount = value.fraction;
			for (int i = 0; i < addAmount; i++)
			{
				genSurvivers.push_back(value);
			}
			added += addAmount;
		}

		for (int i = 0; i < expectedTotal - added; i++)
		{
			double randomDouble = Helper::getRandomDouble(0, totalBehindDot);
			//Deze waarde verhogen om de juiste value te vinden.
			double totalBehindDotCalculated = 0;

			for (auto const &value : oldGeneration)
			{
				int beforeDot = value.fraction;
				double behindDot = value.fraction - beforeDot;
				totalBehindDotCalculated += behindDot;
				if (randomDouble < totalBehindDotCalculated)
				{
					genSurvivers.push_back(value);
					break;
				}

			}

		}
		if (genSurvivers.size() != 100)
		{
			//zou hier niet moeten komen, dan is er iets mis met het kruisen
			std::cout << "Te weinig";
		}
		
		//een geschuffelde versie om te kruisen
		std::vector<BeeStruct> shuffled = genSurvivers;
		std::shuffle(shuffled.begin(), shuffled.end(), Helper::getRandomEngine());
		
		std::vector<std::shared_ptr<Bee>> beesReturn;


		for (int i = 0; i < expectedTotal; i++)
		{
			//beesReturn.push_back(generateBee(genSurvivers.at(i), genSurvivers.at(Helper::getRandomInt(0, expectedTotal - 1)), world));
			beesReturn.push_back(generateBee(genSurvivers.at(i), shuffled.back(), world));
			shuffled.pop_back();
		}

		std::vector<std::shared_ptr<MovingEntity>> returnVal = std::vector<std::shared_ptr<MovingEntity>>();
		//zorgen dat de bees op een random positie komen

		std::shuffle(beesReturn.begin(), beesReturn.end(), Helper::getRandomEngine());
		for (int i = 0; i < 20; i++)
		{
			world->addBee(500, i * 30, beesReturn.back());
			beesReturn.pop_back();
		}
		for (int i = 0; i < 20; i++)
		{
			world->addBee(i * 30, 150, beesReturn.back());
			beesReturn.pop_back();
			//addBee(i * 30, 150);
		}

		for (int i = 0; i < 20; i++)
		{
			world->addBee(i * 30, 450, beesReturn.back());
			beesReturn.pop_back();
			//addBee(i * 30, 450);
		}

		for (int i = 0; i < 20; i++)
		{
			world->addBee(i * 30, 550, beesReturn.back());
			beesReturn.pop_back();
			//addBee(i * 30, 550);
		}

		for (int i = 0; i < 20; i++)
		{
			world->addBee(i * 30, 50, beesReturn.back());
			beesReturn.pop_back();
			//addBee(550, i * 30);
		}
	}
	catch (const std::exception &exc)
	{
		// catch anything thrown within try block that derives from std::exception
		std::cout << exc.what();
	}


}

std::shared_ptr<Bee> BeeGenerator::generateBee(BeeStruct beeOne, BeeStruct beeTwo, GameWorld * world)
{


	int speed = beeOne.m_speed;
	int force = beeOne.m_force;
	int distance = beeTwo.m_distance;

	int splitPoint = Helper::getRandomInt(1, 2);

	if (splitPoint == 1)
	{
		force = beeTwo.m_force;
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



	std::shared_ptr<Bee> returnVal = std::make_shared <Bee>(0, 0, beeSize, beeSize, 1,
		speed,
		force,
		maxTurnRate,
		world,
		distance
		);
	return returnVal;
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
