#include "Helper.h"





std::default_random_engine Helper::randomEngine = std::default_random_engine{};

Helper::Helper()
{
}

Helper::~Helper()
{
}

int Helper::getRandomInt(int min, int max)
{
	using Dist = std::uniform_int_distribution<int>;
	static Dist uid{};
	return uid(randomEngine, Dist::param_type{ min,max});
}

double Helper::getRandomDouble(double min, double max)
{	
	using Dist = std::uniform_real_distribution<double>;
	static Dist uid{};
	return uid(randomEngine, Dist::param_type{ min,max });
}
