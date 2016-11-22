#include "Player.h"

Player::Player(std::string playerName, std::string file, World &world) : Creature(playerName, file) {
	this->getSprite().setTextureRect(IntRect(0, 0, 32, 32));
	this->setWalkingCounter(0);
	this->animationCounter = .05;
	this->setDirection(4);
	this->setSpeed(3);
	this->setCurrentLocation(1);
	this->getRect().setSize(Vector2f(28, 28));
	this->getSprite().setPosition(Vector2f(2, 2));
	this->setAllWalk(true);
	this->wrld = world;
}
Player::~Player() {

}
//handles player movements. called every frame in main.
void Player::updatePlayer(RenderWindow &window) {

	//implement spriting by holding shift, MH
	if (Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RControl))
	{
		this->setSpeed(running);
	}
	else
	{
		this->setSpeed(walking);
	}

	//allow player to walk at the start of every frame. 
	this->setAllWalk(true);

	//map the player's sprite to the player's rect
	this->getSprite().setPosition(this->getRect().getPosition());

	//get the current x and y of the player every frame
	this->setCurrentPosition(this->getRect().getPosition());

	//holds all rectangles that the player is not allowed to insersect with
	std::vector<RectangleShape> obstacles = wrld.getLocation(this->getCurrentLocation()).getObstacles();


	//holds all rectangles that will change the players location if intersected with
	std::vector<RectangleShape> changeLocationRects = wrld.getLocation(this->getCurrentLocation()).getLocationChanges();
	
	//iterate through location changes in current location and check for intersect
	int counter = 0;
	for (std::vector<RectangleShape>::iterator locsItr = changeLocationRects.begin(); locsItr != changeLocationRects.end(); ++locsItr)
	{
	if (this->getRect().getGlobalBounds().intersects(changeLocationRects[counter].getGlobalBounds())) {
	Vector2f newPosition;
	int newLocation;
	if(counter == 0){
		newPosition = wrld.getLocation(this->getCurrentLocation()).getNext1Position();
		newLocation = wrld.getLocation(this->getCurrentLocation()).getLocation1();
	}
	if (counter == 1) {
		newPosition = wrld.getLocation(this->getCurrentLocation()).getNext2Position();
		newLocation = wrld.getLocation(this->getCurrentLocation()).getLocation2();
	}
	if (counter == 2) {
		newPosition = wrld.getLocation(this->getCurrentLocation()).getNext3Position();
		newLocation = wrld.getLocation(this->getCurrentLocation()).getLocation3();
	}
	this->getRect().setPosition(newPosition);
	this->setCurrentLocation(newLocation);
	break;
	}
	counter++;
	}

	//increment walking counter for animation 
	this->setWalkingCounter(this->getWalkingCounter() + 1);

	//added WASD support MH
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
	{
		this->setDirection(1);

		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter)
		{
			this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().x > 0)
		{
			this->getRect().move(-this->getSpeed(), 0);
			this->setCanWalkLeft(!this->checkForIntersect(obstacles, this->getRect()));

			while (this->checkForIntersect(obstacles, this->getRect())) {
				this->getRect().move(1, 0);
			}
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
	{
		this->setDirection(2);

		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter)
		{
			this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 32 * 2, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().x + 32 < window.getSize().x)
		{
			this->getRect().move(this->getSpeed(), 0);
			this->setCanWalkRight(!this->checkForIntersect(obstacles, this->getRect()));

			while (this->checkForIntersect(obstacles, this->getRect())) {
				this->getRect().move(-1, 0);
			}
		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		this->setDirection(3);

		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter)
		{
			this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 96, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().y > 0)
		{
			this->getRect().move(0, -this->getSpeed());
			double temp = this->getSpeed();
			while (this->checkForIntersect(obstacles, this->getRect())) {
				this->getRect().move(0, 1);
			}
		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		this->setDirection(4);

		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter)
		{
			this->getSprite().setTextureRect(IntRect(this->getWalkingCounter() * 32, 0, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().y + 32 < window.getSize().y - 66)
		{
			this->getRect().move(0, this->getSpeed());
			this->setCanWalkDown(!this->checkForIntersect(obstacles, this->getRect()));
			while (this->checkForIntersect(obstacles, this->getRect())) {
				this->getRect().move(0, -1);
			}
		}
	}

	if (this->getWalkingCounter() == 2) {
		setWalkingCounter(0);
	}

	//draw create to the screen
	this->drawCreature(window);
}