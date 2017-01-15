#pragma once
#include "Vehicle.h"
#include "StateMachine.h"
#include "Vertex.h"
#include "Bee.h"


class Beekeeper : public Vehicle
{
private:
	std::shared_ptr<StateMachine<Beekeeper>> m_stateMachine;
	SDL_Texture* m_netTexture;
	SDL_Texture* m_areaTexture;
	double m_catchDistance;
	Vertex* currentVertex;
	Vertex* panicVertex;
	Vertex* nextVertex;
	bool catching = true;
	int maxAmountBees = 10;
	int amountOfBees = 0;
	int returnToBaseChance = 33;
	int panicChance = 33;
	int searchPillChance = 33;
	int amountOfChange = 1; // amount the chances decrease that didn't currently score, and this *2 is the amount the state that scored points increases
	Color color;
	std::string statestring;
public:
	void setCurrentVertex(Vertex* v) { currentVertex = v; };
	void setPanicVertex(Vertex* v) { currentVertex = v; };
	Vertex* getPanicVertex() {	return panicVertex;	};
	Beekeeper(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world);
	std::shared_ptr<StateMachine<Beekeeper>> getStateMachine();
	Vertex* getNextVertex();
	void checkVertex();
	Vertex* calcNextVertex();
	Vertex* getCurrentVertex();
	virtual void update(double deltaTime) override;
	double getCatchDistance();
	void draw();
	bool isCatching();
	void setCatching(bool);
	int getMaxAmountBees();
	void setMaxAmountBees(int amount);
	void addBee(std::shared_ptr<MovingEntity>);
	void setColor(Color c);
	int nrCaughtBees();
	void addBee();
	void removeBee();
	std::string getCurrentState() { return statestring; };
	void setCurrentState(std::string s) { statestring = s; };
	void resetAmountOfBees();
	bool lowerReturnToBaseChance() {if (returnToBaseChance != 0) {	returnToBaseChance = returnToBaseChance - amountOfChange;	return true;}	return false;};
	bool lowerPanicChance() {		if (panicChance != 0) {	panicChance = panicChance - amountOfChange;	return true;}	return false;};
	bool lowerSearchPillChance() {	if (searchPillChance != 0) {searchPillChance = searchPillChance - amountOfChange; return true;}	return false;};
	void increaseReturnToBaseChance() { returnToBaseChance = returnToBaseChance + amountOfChange;};
	void increasePanicChance() {		panicChance = panicChance + amountOfChange;};
	void increaseSearchPillChance() {	searchPillChance = searchPillChance + amountOfChange;};
	int getReturnToBaseChance() { return returnToBaseChance; };
	int getPanicChance() { return panicChance; };
	int getSearchPillChance() { return searchPillChance; };
};

