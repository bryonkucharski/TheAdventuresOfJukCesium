#include "Enemy.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

Enemy::Enemy(std::string file, std::string name, int health, int level) : Creature(name, file) {

	this->sprite.setTextureRect(IntRect(0, 0, 32, 32));

	this->rect.setSize(Vector2f(32, 32));

	srand(time(NULL));

	Vector2f sp;
	sp.x = rand() % 800 + 150;
	sp.y = rand() % 500 + 50;
	this->rect.setPosition(sp);

	this->setWalkingCounter(0);
	this->animationCounter = .05;
	this->setDirection(4);
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
void Enemy::updateEnemy(RenderWindow &window) {
	this->drawText(window);
	this->sprite.setPosition(Vector2f(this->rect.getPosition().x + 10, this->rect.getPosition().y + 10));

	//get random direction
	setRandomDirection();

	//move based on direction
	if (getDirection() == 0)
	{
		this->rect.move(0, getSpeed());
	}
	else if (getDirection() == 1)
		this->rect.move(-getSpeed(), 0);
	else if (getDirection() == 2)
		this->rect.move(getSpeed(), 0);
	else if (getDirection() == 3)
		this->rect.move(0, -getSpeed());


	this->drawCreature(window);
}
bool Enemy::isAlive() {
	return this->alive;
}
void Enemy::setAlive(bool a) {
	this->alive = a;
}
void Enemy::drawText(RenderWindow &window) {
	text.setString(std::to_string(this->getLevel()) + " " + this->getName() + " " + std::to_string(this->getCurrentHealth()) + " / " + std::to_string(this->getMaxHealth()));
	text.setPosition(this->rect.getPosition());
	window.draw(text);
}
void Enemy::setRandomDirection() {
	directionTime = directionClock.getElapsedTime();
	if (directionTime.asSeconds() > .1)
	{
		setDirection(rand() % 4 + 0);
		directionClock.restart();
	}
}