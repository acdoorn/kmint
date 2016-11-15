#pragma once
#include "stdafx.h"
#include "Graph_A_star.h"
#include "Vertex.h"
#include <vector>
#include <SFML\Graphics.hpp>
#include <cmath>
#include <iterator>
#include <queue>
#include <iostream>


Graph_A_star::Graph_A_star()
{

	srand(time(NULL));
	Vertex* nv = new Vertex(300, 10);
	vertices.push_back(nv);
	nv = new Vertex(300, 107);
	vertices.push_back(nv);
	nv = new Vertex(300, 203);
	vertices.push_back(nv);
	nv = new Vertex(300, 300);//start
	vertices.push_back(nv);
	nv = new Vertex(300, 397);
	vertices.push_back(nv);
	nv = new Vertex(300, 493);
	vertices.push_back(nv);
	nv = new Vertex(300, 590);
	vertices.push_back(nv);

	nv = new Vertex(10, 300);
	vertices.push_back(nv);
	nv = new Vertex(107, 300);
	vertices.push_back(nv);
	nv = new Vertex(203, 300);
	vertices.push_back(nv);
	nv = new Vertex(397, 300);
	vertices.push_back(nv);
	nv = new Vertex(493, 300);
	vertices.push_back(nv);
	nv = new Vertex(590, 300);
	vertices.push_back(nv);

	nv = new Vertex(97, 97);
	vertices.push_back(nv);
	nv = new Vertex(193, 193);
	vertices.push_back(nv);
	nv = new Vertex(242, 242);
	vertices.push_back(nv);
	nv = new Vertex(348, 348);
	vertices.push_back(nv);
	nv = new Vertex(407, 407);
	vertices.push_back(nv);
	nv = new Vertex(503, 503);
	vertices.push_back(nv);

	nv = new Vertex(97, 503);
	vertices.push_back(nv);
	nv = new Vertex(193, 407);
	vertices.push_back(nv);
	nv = new Vertex(242, 348);
	vertices.push_back(nv);
	nv = new Vertex(348, 242);
	vertices.push_back(nv);
	nv = new Vertex(407, 193);
	vertices.push_back(nv);
	nv = new Vertex(503, 97);
	vertices.push_back(nv);


	Edge* e = new Edge(vertices[0], vertices[1]);
	edges.push_back(e);
	e = new Edge(vertices[0], vertices[13]);
	edges.push_back(e);
	e = new Edge(vertices[0], vertices[24]);
	edges.push_back(e);
	e = new Edge(vertices[1], vertices[2]);
	edges.push_back(e);
	e = new Edge(vertices[1], vertices[14]);
	edges.push_back(e);
	e = new Edge(vertices[1], vertices[23]);
	edges.push_back(e);
	e = new Edge(vertices[2], vertices[3]);
	edges.push_back(e);
	e = new Edge(vertices[2], vertices[15]);
	edges.push_back(e);
	e = new Edge(vertices[2], vertices[22]);
	edges.push_back(e);
	e = new Edge(vertices[3], vertices[15]);
	edges.push_back(e);
	e = new Edge(vertices[3], vertices[22]);
	edges.push_back(e);
	e = new Edge(vertices[3], vertices[10]);
	edges.push_back(e);
	e = new Edge(vertices[3], vertices[16]);
	edges.push_back(e);
	e = new Edge(vertices[3], vertices[4]);
	edges.push_back(e);
	e = new Edge(vertices[3], vertices[21]);
	edges.push_back(e);
	e = new Edge(vertices[3], vertices[9]);
	edges.push_back(e);
	e = new Edge(vertices[3], vertices[4]);
	edges.push_back(e);
	e = new Edge(vertices[4], vertices[5]);
	edges.push_back(e);
	e = new Edge(vertices[4], vertices[21]);
	edges.push_back(e);
	e = new Edge(vertices[4], vertices[16]);
	edges.push_back(e);
	e = new Edge(vertices[5], vertices[6]);
	edges.push_back(e);
	e = new Edge(vertices[5], vertices[17]);
	edges.push_back(e);
	e = new Edge(vertices[5], vertices[20]);
	edges.push_back(e);
	e = new Edge(vertices[6], vertices[18]);
	edges.push_back(e);
	e = new Edge(vertices[6], vertices[19]);
	edges.push_back(e);
	e = new Edge(vertices[9], vertices[15]);
	edges.push_back(e);
	e = new Edge(vertices[9], vertices[21]);
	edges.push_back(e);
	e = new Edge(vertices[8], vertices[14]);
	edges.push_back(e);
	e = new Edge(vertices[8], vertices[20]);
	edges.push_back(e);
	e = new Edge(vertices[7], vertices[13]);
	edges.push_back(e);
	e = new Edge(vertices[7], vertices[19]);
	edges.push_back(e);
	e = new Edge(vertices[10], vertices[22]);
	edges.push_back(e);
	e = new Edge(vertices[10], vertices[16]);
	edges.push_back(e);
	e = new Edge(vertices[11], vertices[23]);
	edges.push_back(e);
	e = new Edge(vertices[11], vertices[17]);
	edges.push_back(e);
	e = new Edge(vertices[12], vertices[24]);
	edges.push_back(e);
	e = new Edge(vertices[12], vertices[18]);
	edges.push_back(e);

	if (!font.loadFromFile("Resources/OpenSansLight.ttf"))
	{
		int i = 0;
	}
}


Graph_A_star::~Graph_A_star()
{
}

void Graph_A_star::drawGraph(sf::RenderWindow* window) {
	std::vector<sf::Vertex> lines;
	for (int i = 0; i < edges.size(); i++) {
		lines.push_back(sf::Vector2f(edges[i]->b->location.first, edges[i]->b->location.second));
		lines.push_back(sf::Vector2f(edges[i]->a->location.first, edges[i]->a->location.second));

	}
	window->draw(&lines[0], lines.size(), sf::Lines);
	sf::CircleShape s(10);
	sf::Text text;
	text.setColor(sf::Color::White);
	text.setCharacterSize(16);
	text.setFont(font);

	for (int i = 0; i < vertices.size(); i++) {

		s.setFillColor(sf::Color(255, 0, 0));
		s.setPosition(vertices[i]->location.first - 10, vertices[i]->location.second - 10);

		text.setString(std::to_string(i));
		text.setPosition(vertices[i]->location.first - 8, vertices[i]->location.second - 10);
		window->draw(s);
		window->draw(text);


	}

}

Vertex* Graph_A_star::GetRandomVertixNot(Vertex* v) {
	Vertex* out;
	out = vertices[(rand() % (vertices.size()))];
	while (out == v) {
		out = vertices[(rand() % (vertices.size()))];
	}
	return out;
}

Vertex* Graph_A_star::GetRandomVertixNot(std::vector<Vertex*> v) {
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

Vertex* Graph_A_star::GetNextVertex(Vertex* start, Vertex* end) {
	Vertex* out = nullptr;
	if (start != end){

		locations = Graph_SearchAStar(start, end);
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

std::vector<std::pair<int, int>> Graph_A_star::Graph_SearchAStar(Vertex* start, Vertex* end) {
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


float Graph_A_star::guessedCost(Vertex* start, Vertex* end) {
	return sqrt((pow(start->location.first - end->location.first, 2)) + pow(start->location.second - end->location.second, 2));
}
