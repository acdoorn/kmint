#pragma once
class BeeStat
{
public:
	BeeStat(double timeAlive,double maxForce,double maxSpeed, double fleeDistance, double mass);
	~BeeStat();
	double m_timeAlive;
	double m_maxForce;
	double m_maxSpeed;
	double m_fleeDistance;
	double m_mass;
};

