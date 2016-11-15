#pragma once
#include "stdafx.h"
#include "Edge.h"


Edge::Edge(Vertex* one, Vertex* two)
{
	a = one;
	b = two;
	a->addEdge(this);
	b->addEdge(this);
	weight = 1000000;
}


Edge::~Edge()
{
}
