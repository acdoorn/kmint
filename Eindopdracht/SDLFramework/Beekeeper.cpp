#include "Beekeeper.h"
#include <SDL_render.h>

Beekeeper::Beekeeper() {
	texture = mApplication->LoadTexture("beekeeper.png");
	this->SetTexture(texture);
	this->SetSize(52, 75);
}

Beekeeper::~Beekeeper() {
	SDL_DestroyTexture(texture);
}

void Beekeeper::Update(float deltaTime) {
	SetOffset(384, 555);
}