#pragma once
#include "Vector2D.h"
#include "Vehicle.h"
class Vehicle;
class SteeringBehaviors
{
private:
	Vehicle* m_vehicle;

	//radius van de wander circel
	double m_wanderRadius;

	//afstand dat de wander circel van de auto is
	double m_wanderDistance;

	//Finally, m_dWanderJitter is the maximum amount of random displacement
	//that can be added to the target each second
	double m_wanderJitter;
	Vector2D m_wanderTarget;
public:
	SteeringBehaviors(Vehicle*);

	
	Vector2D calculate();
	Vector2D seek(Vector2D);
	Vector2D flee(Vector2D);
	Vector2D arrive(Vector2D);
	Vector2D wander();
	Vector2D pursuit(MovingEntity* evader);
	Vector2D seperation();
	Vector2D allignment();
	double GenerateRandom(double, double);
};

