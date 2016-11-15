#pragma once
#include <map>
#include "State.h"
#include <string>

class StateFactory
{
public:
	~StateFactory();

	static StateFactory& getInstance(){
		static StateFactory instance;
		return instance;
	}
	
	void Register(std::string name, State* s);
	State* getState(std::string name);
private:
	StateFactory();
	std::map<std::string, State*> states;
	
	static StateFactory* instance;
};

