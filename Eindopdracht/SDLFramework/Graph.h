#pragma once
#include <vector>
#include "Vertex.h"
#include "Edge.h"
class Graph
{
public:
	Graph();
	~Graph();
	std::vector<Vertex*> vertices;
	std::vector<Edge*> edges;
	Vertex* GetRandomVertixNot(Vertex* v);
	Vertex* GetRandomVertixNot(std::vector<Vertex*> v);
	Vertex* GetNextVertex(Vertex * start, Vertex * end);
	std::vector<std::pair<int, int>> SearchAStar(Vertex* start, Vertex* end);
	void addVertex(Vertex* v);
	void addEdge(Edge* e);


private:
	bool alreadyCalculated = false;
	std::vector<std::pair<int, int>> locations;
	std::pair<int, int> location;
	int index;
	float Graph::guessedCost(Vertex* start, Vertex* end);
};
