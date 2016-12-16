#include "CowStates.h"
#include "Cow.h"

ChaseState::ChaseState()
{
}

void ChaseState::enter(Cow* cow)
{
	std::cout << "Cow entered chase" << std::endl;
}

void ChaseState::execute(Cow* cow, double deltaTime)
{
	Vector2D influence = cow->getSteeringBehaviour()->seek(cow->getWorld()->getHare()->getPosition());
	cow->move(influence,deltaTime);
}

void ChaseState::exit(Cow* cow)
{
}

void PursuitState::enter(Cow*)
{
}

void PursuitState::execute(Cow* cow, double deltaTime)
{
	Vector2D influence = cow->getSteeringBehaviour()->pursuit(cow->getWorld()->getHare().get());
	Vector2D seperation = cow->getSteeringBehaviour()->seperation() * 1000;
	influence += seperation;
	/*	Vector2D alignment = cow->getSteeringBehaviour()->allignment() * 0.001;
	influence += alignment;
	*/

	cow->move(influence, deltaTime);
}

void PursuitState::exit(Cow* cow)
{
}
