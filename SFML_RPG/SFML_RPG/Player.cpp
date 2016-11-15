#include "Player.h"

Player::~Player() {

}
//handles player movements. called every frame in main.
void Player::updatePlayer(RenderWindow &window) {

	//implement spriting by holding shift, MH
	int speedMod = 0;
	if (Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RControl)) {
		speedMod = 5;
	}

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

	//added WASD support MH
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
	{
		this->setDirection(1);
		//Fixed all the walking animations, MH
		this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));
		this->setCanWalkLeft(!this->checkForIntersect(obstacles, this->getRect()));

		if (this->isWalkLeftAllowed()) {
			//if you are not on an obstacle, you can walk.
			this->getRect().move(-this->getSpeed() - speedMod, 0);
		}
		else {
			//attempting to fix collison that makes you stuck.
			//this is technically saying if you are in an obstacle, walk backwards.
			//How can we say, never enter an obstacle
			//We have to tweak how intersects work then.
			//of if we have interected, setPosition(previous, previous)
			this->getRect().move(this->getSpeed() + speedMod + 2, 0);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
	{
		this->setDirection(2);
		this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 32*2, 32, 32));
		this->setCanWalkRight(!this->checkForIntersect(obstacles, this->getRect()));

		//only move player if allowed to walk (no intersect)
		if (this->isWalkRightAllowed()) {
			this->getRect().move(this->getSpeed() + speedMod, 0);
		}else {
			this->getRect().move(-this->getSpeed() - speedMod - 2, 0);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		this->setDirection(3);
		this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 96, 32, 32));
		this->setCanWalkUp(!this->checkForIntersect(obstacles, this->getRect()));
			
		//only move player if allowed to walk (no intersect)
		if (this->isWalkUpAllowed()) {
			this->getRect().move(0, -this->getSpeed() - speedMod);
		}else {
			this->getRect().move(0, this->getSpeed() + speedMod + 2);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		this->setDirection(4);
		this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 0, 32, 32));
		this->setCanWalkDown(!this->checkForIntersect(obstacles, this->getRect()));

		if (this->isWalkDownAllowed()) {
			this->getRect().move(0, this->getSpeed() + speedMod);
		}else {
			//this->getRect().setPosition(/*The last X position before intersection*/ , /*The last Y position before intersection - speedMod - 2*/ )
			this->getRect().move(0, -this->getSpeed() - speedMod - 2);
		}
	}

	if (this->getWalkingCounter() == 2){
		setWalkingCounter(0);
	}

	//draw create to the screen
	this->drawCreature(window);
}