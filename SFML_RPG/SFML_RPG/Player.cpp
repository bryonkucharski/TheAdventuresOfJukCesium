#include "Player.h"

Player::Player(std::string playerName, std::string file, World &world) : Creature(playerName, file) {

	this->setSpeed(3);
	this->rect.setSize(Vector2f(28, 28));
	this->setCurrentLocation(1);
	this->rect.setSize(Vector2f(28, 28));
	this->rect.setPosition(Vector2f(5*32, 4*32));
	this->setAllWalk(true);
	this->wrld = world;

	this->setCurrentHealth(300);
	this->setMaxHealth(300);
	this->setLevel(1);
	this->setTotalExperience(10);
	this->setDamage(this->getLevel()*2);

	}
	
Player::~Player() {

}
//handles player movements. called every frame in main.
void Player::updatePlayer(RenderWindow &window) {
	//implement spriting by holding shift, MH
	if (Keyboard::isKeyPressed(Keyboard::LShift) || Keyboard::isKeyPressed(Keyboard::RControl)){
		this->setSpeed(running);
	}
	else{
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
	for (std::vector<RectangleShape>::iterator locsItr = changeLocationRects.begin(); locsItr != changeLocationRects.end(); ++locsItr){
		if (this->rect.getGlobalBounds().intersects(changeLocationRects[counter].getGlobalBounds())){
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
			if (counter == 3) {
				newPosition = wrld.getLocation(this->getCurrentLocation()).getNext4Position();
				newLocation = wrld.getLocation(this->getCurrentLocation()).getLocation4();
			}
			
			//this->setCurrentPosition(newPosition);
			this->rect.setPosition(newPosition);
			sprite.setPosition(newPosition);
			this->setCurrentLocation(newLocation);
			this->setCurrentPosition(this->rect.getPosition());

			cout << "Location Change to " << newLocation << " to position " << newPosition.x << " " << newPosition.y << endl;
			//cout << "Player's current location is " << getCurrentPosition().x  << " " << getCurrentPosition().y  << endl;
			cout << "Rectangle Position " << this->rect.getPosition().x << " " << this->rect.getPosition().y << endl;
			cout << "Sprite's Position " << this->sprite.getPosition().x << " " << this->sprite.getPosition().y << endl;

			return;
		}
		counter++;
	}//end of forloop to change locations
	
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		if (this->canShoot()) {
			Projectile * newProjectile = new Projectile("res/Projectiles/fireProjectile.png", Vector2f(18, 18), 
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				,this->getDirection(), 5);
			this->addToBullets(newProjectile);
		}
	}// end of if space was pressed do a projectile

	//added WASD support MH
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A)){
		this->setDirection(1);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter){
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().x > 0){
			this->rect.move(-this->getSpeed(), 0);
			this->setCanWalkLeft(!this->checkForIntersect(obstacles, this->rect));

			while (this->checkForIntersect(obstacles, this->rect)) {
				this->rect.move(1, 0);
			}
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D)){
		this->setDirection(2);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter){
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32 * 2, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().x + 32 < window.getSize().x){
			this->rect.move(this->getSpeed(), 0);
			this->setCanWalkRight(!this->checkForIntersect(obstacles, this->rect));

			while (this->checkForIntersect(obstacles, this->rect)) {
				this->rect.move(-1, 0);
			}
		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)){
		this->setDirection(3);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter){
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 96, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().y > 0){
			this->rect.move(0, -this->getSpeed());
			double temp = this->getSpeed();
			while (this->checkForIntersect(obstacles, this->rect)) {
				this->rect.move(0, 1);
			}
		}

	}
	else if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)){
		this->setDirection(4);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter){
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 0, 32, 32));
			animationClock.restart();
		}

		if (this->getCurrentPosition().y + 32 < window.getSize().y - 66){
			this->rect.move(0, this->getSpeed());
			this->setCanWalkDown(!this->checkForIntersect(obstacles, this->rect));
			while (this->checkForIntersect(obstacles, this->rect)) {
				this->rect.move(0, -1);
			}
		}
	}
	this->updateAnimationCounter();
}//end of keyboard input

//what happends to the player on intersection with an enemy
void Player::onEnemyIntersect(){
	//decrease the health
	this->setCurrentHealth(this->getCurrentHealth() - 1);
}

//what happends to the player on the intersection with an enemy projecetile
void Player::onEnemyBulletIntersect(){
	//decrease the health
	this->setCurrentHealth(this->getCurrentHealth() - 1);
}

//what happens when experience is gained.
void Player::onIncreaseXPEvent(int amount){
	//update experience
	this->setTotalExperience(this->getTotalExperience() + amount);
	
	//when you level up do stuff.
	if (this->didPlayerLevel()) {
		int level = this->getLevel() + 1;
		this->setLevel(level);
		this->setDamage(this->getDamage() + 1);
		this->setMaxHealth(this->getMaxHealth() + 10);
		this->setCurrentHealth(this->getMaxHealth());
	}
}

bool Player::didPlayerLevel() {
	if (this->getTotalExperience() / 10 > this->getLevel() || this->getTotalExperience() % 10 == 0) {
		return true;
	}
	else {
		return false;
	}
}