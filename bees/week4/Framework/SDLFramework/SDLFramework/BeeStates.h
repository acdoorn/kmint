#pragma once
#pragma once
#include "State.h"
class Bee;

class FleeState : public State<Bee>
{
public:

	// Inherited via State
	virtual void enter(Bee*) override;

	virtual void execute(Bee*, double deltaTime) override;

	virtual void exit(Bee*) override;
	virtual std::string name() override;

};


class WanderFlockState : public State<Bee>
{
public:


	// Inherited via State
	virtual void enter(Bee*) override;

	virtual void execute(Bee*, double deltaTime) override;

	virtual void exit(Bee*) override;
	virtual std::string name() override;

};
