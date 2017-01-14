#pragma once
#include <random>
class Helper
{
private:
	Helper();
	~Helper();
public:
	static std::default_random_engine randomEngine;
	
	static int getRandomInt(int min, int max);
	static double getRandomDouble(double min, double max);
	static  std::default_random_engine getRandomEngine();
};

