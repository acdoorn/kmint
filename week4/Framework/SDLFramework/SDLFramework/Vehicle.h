#pragma once
#include "MovingEntity.h"
#include "GameWorld.h"
#include "SteeringBehaviors.h"
class SteeringBehaviors;
class GameWorld;
class Vehicle : public MovingEntity
{
private:
	GameWorld* m_world;
	std::shared_ptr<SteeringBehaviors> m_steering;
public:
	Vehicle(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world);

	// Inherited via MovingEntity
	virtual void update(double deltaTime, int command) =0;

	// Inherited via MovingEntity
	virtual void update(double deltaTime)  = 0;

	std::shared_ptr<SteeringBehaviors> getSteeringBehaviour();
	void move(Vector2D, double);
	std::vector<std::shared_ptr<MovingEntity>> getNeighbours(double);
	GameWorld* getWorld();
};

