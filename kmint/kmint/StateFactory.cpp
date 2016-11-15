#pragma once
#include "stdafx.h"
#include "StateFactory.h"



StateFactory::StateFactory()
{
	
}


StateFactory::~StateFactory()
{
}


void StateFactory::Register(std::string name, State* s){
	states.insert({ name, s });
}

State* StateFactory::getState(std::string name){
	return states.find(name)->second;
}