#pragma once
#include "Pill.h"


Pill::Pill(Vertex* loc) : 
	StaticEntity(loc->x, loc->y, 40, 40)
{
	location = loc;
	m_texture = FWApplication::GetInstance()->LoadTexture("../Resources/pill.png");
	m_position.setX(location->x);
	m_position.setY(location->y);
}

bool Pill::isEaten() {
	return eaten;
}

void Pill::eatPill() {
	eaten = true;
}

void Pill::reSpawn() {
	eaten = false;
}

Vertex* Pill::getLocation() {
	return location;
}

void Pill::setLocation(Vertex* loc) {
	location = loc;
}

void Pill::update(double deltaTime) {

}

void Pill::draw() {

	if (m_texture && !isEaten())
	{
		int x = m_position.getX();
		int y = m_position.getY();

		FWApplication::GetInstance()->DrawTexture(m_texture, x, y, m_width, m_height, 270, 0);
		FWApplication::GetInstance()->SetColor(Color(255, 10, 40, 255));
	}
}
Pill::~Pill()
{
}