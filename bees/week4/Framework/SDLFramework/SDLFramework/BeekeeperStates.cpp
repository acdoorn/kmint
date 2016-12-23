#include "BeekeeperStates.h"
#include "Beekeeper.h"

void BeekeeperWanderState::enter(Beekeeper *)
{
}

void BeekeeperWanderState::execute(Beekeeper * beekeeper, double deltaTime)
{
	beekeeper->move(Vector2D(1,2), deltaTime); 

}

void BeekeeperWanderState::exit(Beekeeper *)
{
}
