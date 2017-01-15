#pragma once
#include "Vertex.h"
#include "StaticEntity.h"
class Pill : StaticEntity
{
private:
	bool eaten = false;
	Vertex* location;

public:
	Pill(Vertex* loc);
	~Pill();
	bool isEaten();
	void eatPill();
	void reSpawn();
	Vertex* getLocation();
	void setLocation(Vertex* loc);
	virtual void update(double deltaTime) override;
	void draw();
};

