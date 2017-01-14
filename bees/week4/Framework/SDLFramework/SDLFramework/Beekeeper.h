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
	Vertex* nextVertex;
	bool catching = true;
	int maxAmountBees = 10;
	int amountOfBees = 0;
	int returnToBaseChance = 33;
	int panicChance = 33;
	int searchPillChance = 33;
public:
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
	void addBee(std::shared_ptr<MovingEntity>);
	int nrCaughtBees();
	void addBee();
	void removeBee();
	void resetAmountOfBees();
	bool lowerReturnToBaseChance() {if (returnToBaseChance != 0) {	returnToBaseChance = returnToBaseChance - 3;	return true;}	return false;};
	bool lowerPanicChance() {		if (panicChance != 0) {	panicChance = panicChance - 3;	return true;}	return false;};
	bool lowerSearchPillChance() {	if (searchPillChance != 0) {searchPillChance = searchPillChance - 3; return true;}	return false;};
	void increaseReturnToBaseChance() { returnToBaseChance = returnToBaseChance + 3;};
	void increasePanicChance() {		panicChance = panicChance + 3;};
	void increaseSearchPillChance() {	searchPillChance = searchPillChance + 3;};
	int getReturnToBaseChance() { return returnToBaseChance; };
	int getPanicChance() { return panicChance; };
	int getSearchPillChance() { return searchPillChance; };
};

