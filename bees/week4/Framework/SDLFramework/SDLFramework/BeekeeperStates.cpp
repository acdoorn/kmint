#include "BeekeeperStates.h"
#include "Beekeeper.h"
#include "Graph.h"

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
