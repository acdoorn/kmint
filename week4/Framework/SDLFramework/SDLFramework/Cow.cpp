#include "Cow.h"
#include "CowStates.h"


Cow::Cow(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world) :
	Vehicle(x, y, width, height, mass, maxSpeed, maxForce, maxTurnRate, world)
{
	m_stateMachine = std::make_shared<StateMachine<Cow>>(this);

	std::shared_ptr<PursuitState> initialState = std::make_shared<PursuitState>();
	m_stateMachine->setCurrentState(initialState);
	m_texture = FWApplication::GetInstance()->LoadTexture("../Resources/koe.png");
}


Cow::~Cow()
{
}

void Cow::update(double deltaTime, int command)
{
	m_stateMachine->update(deltaTime);
}

void Cow::update(double deltaTime)
{
	m_stateMachine->update(deltaTime);
}

std::shared_ptr<StateMachine<Cow>> Cow::getStateMachine()
{
	return m_stateMachine;
}
