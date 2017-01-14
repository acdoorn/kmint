#pragma once
struct BeeStruct
{
	BeeStruct(double timeAlive, double speed, double force, double distance):m_timeAlive(timeAlive),m_speed(speed),m_force(force),m_distance(distance),fraction(0)
	{			
	}
	double m_timeAlive, m_speed, m_force, m_distance, fraction;
};
