#include "NPC.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define PIXEL_SIZE 32

NPC::NPC(std::string file, std::string name, int location, int AI_ID,Vector2f startingPosition, std::vector<RectangleShape> &obstacles) : Creature(name, file) {
	this->sprite.setTextureRect(IntRect(0, 0, 32, 32));
	this->rect.setSize(Vector2f(32, 32));
	this->setCurrentLocation(location);
	this->rect.setPosition(startingPosition);
	this->rect.setFillColor(Color::Transparent);
	this->setSpeed(1);
	
	aID = AI_ID;

	srand(time(NULL));
	currentObstacles = obstacles;
	font.loadFromFile("res/Fonts/Vecna.otf");
	text.setFont(font);
	text.setCharacterSize(10);
	text.setFillColor(Color::White);
}//end of NPC constructor

NPC::~NPC() {
	std::cout << "An NPC has been destroyed." << std::endl;
}
void NPC::updateNPC() {
	this->sprite.setPosition(this->rect.getPosition());
}//end of updateNPC()

void NPC::drawText() {
	text.setString("Level " + std::to_string(this->getLevel()) + "\n" + this->getName() + "  " + std::to_string(this->getCurrentHealth()) + " / " + std::to_string(this->getMaxHealth()));
	text.setPosition(this->rect.getPosition().x, this->rect.getPosition().y - text.getCharacterSize());
}//end of drawText()

void NPC::setRandomDirection() {
	directionTime = directionClock.getElapsedTime();
	if (directionTime.asSeconds() > .5)
	{
		setDirection(rand() % 4 + 1);
		directionClock.restart();
	}
}//end of setRandomDirection()

//AI Selector
void NPC::selectAI(int AI_ID) {
	switch (aID) {
		case 1:
			//Stand Still.
			ai1();
			break;
		case 2:
			//Move like monsters.
			ai1();
			break;
		case 3:
			//Move in a 3 x 3 loop.
			ai3();
			break;
		case 4:
			//Move in a horizontal line back and forth 5 spaces.
			ai4();
			break;
		case 5:
			//Move in a vertical line back and forth 3 spaces.
			ai5();
			break;
		case 6:
			//[NOT USED YET]
			break;
		case 7:
			//[NOT USED YET]
			break;
		default:
			//defaults to standing still.

			break;
	};//end of switch case
}//end of selectAI()

void NPC::ai1() {
	//Stants still.

}//end of ai1()

void NPC::ai2() {
	//Move like monsters.
	if (getDirection() == 1) {
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));
			animationClock.restart();
		}
		this->rect.move(-this->getSpeed(), 0);

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(1, 0);
		}
	}else if (getDirection() == 2) {
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32 * 2, 32, 32));
			animationClock.restart();
		}
		this->rect.move(this->getSpeed(), 0);

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(-1, 0);
		}
	}else if (getDirection() == 3) {
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 96, 32, 32));
			animationClock.restart();
		}
		this->rect.move(0, -this->getSpeed());

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(0, 1);
		}
	}else if (getDirection() == 4) {
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 0, 32, 32));
			animationClock.restart();
		}
		this->rect.move(0, this->getSpeed());
		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(0, -1);
		}
	}//end of all the elseif
}//end of ai2()

void NPC::ai3() {
	//Move in a 3 x 3 loop.

}//end of ai3()

void NPC::ai4() {
	//Move in a horizontal line back and forth 5 spaces.

}//end of ai4()

void NPC::ai5() {
	//Move in a vertical line back and forth 3 spaces.

}//end of ai5()

void NPC::onPlayerBulletIntersect()
{
	//say fuck off XDDDD
}

void NPC::onPlayerIntersect()
{
	//say watch where you're shooting fgt
}

void NPC::onEnemyBulletIntersect()
{
	//say ouch
}