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
		Location(std::string locationName, std::string file);
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

		Location *nextLocation;
		Location *previousLocation;

	

		
};
#endif // !LOCATION_H

