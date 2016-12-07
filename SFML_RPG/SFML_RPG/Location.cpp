#include "Location.h"

Location::Location() {
	//nothing
}
Location::Location(std::string locationName, std::string file, bool hasEnemies, int locationID, int next1, int next2, int next3, int next4, Vector2f nextPos1, Vector2f nextPos2, Vector2f nextPos3, Vector2f nextPos4) {

	this->setFileName(file);
	this->setName(locationName);
	this->texture.loadFromFile(fileName);
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(Vector2f(0, 0));//this is setting the player to the 0, 0 area.

	this->setLocationID(locationID);

	this->setHasEnemies(hasEnemies);

	this->setLocation1(next1);
	this->setLocation2(next2);
	this->setLocation3(next3);
	this->setLocation4(next4);

	this->setNext1Position(nextPos1);
	this->setNext2Position(nextPos2);
	this->setNext3Position(nextPos3);
	this->setNext4Position(nextPos4);

}
Location::~Location() {
	//what if we moved the deleted enemies to a death vector for a location.
	//they can respawn after time by moving back to the original vector.
}

//Getting the current locaitons needed information
std::string Location::getName() {
	return name;
}
std::string Location::getFileName() {
	return fileName;
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
void Location::setEnemies() {

}
void Location::addToObstacles(RectangleShape &rectanlgeToAdd) {
	obstacles.push_back(rectanlgeToAdd);
}
std::vector<RectangleShape>& Location::getObstacles() {
	return obstacles;
}

//Setting the current locations next possible location
void Location::setLocation1(int locationNum) {
	this->nextLocation1 = locationNum;
}
void Location::setLocation2(int locationNum) {
	this->nextLocation2 = locationNum;
}
void Location::setLocation3(int locationNum) {
	this->nextLocation3 = locationNum;
}
void Location::setLocation4(int locationNum) {
	this->nextLocation2;
}

//getters
int Location::getLocation1() {
	return nextLocation1;
}
int Location::getLocation2() {
	return nextLocation2;
}
int Location::getLocation3() {
	return nextLocation3;
}
int Location::getLocation4() {
	return nextLocation4;
}
Vector2f Location::getNext1Position() {
	return next1Position;
}
Vector2f Location::getNext2Position() {
	return next2Position;
}
Vector2f Location::getNext3Position() {
	return next3Position;
}
Vector2f Location::getNext4Position() {
	return next4Position;
}
void Location::setNext1Position(Vector2f pos) {
	this->next1Position = pos;
}
void Location::setNext2Position(Vector2f pos) {
	this->next2Position = pos;
}
void Location::setNext3Position(Vector2f pos) {
	this->next3Position = pos;
}
void Location::setNext4Position(Vector2f pos) {
	this->next4Position = pos;
}

//Location Changes
void Location::addToLocationChanges(RectangleShape& rectanlgeToAdd) {
	this->locationChanges.push_back(rectanlgeToAdd);
}
std::vector<RectangleShape>& Location::getLocationChanges() {
	return locationChanges;
}

//Enemies
void Location::addToEnemies(Enemy * enemyToAdd) {
	this->enemies.push_back(enemyToAdd);
}
std::vector<Enemy*> Location::getEnemies() {
	return enemies;
}
void Location::removeEnemies() {
	/*Using a "Remove-Erase Idiom  https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
	Used http://stackoverflow.com/questions/22729906/stdremove-if-not-working-properly for help writing a lambda function
	*/
	enemies.erase(std::remove_if(enemies.begin(), enemies.end(), [](Enemy *e) { return !e->isAlive(); }), enemies.end());
}

//NPCs
void Location::addToNPCs(NPC *NPCToAdd) {
	this->NPCs.push_back(NPCToAdd);
}
std::vector<NPC*> Location::getNPCs() {
	return NPCs;
}

void Location::setHasEnemies(bool h) {
	this->enemiesInLocation = h;
}
bool Location::hasEnemies() {
	return enemiesInLocation;
}
