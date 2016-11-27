#include "Player.h"

Player::Player(std::string playerName, std::string file, World &world) : Creature(playerName, file) {
	this->sprite.setTextureRect(IntRect(0, 0, 32, 32));
	this->setWalkingCounter(0);
	this->animationCounter = .05;
	this->setDirection(4);
	this->setSpeed(3);
	this->setCurrentLocation(1);
	this->rect.setSize(Vector2f(28, 28));
	this->sprite.setPosition(Vector2f(2, 2));
	this->setAllWalk(true);
	this->wrld = world;

	this->setCurrentHealth(100);
	this->setMaxHealth(100);
	this->setLevel(1);
	this->setTotalExperience(1);
	this->setDamage(this->getLevel()*2);
	
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
	this->sprite.setPosition(this->rect.getPosition());

	//get the current x and y of the player every frame
	this->setCurrentPosition(this->rect.getPosition());

	//holds all rectangles that the player is not allowed to insersect with
	std::vector<RectangleShape> obstacles = wrld.getLocation(this->getCurrentLocation()).getObstacles();


	//holds all rectangles that will change the players location if intersected with
	std::vector<RectangleShape> changeLocationRects = wrld.getLocation(this->getCurrentLocation()).getLocationChanges();
	
	//iterate through location changes in current location and check for intersect
	int counter = 0;
	for (std::vector<RectangleShape>::iterator locsItr = changeLocationRects.begin(); locsItr != changeLocationRects.end(); ++locsItr)
	{
		if (this->rect.getGlobalBounds().intersects(changeLocationRects[counter].getGlobalBounds()))
		{
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
			this->rect.setPosition(newPosition);
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
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().x > 0)
		{
			this->rect.move(-this->getSpeed(), 0);
			this->setCanWalkLeft(!this->checkForIntersect(obstacles, this->rect));

			while (this->checkForIntersect(obstacles, this->rect)) {
				this->rect.move(1, 0);
			}
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
	{
		this->setDirection(2);

		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter)
		{
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32 * 2, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().x + 32 < window.getSize().x)
		{
			this->rect.move(this->getSpeed(), 0);
			this->setCanWalkRight(!this->checkForIntersect(obstacles, this->rect));

			while (this->checkForIntersect(obstacles, this->rect)) {
				this->rect.move(-1, 0);
			}
		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		this->setDirection(3);

		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter)
		{
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 96, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().y > 0)
		{
			this->rect.move(0, -this->getSpeed());
			double temp = this->getSpeed();
			while (this->checkForIntersect(obstacles, this->rect)) {
				this->rect.move(0, 1);
			}
		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		this->setDirection(4);

		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter)
		{
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 0, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().y + 32 < window.getSize().y - 66)
		{
			this->rect.move(0, this->getSpeed());
			this->setCanWalkDown(!this->checkForIntersect(obstacles, this->rect));
			while (this->checkForIntersect(obstacles, this->rect)) {
				this->rect.move(0, -1);
			}
		}
	}

	if (this->getWalkingCounter() == 2) {
		setWalkingCounter(0);
	}

	//draw create to the screen
	this->drawCreature(window);
}