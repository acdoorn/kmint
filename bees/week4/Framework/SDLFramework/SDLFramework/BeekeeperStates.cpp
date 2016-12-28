#include "BeekeeperStates.h"
#include "Beekeeper.h"
#include "Graph.h"

void BeekeeperWanderState::enter(Beekeeper *)
{
}

void BeekeeperWanderState::execute(Beekeeper * beekeeper, double deltaTime)
{
	//Graph* g = beekeeper->getWorld()->getGraph();
	Vertex* nextVertex = beekeeper->nextVertex();
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(nextVertex->x, nextVertex->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
	beekeeper->checkVertex();

}

void BeekeeperWanderState::exit(Beekeeper *)
{
}
