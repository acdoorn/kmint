#pragma once

#include "IGameObject.h"
#include "Vertex.h"

class Bee : public IGameObject {
public:
	Bee();
	~Bee();
	void Update(float deltaTime);
	Vertex* location = new Vertex(300, 300);

private:
	SDL_Texture *texture;
};