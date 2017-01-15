#include "Beekeeper.h"
#include "BeekeeperStates.h"
#include <string> 

Beekeeper::Beekeeper(double x, double y, int width, int height, double mass, double maxSpeed, double maxForce, double maxTurnRate, GameWorld* world) :
	Vehicle(x, y, width, height, mass, maxSpeed, maxForce, maxTurnRate, world), m_catchDistance(80)
{
	currentVertex = getWorld()->getGraph()->vertices.at(getWorld()->getGraph()->vertices.size() - 63);
	panicVertex = getWorld()->getGraph()->vertices.at(getWorld()->getGraph()->vertices.size() - (rand() % 70 + 1));
	m_position.setX(currentVertex->x);
	m_position.setY(currentVertex->y);
	m_stateMachine = std::make_shared<StateMachine<Beekeeper>>(this);
	statestring = "Chase bees";
	std::shared_ptr<BeekeeperWanderState> initialState = std::make_shared<BeekeeperWanderState>();
	m_stateMachine->setCurrentState(initialState);
	m_texture = FWApplication::GetInstance()->LoadTexture("../Resources/beekeeper.png");
	//m_netTexture = FWApplication::GetInstance()->LoadTexture("../Resources/net.png");
	m_areaTexture = FWApplication::GetInstance()->LoadTexture("../Resources/catcharea.png");
	color = Color(255, 10, 40, 255);
}

std::shared_ptr<StateMachine<Beekeeper>> Beekeeper::getStateMachine()
{
	return m_stateMachine;
}

Vertex* Beekeeper::getNextVertex() {
	return nextVertex;
}

Vertex* Beekeeper::getBeesLocation() {
	Vertex* targetVertex = getCurrentVertex();

	if (getWorld()->getBees().size() > 0) {
		std::shared_ptr<MovingEntity> closestBee;
		double closestDistance = 800;
		int totalBees = getWorld()->getBees().size();
		Vector2D destination = Vector2D(0, 0);
		for (auto &value : getWorld()->getBees())
		{
			if (getPosition().distanceTo(value->getPosition()) < closestDistance)
			{
				closestBee = value;
				closestDistance = getPosition().distanceTo(value->getPosition());
			}
			destination += value->getPosition();
		}
		destination = destination / totalBees;
		closestDistance = 900;

		if (closestBee == nullptr)
		{
			targetVertex = getWorld()->getGraph()->GetRandomVertixNot(getCurrentVertex());
		}

		//verwisselen met destination om de gemiddelde positie van de bijen te gebruiken.
		for (auto* value : getWorld()->getGraph()->vertices)
		{
			if (closestBee->getPosition().distanceTo(Vector2D(value->x, value->y)) < closestDistance)
			{
				targetVertex = value;
				closestDistance = closestBee->getPosition().distanceTo(Vector2D(value->x, value->y));
			}
		}
	}
	return targetVertex;

}

void Beekeeper::checkVertex(Vertex* target) {
	nextVertex = getWorld()->getGraph()->GetNextVertex(currentVertex, target);
	double diffX = getPosition().getX() - nextVertex->x;
	double diffY = getPosition().getY() - nextVertex->y;
	if ((-5 <= diffX && diffX <= 5) && (-5 <= diffY && diffY <= 5)) {
		currentVertex = nextVertex;
	}
}

void Beekeeper::update(double deltaTime)
{
	m_stateMachine->update(deltaTime);
	m_catchDistance += deltaTime * 0.4;
}

double Beekeeper::getCatchDistance()
{
	return m_catchDistance;
}

Vertex* Beekeeper::getCurrentVertex()
{
	return currentVertex;
}

void Beekeeper::draw()
{
	if (m_texture)
	{
		int x = m_position.getX();
		int y = m_position.getY();


		FWApplication::GetInstance()->DrawTexture(m_areaTexture, x, y, m_catchDistance * 2, m_catchDistance * 2, getAngle(), getDirection());
		//FWApplication::GetInstance()->DrawTexture(m_netTexture, x, y, m_catchDistance *2, m_catchDistance * 2, getAngle(), getDirection());


		FWApplication::GetInstance()->DrawTexture(m_texture, x, y, m_width, m_height, 270, 0);
		FWApplication::GetInstance()->SetColor(color);

		FWApplication::GetInstance()->DrawText("Distance : " + std::to_string(m_catchDistance), 100, 5);
		FWApplication::GetInstance()->DrawText("Score : " + std::to_string(getWorld()->getScore()), 100, 17);
		FWApplication::GetInstance()->DrawText("Amount of bees in bag : " + std::to_string(nrCaughtBees()), 100, 41);
		FWApplication::GetInstance()->DrawText("RTB chance : " + std::to_string(getReturnToBaseChance()), 100, 53);
		FWApplication::GetInstance()->DrawText("Panic chance : " + std::to_string(getPanicChance()), 100, 65);
		FWApplication::GetInstance()->DrawText("Pill chance : " + std::to_string(getSearchPillChance()), 100, 77);
		FWApplication::GetInstance()->DrawText("Current state : " + getCurrentState(), 100, 89);



	}
}

bool Beekeeper::isCatching() {
	return catching;
}

void Beekeeper::setCatching(bool c) {
	catching = c;
}

int Beekeeper::getMaxAmountBees() {
	return maxAmountBees;
}

void Beekeeper::setMaxAmountBees(int i) {
	maxAmountBees = i;
}

void Beekeeper::setColor(Color c) {
	color = c;
}

void Beekeeper::addBee() {
	amountOfBees++;
}

int Beekeeper::nrCaughtBees() {
	return amountOfBees;
}

void Beekeeper::removeBee() {
	amountOfBees--;
}

void Beekeeper::resetAmountOfBees() {
	amountOfBees = 0;
}