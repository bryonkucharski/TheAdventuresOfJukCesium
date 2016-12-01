#ifndef ENEMY_H
#define ENEMY_H

#include "Creature.h"
#include <string>

class Enemy : public Creature {
	public:
		Enemy(std::string file, std::string name, int health, int level);
		~Enemy();
		void updateEnemy(RenderWindow &window);
		bool isAlive();
		void setAlive(bool a);
		void drawText(RenderWindow &window);
	private:
		
		void setRandomDirection();
		bool alive;
		Clock directionClock;
		Time directionTime;

};
#endif // !ENEMY_H
