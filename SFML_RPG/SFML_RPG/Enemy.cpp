#include "Enemy.h"

Enemy::Enemy(std::string file, std::string name, int health, int level) : Creature(name, file) {

	this->sprite.setTextureRect(IntRect(0, 0, 32, 32));

	this->rect.setSize(Vector2f(32, 32));
	this->rect.setPosition(Vector2f(100,100));

	this->setWalkingCounter(0);
	this->animationCounter = .05;
	this->setDirection(4);
	this->setSpeed(3);
	this->setAlive(true);

	this->setMaxHealth(health);
	this->setCurrentHealth(health);
	this->setLevel(level);
	this->setDamage(level * 2);

}
Enemy::~Enemy() {

}
void Enemy::updateEnemy(RenderWindow &window) {
	this->sprite.setPosition(this->rect.getPosition());
	window.draw(this->getSprite());
}
bool Enemy::isAlive() {
	return this->alive;
}
void Enemy::setAlive(bool a) {
	this->alive = a;
}