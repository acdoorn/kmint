#pragma once
#include "stdafx.h"
#include "State.h"
#include "Cow.h"
#include "Bunny.h"
#include "StateFactory.h"


State::State(std::string name)
{
	stateName = name;
}


State::~State()
{
}

void State::Register(Graph_A_star* graph){

}
