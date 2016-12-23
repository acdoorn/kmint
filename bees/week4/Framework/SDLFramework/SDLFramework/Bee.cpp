#include "Bee.h"
#include "BeeStates.h"
#include <iostream>

Bee::~Bee()
{
	getWorld()->addCatch();
	std::cout << "Bee destroyed " << m_position <<  "  -  " << getWorld()->getBeekeeper()->getPosition() <<  std::endl;
}

Bee::Bee(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world,int fleeDistance) :
	Vehicle(x, y, width, height, mass, maxSpeed, maxForce, maxTurnRate, world),m_fleeDistance(fleeDistance)
{
	m_stateMachine = std::make_shared<StateMachine<Bee>>(this);

	std::shared_ptr<WanderFlockState> initialState = std::make_shared<WanderFlockState>();
	m_stateMachine->setCurrentState(initialState);
	//m_texture = world->getBeeTexture();
	m_texture = FWApplication::GetInstance()->LoadTexture("../Resources/bee.png");
}

std::shared_ptr<StateMachine<Bee>> Bee::getStateMachine()
{
	return m_stateMachine;
}

int Bee::getFleeDistance()
{
	return m_fleeDistance;
}


void Bee::update(double deltaTime)
{
	m_stateMachine->update(deltaTime);
}
