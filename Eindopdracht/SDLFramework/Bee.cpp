#include "Bee.h"
#include <SDL_render.h>

Bee::Bee() {
	texture = mApplication->LoadTexture("bee.png");
	this->SetTexture(texture);
	this->SetSize(25, 19);
}

Bee::~Bee() {
	SDL_DestroyTexture(texture);
}

void Bee::Update(float deltaTime) {
	//const int x = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + 400);
	const int y = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + 300);
	SetOffset(300, y);
}