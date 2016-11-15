#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "World.h"

class Player : public Creature
{
	public:
		Player(std::string playerName, std::string file, World &world) : Creature(playerName, file)
		{
			this->getSprite().setTextureRect(IntRect(0, 0, 32, 32));
			this->setWalkingCounter(0);
			this->animationCounter = .05;
			this->setDirection(4);
			this->setSpeed(3);
			this->setCurrentLocation(world.getHome());
			this->getRect().setSize(Vector2f(32, 32));
			this->getSprite().setPosition(Vector2f(0, 0));
			this->setAllWalk(true);
		}
		~Player();
		void updatePlayer(RenderWindow &window);
	private:
		int running = 5;
		int walking = 2;
};
#endif // !PLAYER_H
