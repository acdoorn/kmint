#include "Beekeeper.h"
#include <SDL_render.h>

Beekeeper::Beekeeper() {
	texture = mApplication->LoadTexture("beekeeper.png");
	this->SetTexture(texture);
	this->SetSize(52, 75);
}
Beekeeper::Beekeeper(Graph* g, Bee* b) {
	texture = mApplication->LoadTexture("beekeeper.png");
	this->SetTexture(texture);
	this->SetSize(52, 75);
	graph = g;
	Vertex* out;
	location = g->vertices.at(g->vertices.size()-1);
	closestBee = b;
}

Beekeeper::~Beekeeper() {
	SDL_DestroyTexture(texture);
}

void Beekeeper::moveTo(int x, int y) {
	std::vector<Vertex*>::iterator it;
	Vertex* findvertex = new Vertex(x, y);
	it = std::find(graph->vertices.begin(), graph->vertices.end(), findvertex);
	if (it != graph->vertices.end())
		location = *it;

}

void Beekeeper::Update(float deltaTime) {
	// Vertex where we want to go for testing:
	// auto vertex103 = new Vertex(28, 31); 

	/* move method:
		const int x = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + 400);
		const int y = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + 300);
		SetOffset(x, y);
	*/
	Vertex* movingto = graph->GetNextVertex(location, closestBee->location);
	const int x = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + movingto->x);
	const int y = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + movingto->y);
	if (movingto->x == x && movingto->y == y) {
		moveTo(x, y);
	}
	SetOffset(x, y);


	//if (b->location == cow->location) {
	//	b->location = g->GetRandomVertixNot(cow->location);
	//	cow->currentState = StateFactory::getInstance().getState("Wander");
	//	b->currentState = StateFactory::getInstance().getState("Wander");
	//	p->reSpawn();
	//	w->reSpawn();
	//	std::vector<Vertex*> usedSpots;
	//	usedSpots.push_back(c->location);
	//	usedSpots.push_back(b->location);
	//	usedSpots.push_back(w->location);
	//	p->location = g->GetRandomVertixNot(usedSpots);
	//}
	//cow->moveTo(g->GetNextVertex(cow->location, b->location));
}

/*
if (graph->setShortestPath(obj->getWaypoint(), graph->getRabbit()->getWaypoint()))
	{
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getRabbit()->getWaypoint()) {
		if (graph->getRabbit()->isAttacking())
		{
			std::cout << "Cow: Lost to the rabbit!\n";
		}
		else
		{
			std::cout << "Cow: Caught the rabbit!\n";
		}
		
		obj->setState(new WanderingStateCow());
		graph->getRabbit()->resetState();
}*/