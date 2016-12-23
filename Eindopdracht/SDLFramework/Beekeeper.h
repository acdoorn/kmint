#pragma once

#include "IGameObject.h"
#include "Graph.h"
#include "Bee.h"

class Beekeeper : public IGameObject {
public:
	Beekeeper();
	Beekeeper(Graph* graph, Bee* bee);
	~Beekeeper();
	void Update(float deltaTime);
	Vertex* location;

private:
	SDL_Texture *texture;
	Graph* graph;
	Bee* closestBee;
	void moveTo(int x, int y);
};