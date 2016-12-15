#pragma once
#include "Graph.h"
#include "Vertex.h"
#include <vector>
#include <cmath>
#include <iterator>
#include <queue>
#include <iostream>


Graph::Graph()
{
}


Graph::~Graph()
{
}

Vertex* Graph::GetRandomVertixNot(Vertex* v) {
	Vertex* out;
	out = vertices[(rand() % (vertices.size()))];
	while (out == v) {
		out = vertices[(rand() % (vertices.size()))];
	}
	return out;
}

Vertex* Graph::GetRandomVertixNot(std::vector<Vertex*> v) {
	Vertex* out;
	bool t = true;
	out = vertices[(rand() % (vertices.size()))];
	while (t) {
		if (std::find(v.begin(), v.end(), out) != v.end()) {
			out = vertices[(rand() % (vertices.size()))];
		}
		else {
			t = false;
		}
	}
	return out;
}

Vertex* Graph::GetNextVertex(Vertex* start, Vertex* end) {
	Vertex* out = nullptr;
	if (start != end){

		locations = SearchAStar(start, end);
		index = locations.size() - 1;
		for each (Vertex* v in vertices) {
			location = locations.at(index);
			if (v->x == location.first && v->y == location.second) {
				out = v;
			}
		}
	}
	return out;


}

std::vector<std::pair<int, int>> Graph::SearchAStar(Vertex* start, Vertex* end) {
	std::vector<std::pair<int, int>> path;

	// Define points to work with
	Vertex* current = start;
	Vertex* child;

	// Define the open and the close list
	std::vector<Vertex*> openList;
	std::vector<Vertex*> closedList;
	std::vector<Vertex*>::iterator i;

	unsigned int n = 0;

	// Add the start point to the openList
	openList.push_back(start);
	start->visited = true;

	while (n == 0 || (current != end && n < 50))
	{
		// Look for the smallest F value in the openList and make it the current point
		for (i = openList.begin(); i != openList.end(); ++i)
		{
			if (i == openList.begin() || (*i)->getFScore() <= current->getFScore())
			{
				current = (*i);
			}
		}

		// Stop if we reached the end
		if (current == end)
		{
			break;
		}

		// Remove the current point from the openList
		openList.erase(std::remove(openList.begin(), openList.end(), current), openList.end());
		current->visited = false;

		// Add the current point to the closedList
		closedList.push_back(current);
		current->closed = true;

		// Get all current's adjacent walkable points
		for each (Vertex* v in current->getNeighbours()) {
			child = v;

			// If it's closed then pass
			if (child->closed)
			{
				continue;
			}

			// If it's already in the openList
			if (child->visited)
			{
				// If it has a worste g score than the one that pass through the current point
				// then its path is improved when it's parent is the current point
				if (child->getGScore() > child->getGScore(current))
				{
					// Change its parent and g score
					child->setParent(current);
					child->computeScores(end);
				}
			}
			else
			{
				// Add it to the openList with current point as parent
				openList.push_back(child);
				child->visited = true;

				// Compute it's g, h and f score
				child->setParent(current);
				child->computeScores(end);
			}

		}

		n++;
	}

	// Reset
	for (i = openList.begin(); i != openList.end(); ++i)
	{
		(*i)->visited = false;
	}
	for (i = closedList.begin(); i != closedList.end(); ++i)
	{
		(*i)->closed = false;
	}

	// Resolve the path starting from the end point
	while (current->hasParent() && current != start)
	{
		path.push_back(current->location);
		current = current->getParent();
		n++;
	}

	return path;
}


float Graph::guessedCost(Vertex* start, Vertex* end) {
	return sqrt((pow(start->location.first - end->location.first, 2)) + pow(start->location.second - end->location.second, 2));
}

void Graph::addVertex(Vertex* v) {
	vertices.push_back(v);
}

void Graph::addEdge(Edge* e) {
	edges.push_back(e);
}