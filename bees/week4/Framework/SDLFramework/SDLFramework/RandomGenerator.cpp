#include "RandomGenerator.h"
#include <random>
#include <iostream>
#include <functional>




std::shared_ptr<RandomGenerator> RandomGenerator::instance = nullptr;

RandomGenerator::RandomGenerator()
{
}


RandomGenerator::~RandomGenerator()
{
}

std::default_random_engine RandomGenerator::getRandomEngine()
{
	return dre;
}

std::shared_ptr<RandomGenerator> RandomGenerator::getInstance()
{
	if (instance == nullptr)
	{
		instance = std::make_shared<RandomGenerator>();
		//instance.reset(new RandomGenerator);
	}
	return instance;
}

int RandomGenerator::randomIntBetween(int min, int max)
{
	if (max < min)
	{
		throw std::invalid_argument("Min should be lower than Max");
	}

	/*my_distribution range{ min,max};
	auto die = std::bind(range, dre);
	int x = die();

	for (int i = 0; i < 100; i++)
	{
		std::cout << x << std::endl;
		x = die();

	}*/



	return 0;
}

int RandomGenerator::randomDoubleBetween(double min, double max)
{
	if (max < min)
	{
		throw std::invalid_argument("Min should be lower than Max");
	}
	return 0;
}
