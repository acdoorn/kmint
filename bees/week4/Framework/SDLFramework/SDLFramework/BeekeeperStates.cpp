#include "BeekeeperStates.h"
#include "Beekeeper.h"
#include "Graph.h"
//BeekeeperWanderState
//BeekeeperReturnToBaseState
//BeekeeperPanicState
//BeekeeperSearchPillState
//BeekeeperUpgradedState

void BeekeeperWanderState::enter(Beekeeper *)
{
}

void BeekeeperWanderState::execute(Beekeeper * beekeeper, double deltaTime)
{
	beekeeper->checkVertex();
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
}

void BeekeeperWanderState::exit(Beekeeper *)
{
}

void BeekeeperReturnToBaseState::enter(Beekeeper *)
{
}

void BeekeeperReturnToBaseState::execute(Beekeeper * beekeeper, double deltaTime)
{
	Graph* g = beekeeper->getWorld()->getGraph();
	Vertex* base = g->vertices.at(g->vertices.size() - 1);
	Vertex* next = g->GetNextVertex(beekeeper->getCurrentVertex(), base);
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(next->x, next->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
	//check if at base(then deposit bees)
}

void BeekeeperReturnToBaseState::exit(Beekeeper *)
{
}

void BeekeeperPanicState::enter(Beekeeper *)
{
}

void BeekeeperPanicState::execute(Beekeeper * beekeeper, double deltaTime)
{
	//TODO
	beekeeper->checkVertex();
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
}

void BeekeeperPanicState::exit(Beekeeper *)
{
}

void BeekeeperSearchPillState::enter(Beekeeper *)
{
}

void BeekeeperSearchPillState::execute(Beekeeper * beekeeper, double deltaTime)
{
	//TODO
	beekeeper->checkVertex();
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
}

void BeekeeperSearchPillState::exit(Beekeeper *)
{
}

void BeekeeperUpgradedState::enter(Beekeeper *)
{
}

void BeekeeperUpgradedState::execute(Beekeeper * beekeeper, double deltaTime)
{
	//TODO
	beekeeper->checkVertex();
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
}

void BeekeeperUpgradedState::exit(Beekeeper *)
{
}

