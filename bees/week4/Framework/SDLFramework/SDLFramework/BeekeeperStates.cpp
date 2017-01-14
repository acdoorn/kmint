#include "BeekeeperStates.h"
#include "Beekeeper.h"
#include "Graph.h"
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
	if (beekeeper->nrCaughtBees() == beekeeper->getMaxAmountBees()) {
		//int random = rand() % 99 + 1; //																random int in range 1 to 99;

		//if (random <= beekeeper->getReturnToBaseChance()) //																BeekeeperReturnToBaseState
		//{
		//	beekeeper->setCatching(false);
		//	std::shared_ptr<BeekeeperReturnToBaseState> nextState = std::make_shared<BeekeeperReturnToBaseState>();
		//	beekeeper->getStateMachine()->changeState(nextState);
		//}
		//else if (random > beekeeper->getReturnToBaseChance() && random <= (beekeeper->getSearchPillChance()+ beekeeper->getReturnToBaseChance())) { //		BeekeeperSearchPillState
		//	beekeeper->setCatching(false);
		//	std::shared_ptr<BeekeeperSearchPillState> nextState = std::make_shared<BeekeeperSearchPillState>();
		//	beekeeper->getStateMachine()->changeState(nextState);
		//}
		//else if (random > (beekeeper->getReturnToBaseChance() + beekeeper->getSearchPillChance())) //										BeekeeperPanicState
		//{
		//	beekeeper->setCatching(false);
		//	std::shared_ptr<BeekeeperPanicState> nextState = std::make_shared<BeekeeperPanicState>();
		//	beekeeper->getStateMachine()->changeState(nextState);
		//}

		beekeeper->setCatching(false);
		std::shared_ptr<BeekeeperReturnToBaseState> nextState = std::make_shared<BeekeeperReturnToBaseState>();
		beekeeper->getStateMachine()->changeState(nextState);
	}
	else {
		if (!beekeeper->isCatching())
			beekeeper->setCatching(true);
	}
	if (beekeeper->nrCaughtBees() > beekeeper->getMaxAmountBees()) {
		beekeeper->removeBee();
	}
	beekeeper->checkVertex();
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
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
	beekeeper->checkVertex();
	if (base != beekeeper->getCurrentVertex()) {
		Vertex* next = g->GetNextVertex(beekeeper->getCurrentVertex(), base);
		Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(next->x, next->y));
		Vector2D influence = seperation;

		beekeeper->move(influence, deltaTime);
	}
	else {
		int temp = beekeeper->getWorld()->getScore();
		beekeeper->getWorld()->upScore(beekeeper->nrCaughtBees());
		beekeeper->resetAmountOfBees();
		if (temp < beekeeper->getWorld()->getScore()) {
			if (beekeeper->getStateMachine()->getPreviousState() == std::make_shared<BeekeeperWanderState>()) {// als returntobase direct door wanderstate aangeroepen wordt.
				if (beekeeper->lowerPanicChance()) {
					beekeeper->increaseReturnToBaseChance();
				}
				if (beekeeper->lowerSearchPillChance()) {
					beekeeper->increaseReturnToBaseChance();
				}
			}
			if (beekeeper->getStateMachine()->getPreviousState() == std::make_shared<BeekeeperPanicState>()) {// als de beekeeper in paniek heeft rondgelopen in de vorige state
				if (beekeeper->lowerReturnToBaseChance()) {
					beekeeper->increasePanicChance();
				}
				if (beekeeper->lowerSearchPillChance()) {
					beekeeper->increasePanicChance();
				}
			}
			if (beekeeper->getStateMachine()->getPreviousState() == std::make_shared<BeekeeperUpgradedState>()) {// als de beekeeper geupgrade is door de pill
				if (beekeeper->lowerReturnToBaseChance()) {
					beekeeper->increaseSearchPillChance();
			}
				if (beekeeper->lowerPanicChance()) {
					beekeeper->increaseSearchPillChance();
				}
			}
			//state omhoog
		}
		//up effectivity
		std::shared_ptr<BeekeeperWanderState> nextState = std::make_shared<BeekeeperWanderState>();
		beekeeper->getStateMachine()->changeState(nextState);
	}

}

void BeekeeperReturnToBaseState::exit(Beekeeper *)
{
}

void BeekeeperPanicState::enter(Beekeeper *)
{
}

void BeekeeperPanicState::execute(Beekeeper * beekeeper, double deltaTime)
{
	//TODO
	beekeeper->checkVertex();
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
}

void BeekeeperPanicState::exit(Beekeeper *)
{
}

void BeekeeperSearchPillState::enter(Beekeeper *)
{
}

void BeekeeperSearchPillState::execute(Beekeeper * beekeeper, double deltaTime)
{
	//TODO
	beekeeper->checkVertex();
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
}

void BeekeeperSearchPillState::exit(Beekeeper *)
{
}

void BeekeeperUpgradedState::enter(Beekeeper *)
{
}

void BeekeeperUpgradedState::execute(Beekeeper * beekeeper, double deltaTime)
{
	//TODO
	beekeeper->checkVertex();
	Vector2D seperation = beekeeper->getSteeringBehaviour()->seek(Vector2D(beekeeper->getNextVertex()->x, beekeeper->getNextVertex()->y));
	Vector2D influence = seperation;

	beekeeper->move(influence, deltaTime);
}

void BeekeeperUpgradedState::exit(Beekeeper *)
{
}

