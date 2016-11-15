#pragma once
#include "stdafx.h"
#include "Vertex.h"
#include "Edge.h"


Vertex::Vertex(int x, int y)
{
	this->location = std::make_pair(x, y);
	this->x = x;
	this->y = y;
	parent = NULL;
	f = g = h = 0;
	visited = false;
	closed = false;
}


Vertex::~Vertex()
{
}

void Vertex::addEdge(Edge* e){
	edges.push_back(e);
}

Vertex* Vertex::getParent()
{
	return parent;
}

void Vertex::setParent(Vertex *p)
{
	parent = p;
}

std::vector<Vertex*> Vertex::getNeighbours(){
	std::vector<Vertex*> neighbours;
	for each (Edge* e in edges)
	{
		if (e->a == this){
			neighbours.push_back(e->b);
		}else
		{
			neighbours.push_back(e->a);
		}
	}
	return neighbours;
}

std::vector<Edge*> Vertex::getEdges(){
	return edges;
}

int Vertex::getX()
{
	return x;
}

int Vertex::getY()
{
	return y;
}

float Vertex::getXf()
{
	return (float)x;
}

float Vertex::getYf()
{
	return (float)y;
}

int Vertex::getGScore(Vertex *p)
{

	return p->g + (getEdgeFrom(p)->weight);
}

int Vertex::getHScore(Vertex *p)
{
	return (abs(p->x - x) + abs(p->y - y)) * 10;
}

int Vertex::getGScore()
{
	return g;
}

int Vertex::getHScore()
{
	return h;
}

int Vertex::getFScore()
{
	return f;
}

void Vertex::computeScores(Vertex *end)
{
	g = getGScore(parent);
	h = getHScore(end);
	f = g + h;
}

bool Vertex::hasParent()
{
	return parent != NULL;
}

Edge* Vertex::getEdgeFrom(Vertex* v){
	for (Edge* e : edges){
		if ((e->a == this || e->b == this) && (e->a == v || e->b == v)){
			return e;
		}
	}
}

Vertex* Vertex::getRandomNeighbour(){
	int number = rand() % edges.size();
	if (edges[number]->a == this){
		return edges[number]->b;
	}
	else {
		return edges[number]->a;
	}
}
