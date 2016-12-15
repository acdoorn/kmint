#pragma once

#include "IGameObject.h"

class Bee : public IGameObject {
public:
	Bee();
	~Bee();
	void Update(float deltaTime);

private:
	SDL_Texture *texture;
};