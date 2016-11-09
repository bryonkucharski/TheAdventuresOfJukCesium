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
			this->setDirection(4);
			this->setSpeed(5);
			this->setCurrentLocation(world.getHome());
			this->getRect().setSize(Vector2f(32, 32));
			this->getSprite().setPosition(Vector2f(0, 0));
			this->setCanWalk(true);
		}
		~Player();
		void updatePlayer(RenderWindow &window);
	private:
};
#endif // !PLAYER_H
