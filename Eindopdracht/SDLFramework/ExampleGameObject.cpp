#include "ExampleGameObject.h"
#include <SDL_render.h>

ExampleGameObject::ExampleGameObject() {
	texture = mApplication->LoadTexture("bee.png");
	this->SetTexture(texture);
	this->SetSize(25, 19);
}

ExampleGameObject::~ExampleGameObject() {
	SDL_DestroyTexture(texture);
}

void ExampleGameObject::Update(float deltaTime) {
	const int x = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + 400);
	const int y = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + 300);
	SetOffset(x, y);
}