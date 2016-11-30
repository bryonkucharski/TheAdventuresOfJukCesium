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
	private:
		bool alive;
};
#endif // !ENEMY_H
