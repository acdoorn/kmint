#include "BeeStates.h"
#include "Bee.h"




void FleeState::enter(Bee * bee)
{
}

void FleeState::execute(Bee * bee, double deltaTime)
{
	const int safeDistance = bee->getFleeDistance() + 100;
	bool safe = true;

	Vector2D influence = Vector2D(0, 0);
	bool vectorSet = false;

	Vector2D fleeFromPosition = bee->getWorld()->getBeekeeper()->getPosition();
	
	int distance = bee->getPosition().distanceTo(fleeFromPosition);
	if (distance < safeDistance)
	{
		influence = bee->getSteeringBehaviour()->flee(fleeFromPosition);
	}
	
	else
	{
		std::shared_ptr<WanderFlockState> nextState = std::make_shared<WanderFlockState>();
		bee->getStateMachine()->changeState(nextState);
	}
	bee->move(influence, deltaTime);
}

void FleeState::exit(Bee * bee)
{
}

void WanderFlockState::enter(Bee * bee)
{
}

void WanderFlockState::execute(Bee * bee, double deltaTime)
{



	std::vector<std::shared_ptr<MovingEntity>>bees = bee->getWorld()->getBees();
	if (bee->getPosition().distanceTo(bee->getWorld()->getBeekeeper()->getPosition()) < bee->getFleeDistance())
	{

		std::shared_ptr<FleeState> nextState = std::make_shared<FleeState>();
		bee->getStateMachine()->changeState(nextState);
		return;
	}


	Vector2D  influence = Vector2D(0,0);

	Vector2D seperation = bee->getSteeringBehaviour()->seperation() * 1000;
	influence += seperation;

	Vector2D alignment = bee->getSteeringBehaviour()->allignment() * 300;
	influence += alignment ;

	Vector2D cohesion = bee->getSteeringBehaviour()->Cohesion() *0.1;
	influence += cohesion;


	bee->move(influence, deltaTime);
}

void WanderFlockState::exit(Bee * bee)
{
}
