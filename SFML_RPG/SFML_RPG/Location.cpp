#include "Location.h"

Location::Location(){
	//nothing
}
Location::Location(std::string locationName, std::string file) {
	
	this->setFileName(file);
	this->setName(locationName);
}
void Location::setup() {
	this->getTexture().loadFromFile(fileName);
	this->getSprite().setTexture(this->getTexture());
	this->getSprite().setPosition(Vector2f(0, 0));
}
Location::~Location() {}

std::string Location::getName() {
	return name;
}
std::string Location::getFileName() {
	return fileName;
}
Location* Location::getPrevious() {
	return previousLocation;
}
Location * Location::getNext() {
	return nextLocation;
}
int Location::getLocationID() {
	return locationID;
}
void Location::setFileName(std::string name) {
	this->fileName = name;
}
void Location::setLocationID(int ID) {
	this->locationID = ID;
}
void Location::setName(std::string name) {
	this->name = name;
}
void Location::setPrevious(Location *prev) {
	this->previousLocation = prev;
}
void Location::setNext(Location *next) {
	this->nextLocation = next;
}

void Location::setEnemies() {

}
void Location::addToObstacles(RectangleShape &rectanlgeToAdd) {
	obstacles.push_back(rectanlgeToAdd);
}
std::vector<RectangleShape>& Location::getObstacles() {
	return obstacles;
}