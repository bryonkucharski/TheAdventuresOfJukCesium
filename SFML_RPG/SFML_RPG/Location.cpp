#include "Location.h"

Location::Location(){
	//nothing
}
Location::Location(std::string locationName, std::string file, int locationID, int next1, int next2, int next3) {
	
	this->setFileName(file);
	this->setName(locationName);
	this->getTexture().loadFromFile(fileName);
	this->getSprite().setTexture(this->getTexture());
	this->getSprite().setPosition(Vector2f(0, 0));

	this->setLocationID(locationID);
	this->setLocation1(next1);
	this->setLocation2(next2);
	this->setLocation3(next3);
		
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






void Location::setLocation1(int locationNum) {
	//This will change your map location to what is left of the object.

}
void Location::setLocation2(int locationNum) {
	//This will change your map location to what is right of the object.
}
void Location::setLocation3(int locationNum) {
	//This will change your map location to what is down of the object.
}

int Location::getLocation1() {
	return nextLocation1;
}
int Location::getLocation2() {
	return nextLocation2;
}
int Location::getLocation3() {
	return nextLocation3;
}