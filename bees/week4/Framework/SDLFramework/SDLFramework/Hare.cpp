#include "Hare.h"
#include "HareStates.h"

Hare::Hare(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world):
	Vehicle( x,  y,  width,  height,  mass,  maxSpeed,  maxForce,  maxTurnRate,  world)
{
	m_stateMachine = std::make_shared<StateMachine<Hare>>(this);
	std::shared_ptr<WanderState> initialState = std::make_shared<WanderState>();
	m_stateMachine->setCurrentState(initialState);
	m_texture = FWApplication::GetInstance()->LoadTexture("../Resources/haas.png");
}

void Hare::update(double deltaTime)
{
	m_stateMachine->update(deltaTime);
}


std::shared_ptr<StateMachine<Hare>> Hare::getStateMachine()
{
	return m_stateMachine;
}
