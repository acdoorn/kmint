#include "HareStates.h"
#include <iostream>
#include "Hare.h"

WanderState::WanderState()
{
}

void WanderState::enter(Hare* hare)
{
	std::cout << "Hare entered wander state" << std::endl;
}

void WanderState::execute(Hare* hare, double deltaTime)
{
	const int panicDistance = 50;


	std::vector<std::shared_ptr<MovingEntity>>cows = hare->getWorld()->getCows();
	for (const auto &value : cows)
	{
		if (hare->getPosition().distanceTo(value->getPosition()) < panicDistance)
		{

			std::shared_ptr<FleeState> nextState = std::make_shared<FleeState>();
			hare->getStateMachine()->changeState(nextState);
			return;
		}
	}
	
	
	
	Vector2D influence = Vector2D(10,5);
	//Vector2D influence = hare->getSteeringBehaviour()->wander();
	hare->move(influence, deltaTime);
}

void WanderState::exit(Hare* hare)
{
}

FleeState::FleeState()
{
}

void FleeState::enter(Hare* hare)
{
	std::cout << "Hare entered flee state" << std::endl;
}

void FleeState::execute(Hare* hare, double deltaTime)
{
	int distance;
	const int safeDistance = 100;
	bool safe = true;

	Vector2D influence = Vector2D(0, 0);
	bool vectorSet = false;

	std::vector<std::shared_ptr<MovingEntity>>cows = hare->getWorld()->getCows();
	for (const auto &value : cows)
	{
		distance = hare->getPosition().distanceTo(value->getPosition());
		if (distance < safeDistance)
		{
			if (!vectorSet)
			{
				influence = hare->getSteeringBehaviour()->flee(value->getPosition());
				vectorSet = true;
			}
			else
			{
				influence += hare->getSteeringBehaviour()->flee(value->getPosition());
			}
			safe = false;
		}
	}
	if (safe)
	{
		std::shared_ptr<WanderState> nextState = std::make_shared<WanderState>();
		hare->getStateMachine()->changeState(nextState);
	}

	
	
	hare->move(influence, deltaTime);
	
}

void FleeState::exit(Hare* hare)
{
}

ArriveState::ArriveState()
{
}

void ArriveState::enter(Hare *)
{
	std::cout << "Hare entered arrive state" << std::endl;
}

void ArriveState::execute(Hare * hare , double deltaTime)
{
	Vector2D destination = Vector2D(100, 100);
	int distance = hare->getPosition().distanceTo(destination);
	if (distance < 5)
	{
		std::shared_ptr<FleeState> nextState = std::make_shared<FleeState>();
		hare->getStateMachine()->changeState(nextState);
		return;
	}
	
	Vector2D influence = hare->getSteeringBehaviour()->arrive(destination);;
	hare->move(influence,deltaTime);

}

void ArriveState::exit(Hare *)
{
}
