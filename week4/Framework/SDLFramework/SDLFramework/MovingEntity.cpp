#include "MovingEntity.h"




MovingEntity::MovingEntity(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce,double maxTurnRate)
	:BaseGameEntity(x, y,width,height),
	m_maxSpeed(maxSpeed),m_maxForce(maxForce),m_maxTurnRate(maxTurnRate),m_mass(mass)
{
}

double MovingEntity::getMaxSpeed()
{
	return m_maxSpeed;
}

Vector2D MovingEntity::getVelocity()
{
	return m_velocity;
}

Vector2D MovingEntity::getHeading()
{
	calculateHeading();
	return m_heading;
}

void MovingEntity::setVelocity(Vector2D newValue)
{
	m_velocity = newValue;
	//make sure vehicle does not exceed maximum velocity
	m_velocity.truncate(m_maxSpeed);
}

void MovingEntity::calculateHeading()
{
	m_heading = m_velocity.normalized();
}


Vector2D MovingEntity::m_side()
{
	return m_heading.opposite();
}

double MovingEntity::getMass()
{
	return m_mass;
}


