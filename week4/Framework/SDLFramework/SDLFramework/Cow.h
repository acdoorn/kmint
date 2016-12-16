#pragma once
#include "Vehicle.h"
#include "StateMachine.h"

class Cow : public Vehicle
{
private:
	std::shared_ptr<StateMachine<Cow>> m_stateMachine;
public:
	Cow(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world);
	~Cow();

	// Inherited via Vehicle
	virtual void update(double deltaTime, int command) override;
	virtual void update(double deltaTime) override;
	std::shared_ptr<StateMachine<Cow>> getStateMachine();
};

