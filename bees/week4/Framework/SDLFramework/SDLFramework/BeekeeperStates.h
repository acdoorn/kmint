#pragma once
#include "State.h"

class Beekeeper;

class BeekeeperWanderState : public State<Beekeeper>
{
	// Inherited via State
	virtual void enter(Beekeeper *) override;
	virtual void execute(Beekeeper *, double deltaTime) override;
	virtual void exit(Beekeeper *) override;
	virtual std::string name() override;
};

class BeekeeperReturnToBaseState : public State<Beekeeper>
{
	// Inherited via State
	virtual void enter(Beekeeper *) override;
	virtual void execute(Beekeeper *, double deltaTime) override;
	virtual void exit(Beekeeper *) override;
	virtual std::string name() override;
};

class BeekeeperPanicState : public State<Beekeeper>
{
	// Inherited via State
	virtual void enter(Beekeeper *) override;
	virtual void execute(Beekeeper *, double deltaTime) override;
	virtual void exit(Beekeeper *) override;
	virtual std::string name() override;
};

class BeekeeperSearchPillState : public State<Beekeeper>
{
	// Inherited via State
	virtual void enter(Beekeeper *) override;
	virtual void execute(Beekeeper *, double deltaTime) override;
	virtual void exit(Beekeeper *) override;
	virtual std::string name() override;
};

class BeekeeperUpgradedState : public State<Beekeeper>
{
	// Inherited via State
	virtual void enter(Beekeeper *) override;
	virtual void execute(Beekeeper *, double deltaTime) override;
	virtual void exit(Beekeeper *) override;
	virtual std::string name() override;
};