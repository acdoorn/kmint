#pragma once
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include <SFML\Graphics.hpp>
class Graph
{
public:
	Graph();
	~Graph();
	std::vector<Vertex*> vertices;
	std::vector<Edge*> edges;
	void Graph::drawGraph(sf::RenderWindow* window);
	Vertex* Graph::GetRandomVertixNot(Vertex* v);
	void Graph::ShortestPath(Vertex* start, Vertex* end);

private:
	sf::Font font;
	float Graph::guessedCost(Vertex* start, Vertex* end);
};

