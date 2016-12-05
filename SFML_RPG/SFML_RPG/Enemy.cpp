#include "Enemy.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cmath>

Enemy::Enemy(std::string file, std::string name,int location, int AI_ID, int health, int level,Vector2f startingPosition, std::vector<RectangleShape> &obstacles) : Creature(name, file) {

	this->sprite.setTextureRect(IntRect(0, 0, 32, 32));
	this->rect.setSize(Vector2f(32, 32));

	this->bOnDeath.loadFromFile("res/Sounds/Attack3.ogg");
	this->bOnHit.loadFromFile("res/Sounds/Attack2.ogg");
	this->soundOnDeath.setBuffer(bOnDeath);
	this->soundOnHit.setBuffer(bOnHit);

	srand(time(NULL));

	this->setCurrentLocation(location);
	this->rect.setPosition(startingPosition);

	this->currentObstacles = obstacles;

	this->setSpeed(1);
	this->setAlive(true);

	this->setAI_ID(AI_ID);

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
		this->shootPlayer(playerPos);
	}

	this->sprite.setPosition(Vector2f(this->rect.getPosition().x + 10, this->rect.getPosition().y + 10));

	//update text above enemy
	text.setString("Level " + std::to_string(this->getLevel()) + "\n" + this->getName() + "  " + std::to_string(this->getCurrentHealth()) + " / " + std::to_string(this->getMaxHealth()));
	text.setPosition(this->rect.getPosition().x, this->rect.getPosition().y - text.getCharacterSize());

	this->selectAI(this->getAI_ID());

}//end of update enemy

bool Enemy::isAlive() {
	return this->alive;
}
void Enemy::setAlive(bool a) {
	this->alive = a;
}

//what to do when the enemy is hit by a player bullet
void Enemy::onPlayerBulletIntersect(int damage){
	//loose health
	this->setCurrentHealth(this->getCurrentHealth() - damage);
	this->soundOnHit.play();
	
}

int Enemy::dropExp() {
	this->soundOnDeath.play();
	int exp = this->getMaxHealth() / 20 + this->getLevel();
	return exp;
}