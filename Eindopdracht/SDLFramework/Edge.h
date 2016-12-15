#pragma once
#include "Vertex.h"
class Edge
{
public:
	Edge(Vertex* one, Vertex* two);
	~Edge();
	Vertex* a;
	Vertex* b;
	float weight;
};
