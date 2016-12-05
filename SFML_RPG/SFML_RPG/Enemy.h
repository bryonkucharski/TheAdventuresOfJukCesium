#ifndef ENEMY_H
#define ENEMY_H

#include "Creature.h"
#include <string>

class Enemy : public Creature {
	public:
		Enemy(std::string file, std::string name, int location, int AI_ID, int health, int level, Vector2f startingPosition, std::vector<RectangleShape> &obstacles);
		~Enemy();
		void updateEnemy(Vector2f playerPos);
		bool isAlive();
		void setAlive(bool a);
		void onPlayerBulletIntersect(int damage);
		int dropExp();

	private:
		bool alive;
		Clock directionClock;
		Time directionTime;
};
#endif // !ENEMY_H
