#pragma once
#include <vector>
#include "BaseGameEntity.h"
#include "MovingEntity.h"
#include <memory>
#include "Vehicle.h"
#include "Graph.h"


class GameWorld
{
private:
	SDL_Texture* bee_texture;
	//Pointers gebruikt omdat ander .update niet kan worden aangeroepen	
	//http://stackoverflow.com/questions/5270540/calling-derived-class-functions-from-within-a-vector-c
	std::vector<std::shared_ptr<MovingEntity>>gameObjects;
	std::vector<std::shared_ptr<MovingEntity>>bees;
	std::shared_ptr<MovingEntity>m_beekeeper;
	int m_score;
	Graph* graph;
public:
	GameWorld();
	void addCatch();
	void addObject();
	void update(double deltaTime);
	void draw();
	SDL_Texture* getBeeTexture();
	void catchBees();
	bool beeToClose(const std::shared_ptr<MovingEntity>&);
	int getScore();
	void catchBee(std::shared_ptr<MovingEntity>);
	std::shared_ptr<MovingEntity> getBeekeeper();
	std::vector<std::shared_ptr<MovingEntity>>getBees();
	Graph* getGraph();
};

