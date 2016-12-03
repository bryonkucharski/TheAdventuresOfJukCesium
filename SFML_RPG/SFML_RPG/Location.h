#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include <algorithm>

#include "Entity.h"
#include "Enemy.h"
#include "NPC.h"

class Location : public Entity
{
public:
	Location();
	Location(std::string locationName, std::string file, int locationID, int next1, int next2, int next3, int next4, Vector2f nextPos1, Vector2f nextPos2, Vector2f nextPos3, Vector2f nextPos4);
	~Location();


	std::string getName();
	std::string getFileName();

	int getLocationID();
	void setLocationID(int ID);

	void setName(std::string name);
	void setFileName(std::string name);

	void setLocation1(int locationNum);
	void setLocation2(int locationNum);
	void setLocation3(int locationNum);
	void setLocation4(int locationNum);

	int getLocation1();
	int getLocation2();
	int getLocation3();
	int getLocation4();

	Vector2f getNext1Position();
	Vector2f getNext2Position();
	Vector2f getNext3Position();
	Vector2f getNext4Position();

	void setNext1Position(Vector2f pos);
	void setNext2Position(Vector2f pos);
	void setNext3Position(Vector2f pos);
	void setNext4Position(Vector2f pos);

	void setEnemies();
	void addToObstacles(RectangleShape& rectanlgeToAdd);
	void addToLocationChanges(RectangleShape& rectanlgeToAdd);
	void addToEnemies(Enemy *enemyToAdd);
	void addToNPCs(NPC *NPCToAdd);

	std::vector<RectangleShape>& getObstacles();
	std::vector<RectangleShape>& getLocationChanges();
	std::vector<Enemy*> getEnemies();
	std::vector<NPC*> getNPCs();

	/* Removes any enemies from the enemy vector that are not alive */
	void removeEnemies();


private:
	std::vector<RectangleShape> obstacles;
	std::vector<RectangleShape> locationChanges;
	std::vector<Enemy*> enemies;
	std::vector<NPC*> NPCs;
	std::string name;
	std::string fileName;

	int locationID;

	int nextLocation1;
	Vector2f next1Position;
	int nextLocation2;
	Vector2f next2Position;
	int nextLocation3;
	Vector2f next3Position;
	int nextLocation4;
	Vector2f next4Position;
};
#endif // !LOCATION_H

