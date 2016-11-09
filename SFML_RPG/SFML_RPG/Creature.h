#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include "Location.h"

class Creature : public Entity 
{
	public:
		Creature(std::string creatureName, std::string file);
		~Creature();

		void setHealth(int h);
		void setLevel(int l);
		void setName(std::string name);
		void setSpeed(double s);
		void setDirection(int d);
		void setWalkingCounter(int w);

		int getHealth();
		int getLevel();
		std::string getName();
		double getSpeed();
		int getDirection();
		int getWalkingCounter();

		void setCurrentLocation(Location l);
		Location &getCurrentLocation();

		void setCurrentPosition(Vector2f p);
		Vector2f &getCurrentPosition();

		
		void drawCreature(RenderWindow &window);

	private:
		int health;
		double speed;
		int level;
		int direction;
		int walkingCounter;
		std::string name;

		Location currentLocation;
		Vector2f currentPosition;

};
	

#endif // !CREATURE_H
