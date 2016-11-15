#pragma once
#include <vector>
class Edge;
class Vertex
{
public:
	Vertex(int x, int y);
	~Vertex();
	std::vector<Edge*> edges;
	std::pair<int, int> location;
	void addEdge(Edge* e);
	Vertex * getParent();
	void setParent(Vertex * p);
	std::vector<Vertex*> getNeighbours();
	std::vector<Edge*> getEdges();
	int getX();
	int getY();
	bool visited, closed;
	int	x, y, f, g, h;
	float getXf();
	float getYf();
	int getGScore(Vertex * p);
	int getHScore(Vertex * p);
	int getGScore();
	int getHScore();
	int getFScore();
	void computeScores(Vertex * end);
	bool hasParent();
	Vertex* parent;
	Edge* getEdgeFrom(Vertex* p);
	Vertex* getRandomNeighbour();
};

