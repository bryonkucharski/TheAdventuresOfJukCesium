#include "Creature.h"

Creature::Creature(std::string creatureName, std::string file) {
	
	this->setName(creatureName);
	this->getTexture().loadFromFile(file);
	this->getSprite().setTexture(this->getTexture());
}
Creature::~Creature() {

}

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
void Creature::drawCreature(RenderWindow &window) {
	window.draw(this->getSprite());
}
void Creature::setCurrentLocation(Location l) {
	this->currentLocation = l;
}
Location& Creature::getCurrentLocation() {
	return currentLocation;
}
void Creature::setCurrentPosition(Vector2f p) {
	this->currentPosition = p;
}
Vector2f& Creature::getCurrentPosition() {
	return currentPosition;
}
