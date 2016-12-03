#ifndef ENEMY_H
#define ENEMY_H

#include "Creature.h"
#include <string>

class Enemy : public Creature {
	public:
		Enemy::Enemy(std::string file, std::string name, int location, int health, int level, Vector2f startingPosition, std::vector<RectangleShape> &obstacles);
		~Enemy();
		void updateEnemy(RenderWindow &window);
		bool isAlive();
		void setAlive(bool a);
		void drawText(RenderWindow &window);
	private:
		std::vector<RectangleShape> currentObstacles;
		void setRandomDirection();
		bool alive;
		Clock directionClock;
		Time directionTime;

};
#endif // !ENEMY_H
