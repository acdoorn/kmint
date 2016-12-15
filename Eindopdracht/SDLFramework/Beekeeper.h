#pragma once

#include "IGameObject.h"

class Beekeeper : public IGameObject {
public:
	Beekeeper();
	~Beekeeper();
	void Update(float deltaTime);

private:
	SDL_Texture *texture;
};