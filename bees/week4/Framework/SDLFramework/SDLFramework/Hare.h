#pragma once
#include "Vehicle.h"
#include "HareStates.h"
#include "StateMachine.h"


class Hare : public Vehicle
{
private:
	std::shared_ptr<StateMachine<Hare>> m_stateMachine;	
public:
	Hare(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world);
	void update(double deltaTime)override;

	std::shared_ptr<StateMachine<Hare>> getStateMachine();
};

