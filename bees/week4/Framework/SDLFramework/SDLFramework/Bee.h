#pragma once
#include "Vehicle.h"
#include "StateMachine.h"

class Bee : public Vehicle
{
private:
	std::shared_ptr<StateMachine<Bee>> m_stateMachine;
	int m_fleeDistance;

public:
	~Bee();
	Bee(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world, int fleeDistance);
	std::shared_ptr<StateMachine<Bee>> getStateMachine();
	int getFleeDistance();

	virtual void update(double deltaTime) override;
};

