#ifndef ENEMY_H
#define ENEMY_H
#include <SFML/Audio.hpp>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>
#include <stdio.h>
#include <math.h>
#include "Creature.h"

class Enemy : public Creature {
	public:
		Enemy(std::string file, std::string name, int location, int AI_ID, int aiShoot, int health, int level, Vector2f startingPosition, std::vector<RectangleShape> &obstacles);
		Enemy(std::string file, std::string name, int location, int AI_ID, int aiShoot, int health, int level, Vector2f startingPosition, std::vector<RectangleShape> &obstacles, Vector2f pixelSize);
		~Enemy();
		void updateEnemy(Vector2f playerPos);
		bool isAlive();
		void setAlive(bool a);
		void shootPlayer(Vector2f playerPos);
		void onPlayerBulletIntersect(int damage);
		int dropExp();

		void selectShootAI(int aiShoot, Vector2f playerPos);
		void setShootAI(int aiShoot);
		int getShootAI();

		void shootAI1(Vector2f playerPos);
		void shootAI2(Vector2f playerPos);
		void shootAI3(Vector2f playerPos);
		void shootAI4(Vector2f playerPos);
		void shootAI5(Vector2f playerPos);

	private:
		bool alive, clockCheck;
		Clock directionClock, bossClock;
		Time directionTime, bossTime;
		
		int shootAI, bossTemp;

		//sounds
		SoundBuffer bOnDeath;//buffer for on death.
		SoundBuffer bOnHit;//buffer for on hit.
		Sound soundOnDeath;
		Sound soundOnHit;
};
#endif // !ENEMY_H
