#include "Enemy.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>


Enemy::Enemy(std::string file, std::string name,int location, int health, int level,Vector2f startingPosition, std::vector<RectangleShape> &obstacles) : Creature(name, file) {

	this->sprite.setTextureRect(IntRect(0, 0, 32, 32));
	this->rect.setSize(Vector2f(32, 32));

	srand(time(NULL));

	this->setCurrentLocation(location);
	this->rect.setPosition(startingPosition);

	currentObstacles = obstacles;

	this->setSpeed(1);
	this->setAlive(true);

	this->setMaxHealth(health);
	this->setCurrentHealth(health);
	this->setLevel(level);
	this->setDamage(level * 2);

	font.loadFromFile("res/Fonts/Vecna.otf");
	text.setFont(font);
	text.setCharacterSize(10);
	text.setFillColor(Color::White);
}
Enemy::~Enemy() {

}
void Enemy::updateEnemy(Vector2f playerPos){
	//killing enemies
	if (this->getCurrentHealth() <= 0) {
		this->setAlive(false);
		return;//so you dont update his position.
	}


	if (canShoot()) {
		float distX = this->getRect().getPosition().x - playerPos.x;
		float distY = this->getRect().getPosition().y - playerPos.y;
		distX = distX*distX;
		distY = distY*distY;
		float distance = sqrt(distX + distY);
		std::cout << "Player distance from me: " << distance << std::endl;
		if (distance < 100){
			Projectile * newProjectile = new Projectile("res/Projectiles/fireProjectile.png", Vector2f(18, 18), this->rect.getPosition(), this->getDirection(), 5);
			this->addToBullets(newProjectile);
		}
	}
	


	this->sprite.setPosition(Vector2f(this->rect.getPosition().x + 10, this->rect.getPosition().y + 10));

	//update text above enemy
	text.setString("Level " + std::to_string(this->getLevel()) + "\n" + this->getName() + "  " + std::to_string(this->getCurrentHealth()) + " / " + std::to_string(this->getMaxHealth()));
	text.setPosition(this->rect.getPosition().x, this->rect.getPosition().y - text.getCharacterSize());

	//get random direction
	setRandomDirection();

	//move based on direction
	// left is 1, right is 2, up is 3, down is 4
	if (getDirection() == 1){

		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter){
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));
			animationClock.restart();
		}
		this->rect.move(-this->getSpeed(), 0);

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(1, 0);
		}
	}
	else if (getDirection() == 2) {
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter)
		{
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32 * 2, 32, 32));
			animationClock.restart();
		}

		this->rect.move(this->getSpeed(), 0);
		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(-1, 0);
		}
	}
	else if (getDirection() == 3) {
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter)
		{
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 96, 32, 32));
			animationClock.restart();
		}

		this->rect.move(0, -this->getSpeed());
		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(0, 1);
		}
	}
	else if (getDirection() == 4) {
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter)
		{
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 0, 32, 32));
			animationClock.restart();
		}


		this->rect.move(0, this->getSpeed());
		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(0, -1);
		}
	}

    this->updateAnimationCounter();
}//end of update enemy

bool Enemy::isAlive() {
	return this->alive;
}
void Enemy::setAlive(bool a) {
	this->alive = a;
}
void Enemy::setRandomDirection() {
	directionTime = directionClock.getElapsedTime();
	if (directionTime.asSeconds() > .5)
	{
		setDirection(rand() % 4 + 1);
		directionClock.restart();
	}

}

//what to do when the enemy is hit by a player buttet
void Enemy::onPlayerBulletIntersect(int damage)
{
	//loose health
	this->setCurrentHealth(this->getCurrentHealth() - damage);
}