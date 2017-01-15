#include "BeekeeperStates.h"
#include "Beekeeper.h"
#include "Graph.h"
#include <time.h>
//BeekeeperWanderState
//BeekeeperReturnToBaseState
//BeekeeperPanicState
//BeekeeperSearchPillState
//BeekeeperUpgradedState

void BeekeeperWanderState::enter(Beekeeper *)
{
}

void BeekeeperWanderState::execute(Beekeeper * beekeeper, double deltaTime)
{
	//TODO:
	//Beslissing inbouwen als er 10 bijen gevangen zijn tussen 3 states
	//effectiviteit aan hand van de score die toegevoegd wordt, als er score wordt toegevoegd voor de state switched gaat kans omhoog met 6%, anderen krijgen -3%, totaal moet 99 blijven
	if (beekeeper->nrCaughtBees() >= beekeeper->getMaxAmountBees() || beekeeper->getWorld()->getBees().size() == 0) {
		//int random = rand() % 99 + 1; //																random int in range 1 to 99;

		//if (random <= beekeeper->getReturnToBaseChance()) //																BeekeeperReturnToBaseState
		//{
		//	beekeeper->setCatching(false);
		//	beekeeper->setCurrentState("RTB");
		//	std::shared_ptr<BeekeeperReturnToBaseState> nextState = std::make_shared<BeekeeperReturnToBaseState>();
		//	beekeeper->getStateMachine()->changeState(nextState);
		//}
		//else if (random > beekeeper->getReturnToBaseChance() && random <= (beekeeper->getSearchPillChance()+ beekeeper->getReturnToBaseChance())) { //		BeekeeperSearchPillState
		//	beekeeper->setCatching(false);
		//	beekeeper->setCurrentState("Search pill");
		//	std::shared_ptr<BeekeeperSearchPillState> nextState = std::make_shared<BeekeeperSearchPillState>();
		//	beekeeper->getStateMachine()->changeState(nextState);
		//}
		//else if (random > (beekeeper->getReturnToBaseChance() + beekeeper->getSearchPillChance())) //										BeekeeperPanicState
		//{
		//	beekeeper->setCatching(false);
		//	beekeeper->setCurrentState("Panic");
		//	std::shared_ptr<BeekeeperPanicState> nextState = std::make_shared<BeekeeperPanicState>();
		//	beekeeper->getStateMachine()->changeState(nextState);
		//}

		beekeeper->setCatching(false);
		beekeeper->setCurrentState("Panic");
		std::shared_ptr<BeekeeperPanicState> nextState = std::make_shared<BeekeeperPanicState>();
		beekeeper->getStateMachine()->changeState(nextState);
	}
	else {
		if (!beekeeper->isCatching())
			beekeeper->setCatching(true);
	}
	

	beekeeper->checkVertex(beekeeper->getBeesLocation());
	//Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
}

std::string BeekeeperWanderState::name() {
	return "Wander";
}

void BeekeeperWanderState::exit(Beekeeper *)
{
}

void BeekeeperReturnToBaseState::enter(Beekeeper *)
{
}

void BeekeeperReturnToBaseState::execute(Beekeeper * beekeeper, double deltaTime)
{
	Graph* g = beekeeper->getWorld()->getGraph();
	Vertex* base = g->vertices.at(g->vertices.size() - 1);

	if (base == beekeeper->getCurrentVertex()) {
		int temp = beekeeper->getWorld()->getScore();
		beekeeper->getWorld()->upScore(beekeeper->nrCaughtBees());
		beekeeper->resetAmountOfBees();
		if (temp < beekeeper->getWorld()->getScore()) {
			if (beekeeper->getStateMachine()->getPreviousState().get()->name() == "Wander") {// als returntobase direct door wanderstate aangeroepen wordt.
				if (beekeeper->lowerPanicChance()) {
					beekeeper->increaseReturnToBaseChance();
				}
				if (beekeeper->lowerSearchPillChance()) {
					beekeeper->increaseReturnToBaseChance();
				}
			}
			if (beekeeper->getStateMachine()->getPreviousState().get()->name() == "Panic") {// als de beekeeper in paniek heeft rondgelopen in de vorige state
				if (beekeeper->lowerReturnToBaseChance()) {
					beekeeper->increasePanicChance();
				}
				if (beekeeper->lowerSearchPillChance()) {
					beekeeper->increasePanicChance();
				}
			}
			if (beekeeper->getStateMachine()->getPreviousState().get()->name() == "Upgraded") {// als de beekeeper geupgrade is door de pill
				if (beekeeper->lowerReturnToBaseChance()) {
					beekeeper->increaseSearchPillChance();
				}
				if (beekeeper->lowerPanicChance()) {
					beekeeper->increaseSearchPillChance();
				}
			}
			//state omhoog
		}
		beekeeper->setCurrentState("Chase bees");
		std::shared_ptr<BeekeeperWanderState> nextState = std::make_shared<BeekeeperWanderState>();
		beekeeper->getStateMachine()->changeState(nextState);
	}
	else {
		beekeeper->checkVertex(base);
		Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
		Vector2D influence = seperation;

		beekeeper->move(influence, deltaTime);
	}


}

std::string BeekeeperReturnToBaseState::name() {
	return "";
}

void BeekeeperReturnToBaseState::exit(Beekeeper *)
{
}

void BeekeeperPanicState::enter(Beekeeper *)
{
}

void BeekeeperPanicState::execute(Beekeeper * beekeeper, double deltaTime)
{
	if (beekeeper->nrCaughtBees() == 0) {
		beekeeper->setPanicVertex(beekeeper->getCurrentVertex());
	}
	if (beekeeper->getCurrentVertex() == beekeeper->getPanicVertex() && beekeeper->nrCaughtBees() == 0) {
		beekeeper->setCurrentState("RTB");
		std::shared_ptr<BeekeeperReturnToBaseState> nextState = std::make_shared<BeekeeperReturnToBaseState>();
		beekeeper->getStateMachine()->changeState(nextState);
	}
	else if (beekeeper->getCurrentVertex() == beekeeper->getPanicVertex()) {
		beekeeper->setPanicVertex(beekeeper->getWorld()->getGraph()->GetRandomVertixNot(beekeeper->getPanicVertex()));
	}
	else {
		if (beekeeper->getNextVertex() == beekeeper->getCurrentVertex()) {
			if (beekeeper->nrCaughtBees() > 0) {
				beekeeper->removeBee();
			}
			beekeeper->setCurrentVertex(beekeeper->getNextVertex());
		}
	}
	beekeeper->checkVertex(beekeeper->getPanicVertex());
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
}

std::string BeekeeperPanicState::name() {
	return "Panic";
}

void BeekeeperPanicState::exit(Beekeeper *)
{
}

void BeekeeperSearchPillState::enter(Beekeeper *)
{
}

void BeekeeperSearchPillState::execute(Beekeeper * beekeeper, double deltaTime)
{
	beekeeper->getWorld()->getPill()->reSpawn();
	if (beekeeper->getCurrentVertex() == beekeeper->getWorld()->getPill()->getLocation()) {
		beekeeper->getWorld()->getPill()->eatPill();
		beekeeper->getWorld()->upScore(beekeeper->nrCaughtBees());
		beekeeper->resetAmountOfBees();
		beekeeper->setCatching(true);
		beekeeper->setCurrentState("RTB");
		std::shared_ptr<BeekeeperUpgradedState> nextState = std::make_shared<BeekeeperUpgradedState>();
		beekeeper->getStateMachine()->changeState(nextState);
	}
	else {
		beekeeper->checkVertex(beekeeper->getWorld()->getPill()->getLocation());
		Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
		Vector2D influence = seperation;

		beekeeper->move(influence, deltaTime);

	}
}

std::string BeekeeperSearchPillState::name() {
	return "";
}

void BeekeeperSearchPillState::exit(Beekeeper *)
{
}

void BeekeeperUpgradedState::enter(Beekeeper *)
{
}

void BeekeeperUpgradedState::execute(Beekeeper * beekeeper, double deltaTime)
{
	beekeeper->setMaxAmountBees(30); 
	if (beekeeper->nrCaughtBees() >= beekeeper->getMaxAmountBees() || beekeeper->getWorld()->getBees().size() == 0) {
		beekeeper->setCatching(false);
		beekeeper->setMaxAmountBees(10);
		beekeeper->setCurrentState("RTB");
		std::shared_ptr<BeekeeperReturnToBaseState> nextState = std::make_shared<BeekeeperReturnToBaseState>();
		beekeeper->getStateMachine()->changeState(nextState);
	}
	else {
		if (!beekeeper->isCatching())
			beekeeper->setCatching(true);
	}
	beekeeper->checkVertex(beekeeper->getBeesLocation());
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime*3);
}

std::string BeekeeperUpgradedState::name() {
	return "Upgraded";
}

void BeekeeperUpgradedState::exit(Beekeeper *)
{
}

