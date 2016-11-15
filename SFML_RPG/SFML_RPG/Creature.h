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

		void setCanWalkUp(bool up);
		void setCanWalkDown(bool down);
		void setCanWalkLeft(bool left);
		void setCanWalkRight(bool right);

		int getHealth();
		int getLevel();
		std::string getName();
		double getSpeed();
		int getDirection();
		int getWalkingCounter();

		bool isWalkUpAllowed();
		bool isWalkDownAllowed();
		bool isWalkLeftAllowed();
		bool isWalkRightAllowed();

	

		void setCurrentLocation(Location l);
		Location &getCurrentLocation();

		void setCurrentPosition(Vector2f p);
		Vector2f &getCurrentPosition();

		
		void drawCreature(RenderWindow &window);

	private:
		int health;
		float speed;
		int level;
		int direction;
		int walkingCounter;
		std::string name;

		bool canWalkUp;
		bool canWalkDown;
		bool canWalkLeft;
		bool canWalkRight;

		
		Location currentLocation;
		Vector2f currentPosition;
	protected:
		bool checkForIntersect(std::vector<RectangleShape> &obs, RectangleShape &rect);
		void setAllWalk(bool val);

		Clock animationClock;
		Time animationTime;
		float animationCounter;

};
	

#endif // !CREATURE_H
