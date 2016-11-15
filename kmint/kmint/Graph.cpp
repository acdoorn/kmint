#pragma once
#include "stdafx.h"
#include "Graph.h"
#include "Vertex.h"
#include <vector>
#include <SFML\Graphics.hpp>
#include <cmath>


Graph::Graph()
{

	srand(time(NULL));
	Vertex* nv = new Vertex(480, 450);
	vertices.push_back(nv);
	nv = new Vertex(1536, 216);
	vertices.push_back(nv);
	nv = new Vertex(800, 630);
	vertices.push_back(nv);
	nv = new Vertex(1120, 144);
	vertices.push_back(nv);
	nv = new Vertex(320, 720);
	vertices.push_back(nv);
	nv = new Vertex(320, 216);
	vertices.push_back(nv);
	nv = new Vertex(832, 684);
	vertices.push_back(nv);
	nv = new Vertex(352, 594);
	vertices.push_back(nv);
	nv = new Vertex(1184, 594);
	vertices.push_back(nv);
	nv = new Vertex(1280, 756);
	vertices.push_back(nv);
	nv = new Vertex(1440, 360);
	vertices.push_back(nv);
	nv = new Vertex(800, 360);
	vertices.push_back(nv);

	Edge* e = new Edge(vertices[0], vertices[5]);
	edges.push_back(e);
	e = new Edge(vertices[0], vertices[7]);
	edges.push_back(e);
	e = new Edge(vertices[2], vertices[7]);
	edges.push_back(e);
	e = new Edge(vertices[4], vertices[7]);
	edges.push_back(e);
	e = new Edge(vertices[4], vertices[2]);
	edges.push_back(e);
	e = new Edge(vertices[2], vertices[11]);
	edges.push_back(e);
	e = new Edge(vertices[2], vertices[6]);
	edges.push_back(e);
	e = new Edge(vertices[6], vertices[8]);
	edges.push_back(e);
	e = new Edge(vertices[8], vertices[9]);
	edges.push_back(e);
	e = new Edge(vertices[8], vertices[11]);
	edges.push_back(e);
	e = new Edge(vertices[8], vertices[10]);
	edges.push_back(e);
	e = new Edge(vertices[10], vertices[1]);
	edges.push_back(e);
	e = new Edge(vertices[10], vertices[3]);
	edges.push_back(e);
	e = new Edge(vertices[0], vertices[11]);
	edges.push_back(e);
	e = new Edge(vertices[5], vertices[3]);
	edges.push_back(e);

	if (!font.loadFromFile("Resources/OpenSansLight.ttf"))
	{
		int i = 0;
	}
}


Graph::~Graph()
{
}

void Graph::drawGraph(sf::RenderWindow* window){
	std::vector<sf::Vertex> lines;
	for (int i = 0; i < edges.size(); i++){
		lines.push_back(sf::Vector2f(edges[i]->b->location.first, edges[i]->b->location.second));
		lines.push_back(sf::Vector2f(edges[i]->a->location.first, edges[i]->a->location.second));

	}
	window->draw(&lines[0], lines.size(), sf::Lines);
	sf::CircleShape s(10);
	sf::Text text;
	text.setFillColor(sf::Color::White);
	text.setCharacterSize(16);
	text.setFont(font);
	
	for (int i = 0; i < vertices.size(); i++){
		
		s.setFillColor(sf::Color(255, 0, 0));
		s.setPosition(vertices[i]->location.first - 10, vertices[i]->location.second - 10);

		text.setString(std::to_string(i));
		text.setPosition(vertices[i]->location.first - 8, vertices[i]->location.second - 10);
		window->draw(s);
		window->draw(text);


	}
	
}

Vertex* Graph::GetRandomVertixNot(Vertex* v){
	Vertex* out;
	out = vertices[(rand() % (vertices.size()))];
	while (out == v){
		out = vertices[(rand() % (vertices.size()))];
	}
	return out;
}

void Graph::ShortestPath(Vertex* start, Vertex* end){
	std::vector<Vertex*> ClosedSet;
	std::vector<Vertex*> OpenSet;
	std::map<Vertex*, float> gScore;
	std::map<Vertex*, float> fScore;
	std::map<Vertex*, Vertex*> cameFrom;
	gScore[start] = 0;
	fScore[start] = gScore[start] + guessedCost(start, end);
	Vertex* current = nullptr;
	
	OpenSet.push_back(start);
	while (!OpenSet.empty()){
		// setting current with lowest F score;
		int lowestFScore = 1000000000;
		for (int i = 0; i < OpenSet.size(); i++){
			if (fScore[OpenSet[i]] < lowestFScore){
				current = OpenSet[i];
				lowestFScore = fScore[current];
			}
		}
		if (current == end){
			// return lijst van vertices van start naar end
		}
		OpenSet.erase(std::remove(OpenSet.begin(), OpenSet.end(),current),OpenSet.end());
		ClosedSet.push_back(current);

		for each (Vertex* v in current->getNeighbours())
		{
			if (std::find(ClosedSet.begin(), ClosedSet.end(), v) != ClosedSet.end()){
				
			}
			if (!(std::find(OpenSet.begin(), OpenSet.end(), v) != OpenSet.end())){

			}
		}

	}

}

float Graph::guessedCost(Vertex* start, Vertex* end){
	return sqrt((pow(start->location.first - end->location.first, 2)) + pow(start->location.second - end->location.second, 2));
}
