#pragma once
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include <SFML\Graphics.hpp>
class Graph_A_star
{
public:
	Graph_A_star();
	~Graph_A_star();
	std::vector<Vertex*> vertices;
	std::vector<Edge*> edges;
	void drawGraph(sf::RenderWindow* window);
	Vertex* GetRandomVertixNot(Vertex* v);
	Vertex* GetRandomVertixNot(std::vector<Vertex*> v);
	Vertex* GetNextVertex(Vertex * start, Vertex * end);
	std::vector<std::pair<int, int>> Graph_SearchAStar(Vertex* start, Vertex* end);


private:
	sf::Font font;

	bool alreadyCalculated = false;
	std::vector<std::pair<int, int>> locations;
	std::pair<int, int> location;
	int index;
	float Graph_A_star::guessedCost(Vertex* start, Vertex* end);
};

