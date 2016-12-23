#include "BeekeeperStates.h"
#include "Beekeeper.h"

void BeekeeperWanderState::enter(Beekeeper *)
{
}

void BeekeeperWanderState::execute(Beekeeper * beekeeper, double deltaTime)
{
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(100,100));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);

}

void BeekeeperWanderState::exit(Beekeeper *)
{
}
