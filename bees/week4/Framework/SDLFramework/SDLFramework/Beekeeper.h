#pragma once
#include "Vehicle.h"
#include "StateMachine.h"


class Beekeeper : public Vehicle
{
private:
	std::shared_ptr<StateMachine<Beekeeper>> m_stateMachine;
	SDL_Texture* m_netTexture;
	SDL_Texture* m_areaTexture;
	double m_catchDistance;

public:
	Beekeeper(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world);
	std::shared_ptr<StateMachine<Beekeeper>> getStateMachine();

	virtual void update(double deltaTime) override;
	double getCatchDistance();
	void draw();
};
