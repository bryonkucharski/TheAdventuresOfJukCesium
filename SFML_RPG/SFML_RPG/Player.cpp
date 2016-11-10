#include "Player.h"

Player::~Player() {

}
//handles player movements. called every frame in main.
void Player::updatePlayer(RenderWindow &window) {

	//allow player to walk at the start of every frame. 
	this->setAllWalk(true);

	//map the player's sprite to the player's rect
	this->getSprite().setPosition(this->getRect().getPosition());

	//get the current x and y of the player every frame
	this->setCurrentPosition(this->getRect().getPosition());

	//holds all rectangles that the player is not allowed to insersect with
	std::vector<RectangleShape> obstacles = this->getCurrentLocation().getObstacles();

	//increment walking counter for animation 
	this->setWalkingCounter(this->getWalkingCounter() + 1);

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		this->setDirection(1);
		this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 96, 32, 32));
		this->setCanWalkLeft(!this->checkForIntersect(obstacles, this->getRect()));

		if (this->isWalkLeftAllowed()) {
			this->getRect().move(-this->getSpeed(), 0);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		this->setDirection(2);
		this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));
		this->setCanWalkRight(!this->checkForIntersect(obstacles, this->getRect()));

		//only move player if allowed to walk (no intersect)
		if (this->isWalkRightAllowed()) {
			this->getRect().move(this->getSpeed(), 0);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		this->setDirection(3);
		this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 64, 32, 32));
		this->setCanWalkUp(!this->checkForIntersect(obstacles, this->getRect()));
			
		//only move player if allowed to walk (no intersect)
		if (this->isWalkUpAllowed()) {
			this->getRect().move(0, -this->getSpeed());
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		this->setDirection(4);
		this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 0, 32, 32));
		this->setCanWalkDown(!this->checkForIntersect(obstacles, this->getRect()));

		if (this->isWalkDownAllowed()) {
			this->getRect().move(0, this->getSpeed());
		}
	}

	if (this->getWalkingCounter() == 2){
		setWalkingCounter(0);
	}

	//draw create to the screen
	this->drawCreature(window);
}