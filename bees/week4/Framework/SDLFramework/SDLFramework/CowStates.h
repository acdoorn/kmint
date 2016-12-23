#pragma once
#include "State.h"

class Cow;
class ChaseState : public State<Cow>
{
public:
	ChaseState();

	// Inherited via State
	virtual void enter(Cow*) override;
	virtual void execute(Cow*, double deltaTime) override;
	virtual void exit(Cow*) override;
};

class PursuitState : public State<Cow>
{
public:


	// Inherited via State
	virtual void enter(Cow*) override;

	virtual void execute(Cow*, double deltaTime) override;

	virtual void exit(Cow*) override;

};

