#pragma once
#include <vector>
#include "BaseGameEntity.h"
#include "MovingEntity.h"
#include <memory>
#include "Vehicle.h"


class GameWorld
{
	//Pointers gebruikt omdat ander .update niet kan worden aangeroepen	
	//http://stackoverflow.com/questions/5270540/calling-derived-class-functions-from-within-a-vector-c
	std::vector<std::shared_ptr<MovingEntity>>gameObjects;
	std::vector<std::shared_ptr<MovingEntity>>cows;
	std::shared_ptr<MovingEntity>hare;
public:
	GameWorld();
	void addObject();
	void update(double deltaTime, int command);
	void update(double deltaTime);
	void draw();
	std::shared_ptr<MovingEntity> getHare();
	std::vector<std::shared_ptr<MovingEntity>>getCows();
};

