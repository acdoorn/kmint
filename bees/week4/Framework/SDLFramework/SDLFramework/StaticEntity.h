#pragma once
#include "BaseGameEntity.h"

class StaticEntity : public BaseGameEntity
{
public:
	StaticEntity(double x, double y, int width, int height);
	void draw() override;
};

