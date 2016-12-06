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

	this->currentObstacles = obstacles;
	
	/*
	this->bOnHit.loadFromFile("res/Sounds/Cancel2.ogg");
	this->soundOnHit.setBuffer(bOnHit);
	this->soundOnHit.setPitch(.55);
	*/

	this->setAI_ID(AI_ID);
	intText = intersectionText;

	srand(time(NULL));
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
	text.setPosition(this->rect.getPosition().x, this->rect.getPosition().y - text.getCharacterSize());

	textTime = textClock.getElapsedTime();
	if (textTime.asSeconds() > 1) {
		this->text.setString(this->getName());
	}

	selectMovementAI(this->getAI_ID());
}//end of updateNPC()

void NPC::setIntersectionText(std::string s) {
	this->intText = s;
}
std::string NPC::getIntersectionText() {
	return this->intText;
}

void NPC::onPlayerBulletIntersect(){
	this->text.setString("OUCH!!");
	textClock.restart();
	//this->soundOnHit.play();
}

void NPC::onPlayerIntersect(){
	//give player a message
	textClock.restart();
	this->text.setString(this->getIntersectionText());
}
