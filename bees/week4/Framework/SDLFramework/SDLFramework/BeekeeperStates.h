#pragma once
#include "State.h"

class Beekeeper;
class BeekeeperWanderState : public State<Beekeeper>
{
	// Inherited via State
	virtual void enter(Beekeeper *) override;
	virtual void execute(Beekeeper *, double deltaTime) override;
	virtual void exit(Beekeeper *) override;
};
