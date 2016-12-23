#include "Beekeeper.h"
#include <SDL_render.h>
#include <SDL_opengl.h>

Beekeeper::Beekeeper() {
	texture = mApplication->LoadTexture("beekeeper.png");
	this->SetTexture(texture);
	this->SetSize(52, 75);
}
Beekeeper::Beekeeper(Graph* g, Bee* b) {
	texture = mApplication->LoadTexture("beekeeper.png");
	this->SetTexture(texture);
	this->SetSize(52, 75);
	graph = g;
	Vertex* out;
	location = g->vertices.at(g->vertices.size()-1);
	SetOffset(location->x, location->y);
	closestBee = b;
}

Beekeeper::~Beekeeper() {
	SDL_DestroyTexture(texture);
}

void Beekeeper::moveTo(int x, int y) {
	std::vector<Vertex*>::iterator it;
	Vertex* findvertex = new Vertex(x, y);
	it = std::find(graph->vertices.begin(), graph->vertices.end(), findvertex);
	if (it != graph->vertices.end())
		location = *it;

}

void Beekeeper::Update(float deltaTime) {
	// Vertex where we want to go for testing:
	// auto vertex103 = new Vertex(28, 31); 
	// bee location = 300,300;

	/* move method:
		const int x = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + 400);
		const int y = (int)(sin(mApplication->GetTimeSinceStartedMS() / 300.0) * 15.0 + 300);
		SetOffset(x, y);
	*/
	
}