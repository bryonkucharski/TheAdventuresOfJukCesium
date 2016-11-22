#include "Creature.h"

Creature::Creature(std::string creatureName, std::string file) {
	
	this->setName(creatureName);
	this->getTexture().loadFromFile(file);
	this->getSprite().setTexture(this->getTexture());
}
Creature::~Creature() {

}
//setters
void Creature::setHealth(int h) {
	this->health = h;
}
void Creature::setLevel(int l) {
	this->level = l;
}
void Creature::setName(std::string name) {
	this->name = name;
}
void Creature::setSpeed(double s) {
	this->speed = s;
}
void Creature::setDirection(int d) {
	this->direction = d;
}
void Creature::setWalkingCounter(int w) {
	this->walkingCounter = w;
}
void Creature::setCanWalkUp(bool up) {
	this->canWalkUp = up;
}
void Creature::setCanWalkDown(bool down) {
	this->canWalkDown = down;
}
void Creature::setCanWalkLeft(bool left) {
	this->canWalkLeft = left;
}
void Creature::setCanWalkRight(bool right) {
	this->canWalkRight = right;
}

//getters
int Creature::getHealth() {
	return health;
}
int Creature::getLevel() {
	return level;
}
std::string Creature::getName() {
	return name;
}
double Creature::getSpeed() {
	return speed;
}
int Creature::getDirection() {
	return direction;
}
int Creature::getWalkingCounter() {
	return walkingCounter;
}
bool Creature::isWalkUpAllowed() {
	return this->canWalkUp;
}
bool Creature::isWalkDownAllowed() {
	return this->canWalkDown;
}
bool Creature::isWalkLeftAllowed() {
	return this->canWalkLeft;
}
bool Creature::isWalkRightAllowed() {
	return this->canWalkRight;
}

void Creature::drawCreature(RenderWindow &window) {
	window.draw(this->getSprite());
}
void Creature::setCurrentLocation(int l) {
	this->currentLocation = l;
}
int Creature::getCurrentLocation() {
	return currentLocation;
}
void Creature::setCurrentPosition(Vector2f p) {
	this->currentPosition = p;
}
Vector2f& Creature::getCurrentPosition() {
	return currentPosition;
}
bool Creature::checkForIntersect(std::vector<RectangleShape> &obs, RectangleShape &rect) {

	//iterate through obstacles in current location and check for intersect 
	int counter = 0;
	for (std::vector<RectangleShape>::iterator obsIter = obs.begin(); obsIter != obs.end(); ++obsIter)
	{
		if (rect.getGlobalBounds().intersects(obs[counter].getGlobalBounds())) {
			return true;
		}
		counter++;
	}
	return false;

}
void Creature::setAllWalk(bool val) {
	this->setCanWalkUp(val);
	this->setCanWalkDown(val);
	this->setCanWalkLeft(val);
	this->setCanWalkRight(val);
}
