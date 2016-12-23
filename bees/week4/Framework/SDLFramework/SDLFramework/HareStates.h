#pragma once
#include "State.h"
class Hare;
class WanderState : public State<Hare>
{
public:
	WanderState();

	// Inherited via State
	virtual void enter(Hare*) override;
	virtual void execute(Hare*, double deltaTime) override;
	virtual void exit(Hare*) override;
};


class FleeState : public State<Hare>
{
public:
	FleeState();


	// Inherited via State
	virtual void enter(Hare*) override;

	virtual void execute(Hare*, double deltaTime) override;

	virtual void exit(Hare*) override;

};

class ArriveState : public State<Hare>
{
public:
	ArriveState();


	// Inherited via State
	virtual void enter(Hare *) override;

	virtual void execute(Hare *, double deltaTime) override;

	virtual void exit(Hare *) override;

};
