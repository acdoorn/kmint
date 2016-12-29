#include "BeeStat.h"





BeeStat::BeeStat(double timeAlive, double maxForce, double maxSpeed, double fleeDistance, double mass)
{
	m_fleeDistance = fleeDistance;
	m_mass = mass;
	m_maxForce = maxForce;
	m_maxSpeed = maxSpeed;
	m_timeAlive = timeAlive;
}

BeeStat::~BeeStat()
{
}
