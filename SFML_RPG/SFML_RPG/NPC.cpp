#include "NPC.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#define PIXEL_SIZE 32

NPC::NPC(std::string file, std::string name, std::string intersectionText, int location, int AI_ID,Vector2f startingPosition, std::vector<RectangleShape> &obstacles) : Creature(name, file) {
	this->sprite.setTextureRect(IntRect(0, 0, 32, 32));
	this->rect.setSize(Vector2f(32, 32));
	this->setCurrentLocation(location);
	this->rect.setPosition(startingPosition);
	this->rect.setFillColor(Color::Transparent);
	this->setSpeed(1);
	this->text.setString("");
	this->text.setPosition(this->rect.getPosition().x, this->rect.getPosition().y - text.getCharacterSize());
	this->setWalkingCounter(0);
	
	aID = AI_ID;
	intText = intersectionText;

	srand(time(NULL));
	currentObstacles = obstacles;
	font.loadFromFile("res/Fonts/Vecna.otf");
	text.setFont(font);
	text.setCharacterSize(10);
	text.setFillColor(Color::Yellow);
}//end of NPC constructor

NPC::~NPC() {
	std::cout << "An NPC has been destroyed." << std::endl;
}
void NPC::updateNPC() {
	this->sprite.setPosition(this->rect.getPosition());
	selectAI(this->aID);
}//end of updateNPC()


void NPC::setRandomDirection() {
	directionTime = directionClock.getElapsedTime();
	if (directionTime.asSeconds() > .5)
	{
		setDirection(rand() % 4 + 1);
		directionClock.restart();
	}
}//end of setRandomDirection()


void NPC::setIntersectionText(std::string s) {
	this->intText = s;
}
std::string NPC::getIntersectionText() {
	return this->intText;
}


//AI Selector
void NPC::selectAI(int AI_ID) {
	switch (aID) {
		case 1:
			//Stand Still.
			ai1();
			break;
		case 2:
			//Move like monsters.
			ai2();
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
			//Spin
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
	setRandomDirection();
	if (getDirection() == 1) {
		//left
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
		//right
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
		//up
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
		//down
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
	genericTime = genericClock.getElapsedTime();
	int timeToWalk = 1;//how many seconds you want the ai to move.
	static int wayToMove = 1;
	if (wayToMove == 1) {
		setDirection(1);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));//this changes png
			animationClock.restart();
		}
		this->rect.move(-this->getSpeed(), 0);//going left

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(1, 0);
		}
	}
	if(wayToMove == 2) {
		setDirection(2);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32 * 2, 32, 32));//changing png
			animationClock.restart();
		}
		this->rect.move(0, -this->getSpeed());//going up
		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(0, 1);
		}
	}
	if (wayToMove == 3) {
		setDirection(3);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32 * 2, 32, 32));//changing png
			animationClock.restart();
		}
		this->rect.move(this->getSpeed(), 0);//going right

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(-1, 0);
		}
	}
	if (wayToMove == 4) {
		setDirection(4);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 0, 32, 32));//changing png
			animationClock.restart();
		}
		this->rect.move(0, this->getSpeed());//going down

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(0, -1);
		}
	}

	if (genericTime.asSeconds() > timeToWalk) {
		genericClock.restart();
		wayToMove++;
		if (wayToMove == 5) {
			wayToMove = 1;
		}
	}
	this->updateAnimationCounter();
}//end of ai3()

void NPC::ai4() {
	//Move in a horizontal line back and forth for an ammount of time.
	genericTime = genericClock.getElapsedTime();
	int timeToWalk = 1;//how many seconds you want the ai to move.
	static int wayToMove = -1;
	if (wayToMove == -1) {
		setDirection(1);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));//this changes png
			animationClock.restart();
		}
		this->rect.move(wayToMove * this->getSpeed(), 0);//going left

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(-wayToMove * 1, 0);
		}
	}
	else {
		setDirection(2);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32 * 2, 32, 32));//changing png
			animationClock.restart();
		}
		this->rect.move(wayToMove * this->getSpeed(), 0);//going right

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(-wayToMove * 1, 0);
		}
	}
	if (genericTime.asSeconds() > timeToWalk) {
		genericClock.restart();
		wayToMove *= -1;
	}
	this->updateAnimationCounter();
	
}//end of ai4()

void NPC::ai5() {
	//Move in a vertical line back and forth 3 spaces.

}//end of ai5()

void NPC::onPlayerBulletIntersect(){
	//say fuck off XDDDD

}

void NPC::onPlayerIntersect(){
	//say watch where you're shooting fgt
	this->text.setString(this->getIntersectionText());
	textTime = textClock.getElapsedTime();
	if (textTime.asSeconds() > 2) {
		this->text.setString(" ");
		textClock.restart();
	}
}

void NPC::onEnemyBulletIntersect(){
	//say ouch
	onPlayerIntersect();
}