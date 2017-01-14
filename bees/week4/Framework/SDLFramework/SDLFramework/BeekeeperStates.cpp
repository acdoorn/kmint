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
		int random = rand() % 99 + 1; //																random int in range 1 to 99;

		if (random <= returnToBaseChance) //																BeekeeperReturnToBaseState
		{
			beekeeper->setCatching(false);
			std::shared_ptr<BeekeeperReturnToBaseState> nextState = std::make_shared<BeekeeperReturnToBaseState>();
			beekeeper->getStateMachine()->changeState(nextState);
		}
		else if (random > returnToBaseChance && random <= (searchPillChance+returnToBaseChance)) { //		BeekeeperSearchPillState
			beekeeper->setCatching(false);
			std::shared_ptr<BeekeeperSearchPillState> nextState = std::make_shared<BeekeeperSearchPillState>();
			beekeeper->getStateMachine()->changeState(nextState);
		}
		else if (random > (returnToBaseChance + searchPillChance)) //										BeekeeperPanicState
		{
			beekeeper->setCatching(false);
			std::shared_ptr<BeekeeperPanicState> nextState = std::make_shared<BeekeeperPanicState>();
			beekeeper->getStateMachine()->changeState(nextState);
		}

	}
	else {
		if (!beekeeper->isCatching())
			beekeeper->setCatching(true);
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
			//state omhoog
		}
		else {
			//state omlaag
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

