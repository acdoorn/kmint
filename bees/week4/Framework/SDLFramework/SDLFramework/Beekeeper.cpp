#include "Beekeeper.h"
#include "BeekeeperStates.h"
#include <string> 

Beekeeper::Beekeeper(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world) :
	Vehicle(x, y, width, height, mass, maxSpeed, maxForce, maxTurnRate, world), m_catchDistance(80)
{
	m_stateMachine = std::make_shared<StateMachine<Beekeeper>>(this);

	std::shared_ptr<BeekeeperWanderState> initialState = std::make_shared<BeekeeperWanderState>();
	m_stateMachine->setCurrentState(initialState);
	m_texture = FWApplication::GetInstance()->LoadTexture("../Resources/beekeeper.png");
	m_netTexture = FWApplication::GetInstance()->LoadTexture("../Resources/net.png");
	m_areaTexture = FWApplication::GetInstance()->LoadTexture("../Resources/catcharea.png");
}

std::shared_ptr<StateMachine<Beekeeper>> Beekeeper::getStateMachine()
{
	return m_stateMachine;
}



void Beekeeper::update(double deltaTime)
{
	m_stateMachine->update(deltaTime);
	m_catchDistance += deltaTime * 4;
}

double Beekeeper::getCatchDistance()
{
	return m_catchDistance;
}

void Beekeeper::draw()
{
	if (m_texture)
	{
		int x = m_position.getX();
		int y = m_position.getY();
		
		
		FWApplication::GetInstance()->DrawTexture(m_areaTexture, x, y, m_catchDistance * 2, m_catchDistance * 2, getAngle(), getDirection());
		FWApplication::GetInstance()->DrawTexture(m_netTexture, x, y, m_catchDistance *2, m_catchDistance * 2, getAngle(), getDirection());


		FWApplication::GetInstance()->DrawTexture(m_texture, x, y, m_width, m_height, 270, 0);
		FWApplication::GetInstance()->SetColor(Color(255, 10, 40, 255));

		FWApplication::GetInstance()->DrawText("Distance : "+ std::to_string(m_catchDistance) ,100,10);
		FWApplication::GetInstance()->DrawText("Score : " + std::to_string(getWorld()->getScore()), 100, 30);
		
		
		
	}
}


