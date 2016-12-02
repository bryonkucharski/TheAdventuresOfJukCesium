#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"


class Creature : public Entity 
{
	public:
		Creature(std::string creatureName, std::string file);
		~Creature();

		void setCurrentHealth(int h);
		void setMaxHealth(int maxH);
		void setDamage(int d);
		void setLevel(int l);
		void setTotalExperience(int xp);
		void setName(std::string name);
		void setSpeed(float s);
		void setDirection(int d);

		void setWalkingCounter(int w);
		void setwalkingCounterDirection(int w);

		void setCanWalkUp(bool up);
		void setCanWalkDown(bool down);
		void setCanWalkLeft(bool left);
		void setCanWalkRight(bool right);

		int getCurrentHealth();
		int getMaxHealth();
		int getDamage();
		int getLevel();
		int getTotalExperience();
		std::string getName();
		double getSpeed();
		int getDirection();
		int getWalkingCounter();
		int getwalkingCounterDirection();

		bool isWalkUpAllowed();
		bool isWalkDownAllowed();
		bool isWalkLeftAllowed();
		bool isWalkRightAllowed();

	

		void setCurrentLocation(int l);
		int getCurrentLocation();

		void setCurrentPosition(Vector2f p);
		Vector2f &getCurrentPosition();

		
		void drawCreature(RenderWindow &window);

	private:
		int damage;
		int currentHealth;
		int maxHealth;
		float speed;
		int level;
		int totalExperience;
		int direction; // left is 1, right is 2, up is 3, down is 4
		int walkingCounter;
		int walkingCounterDirection;
		std::string name;

		bool canWalkUp;
		bool canWalkDown;
		bool canWalkLeft;
		bool canWalkRight;

		
		int currentLocation;
		Vector2f currentPosition;
	protected:
		bool checkForIntersect(std::vector<RectangleShape> &obs, RectangleShape &rect);
		//bool checkForEnemyIntersect(std::vector<Enemy*> enemies, RectangleShape &rect);
		void updateAnimationCounter();
		void setAllWalk(bool val);
	

		Clock animationClock;
		Time animationTime;
		float animationCounter;

};
	

#endif // !CREATURE_H
