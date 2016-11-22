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
		Location(std::string locationName, std::string file, int locationID, int next1, int next2, int next3);
		~Location();

		
		std::string getName();
		std::string getFileName();
		Location * getPrevious();
		Location * getNext();
		int getLocationID();

		void setLocationID(int ID);
		void setName(std::string name);
		void setFileName(std::string name);
		void setPrevious(Location *prev);
		void setNext(Location *next);

		void setLocation1(int locationNum);
		void setLocation2(int locationNum);
		void setLocation3(int locationNum);

		int getLocation1();
		int getLocation2();
		int getLocation3();


		void setup();

		void setEnemies();
		void addToObstacles(RectangleShape& rectanlgeToAdd);
		void setObstacles();

		std::vector<RectangleShape>& getObstacles();
		

	private:
		std::vector<RectangleShape> obstacles;
		std::string name;
		std::string fileName;
		int locationID;
		int nextLocation1;
		int nextLocation2;
		int nextLocation3;
		

		Location *nextLocation;
		Location *previousLocation;

	

		
};
#endif // !LOCATION_H

