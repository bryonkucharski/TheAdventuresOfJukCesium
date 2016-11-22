#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>

#include "Entity.h"
#include "Obstacle.h"


class Location : public Entity
{
public:
	Location();
	Location(std::string locationName, std::string file, int locationID, int next1, int next2, int next3, Vector2f nextPos1, Vector2f nextPos2, Vector2f nextPos3);
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

	int getLocation1();
	int getLocation2();
	int getLocation3();

	Vector2f getNext1Position();
	Vector2f getNext2Position();
	Vector2f getNext3Position();

	void setNext1Position(Vector2f pos);
	void setNext2Position(Vector2f pos);
	void setNext3Position(Vector2f pos);


	void setup();

	void setEnemies();
	void addToObstacles(RectangleShape& rectanlgeToAdd);
	void addToLocationChanges(RectangleShape& rectanlgeToAdd);

	std::vector<RectangleShape>& getObstacles();
	std::vector<RectangleShape>& getLocationChanges();


private:
	std::vector<RectangleShape> obstacles;
	std::vector<RectangleShape> locationChanges;
	std::string name;
	std::string fileName;

	int locationID;

	int nextLocation1;
	Vector2f next1Position;
	int nextLocation2;
	Vector2f next2Position;
	int nextLocation3;
	Vector2f next3Position;
};
#endif // !LOCATION_H

