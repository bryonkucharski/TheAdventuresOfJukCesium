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
	this->setBulletSpeed(6);
	this->setBulletPng("res/Projectiles/fireProjectile.png");

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
			//dont update player when you change locations, so break out of the loop
			return;
		}
		counter++;
	}//end of forloop to change locations
	
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		if (this->canShoot()) {
			Projectile * newProjectile = new Projectile(this->getBulletPng(), Vector2f(this->getBulletWidth(), this->getBulletHeight()), 
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				,this->getDirection(), this->getBulletSpeed());
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

		std::cout << "You have leveled up. Current level is: " << this->getLevel() << std::endl;
		std::cout << "Damage level has been increased. Current damage level is: " << this->getDamage() + 8 << std::endl;
		std::cout << "Max health has been increased. Current max health is: " << this->getMaxHealth() << std::endl;
		checkForUpgrades();
		std::cout << std::endl;
	}
}

bool Player::didPlayerLevel() {
	int expNeeded = 100;//exp needed to level up
	if (this->getTotalExperience() / expNeeded > this->getLevel() || this->getTotalExperience() % expNeeded == 0) {
		return true;
	}
	else {
		return false;
	}
}

void Player::setBulletSpeed(int sp) {
	bulletSpeed = sp;
}

int Player::getBulletSpeed() {
	return bulletSpeed;
}

void Player::setBulletPng(string png) {
	bulletPng = png;
}

string Player::getBulletPng() {
	return bulletPng;
}

void Player::setBulletWidth(int w) {
	bulletWidth = w;
}
void Player::setBulletHeight(int h) {
	bulletHeight = h;
}
int Player::getBulletWidth() {
	return bulletWidth;
}
int Player::getBulletHeight() {
	return bulletHeight;
}

void Player::checkForUpgrades() {
	//only check for upgrades when you level up.

	//what if we made a vector of upgrades and instantiated upgrades from a class when you level.
	//of a forloop to instantiate a case statement.
	switch (this->getLevel()) {
	case 3:
		std::cout << "Bullet speed has been increased." << std::endl;
		this->setBulletSpeed(this->getBulletSpeed() + 1);
		break;
	case 6:
		std::cout << "Bullet speed has been increased." << std::endl;
		std::cout << "You have learned Fire Shuriken." << std::endl;
		this->setBulletSpeed(this->getBulletSpeed() + 1);
		this->setBulletPng("res/Projectiles/fire2.png");
		break;
	case 9:
		std::cout << "Bullet speed has been increased." << std::endl;
		std::cout << "You have learned Stone Hurl." << std::endl;
		this->setBulletSpeed(this->getBulletSpeed() + 1);
		this->setBulletPng("res/Projectiles/stone1.png");
		break;
	case 12:
		std::cout << "Bullet speed has been increased." << std::endl;
		std::cout << "You have learned Rocket Spin." << std::endl;
		this->setBulletSpeed(this->getBulletSpeed() + 1);
		this->setBulletPng("res/Projectiles/fire3.png");
		break;
	case 15:
		break;
	case 18:
		break;
	case 21:
		break;
	case 24:
		break;
	case 27:
		break;
	case 30:
		break;
	};

}//end of checkForUpgrades();