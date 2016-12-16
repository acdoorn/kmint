#include "Vehicle.h"
#include "FWApplication.h"



Vehicle::Vehicle(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world)
	:MovingEntity(x,y,width,height,mass,maxSpeed,maxForce,maxTurnRate)
{	
	m_steering = std::make_shared<SteeringBehaviors>(this);
	m_world = world;
	m_texture = FWApplication::GetInstance()->LoadTexture("../Resources/arrow.png");
}




std::shared_ptr<SteeringBehaviors> Vehicle::getSteeringBehaviour()
{
	return m_steering;
}

GameWorld * Vehicle::getWorld()
{
	return m_world;
}

void Vehicle::move(Vector2D influence, double deltaTime)
{
	Vector2D steeringForce = influence;

	// acceleration = Force/Mass
	Vector2D acceleration = steeringForce / m_mass;


	m_velocity += acceleration * deltaTime;
	
	//make sure vehicle does not exceed maximum velocity
	m_velocity.truncate(m_maxSpeed);


	//update the position
	m_position += m_velocity * deltaTime;

	if (m_velocity.getLength() > 0, 00000001)
	{
		m_heading = m_velocity.normalized();
	}

	FWApplication::GetInstance()->SetColor(Color(50, 50, 255, 255));
	//wrapAround

	double x = m_position.getX();
	double y = m_position.getY();

	if (x > 1000)
	{
		m_position.setX(x - 1000);
	}
	else if (x < 0)
	{
		m_position.setX(x + 1000);
	}

	if (y > 700)
	{
		m_position.setY(y - 700);
	}
	else if (y < 0)
	{
		m_position.setY(y + 700);
	}
}

std::vector<std::shared_ptr<MovingEntity>> Vehicle::getNeighbours(double range)
{

	std::vector<std::shared_ptr<MovingEntity>> neighbours = std::vector<std::shared_ptr<MovingEntity>>();
	for (const auto& value : m_world->getCows())
	{
		if (value->getID() != this->getID())
		{
			int distance = getPosition().distanceTo(value->getPosition());
			if (distance < range)
			{
				neighbours.push_back(value);
			}
		}
	}
	return neighbours;
}
