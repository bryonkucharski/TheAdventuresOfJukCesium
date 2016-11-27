#include "Creature.h"

Creature::Creature(std::string creatureName, std::string file) {
	
	this->setName(creatureName);
	this->texture.loadFromFile(file);
	this->sprite.setTexture(this->texture);
}
Creature::~Creature() {

}
//setters
void Creature::setCurrentHealth(int h) {
	this->currentHealth = h;
}
void::Creature::setDamage(int d) {
	this->damage = d;
}
void Creature::setLevel(int l) {
	this->level = l;
}
void Creature::setTotalExperience(int xp) {
	this->totalExperience = xp;
}
void Creature::setMaxHealth(int maxH) {
	this->maxHealth = maxH;
}
void Creature::setName(std::string name) {
	this->name = name;
}
void Creature::setSpeed(float s) {
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
int Creature::getCurrentHealth() {
	return currentHealth;
}
int Creature::getMaxHealth() {
	return maxHealth;
}
int Creature::getDamage() {
	return damage;
}
int Creature::getLevel() {
	return level;
}
int Creature::getTotalExperience() {
	return totalExperience;
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
	window.draw(this->sprite);
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
