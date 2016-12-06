#include "Creature.h"

Creature::Creature(std::string creatureName, std::string file) {
	
	this->setName(creatureName);
	this->texture.loadFromFile(file);
	this->sprite.setTexture(this->texture);

	this->sprite.setTextureRect(IntRect(0, 0, 32, 32));
	this->setWalkingCounter(1);
	this->setwalkingCounterDirection(1);
	this->animationCounter = .05;
	this->setDirection(4);
	this->wayToMove = 1;


}
Creature::~Creature() {

}
//setters
void Creature::setCurrentHealth(int h) {
	this->currentHealth = h;
}
void::Creature::setDamage(int d) {
	this->damage = d;
}
void Creature::setLevel(int l) {
	this->level = l;
}
void Creature::setTotalExperience(int xp) {
	this->totalExperience = xp;
}
void Creature::setMaxHealth(int maxH) {
	this->maxHealth = maxH;
}
void Creature::setName(std::string name) {
	this->name = name;
}
void Creature::setSpeed(float s) {
	this->speed = s;
}
void Creature::setDirection(int d) {
	this->direction = d;
}
void Creature::setWalkingCounter(int w) {
	this->walkingCounter = w;
}
void Creature::setwalkingCounterDirection(int w) {
	this->walkingCounterDirection = w;
}
void Creature::setCanWalkUp(bool up) {
	this->canWalkUp = up;
}
void Creature::setCanWalkDown(bool down) {
	this->canWalkDown = down;
}
void Creature::setCanWalkLeft(bool left) {
	this->canWalkLeft = left;
}
void Creature::setCanWalkRight(bool right) {
	this->canWalkRight = right;
}
void Creature::setAI_ID(int a) {
	this->aID = a;
}

//getters
int Creature::getCurrentHealth() {
	return currentHealth;
}
int Creature::getMaxHealth() {
	return maxHealth;
}
int Creature::getDamage() {
	return damage;
}
int Creature::getLevel() {
	return level;
}
int Creature::getTotalExperience() {
	return totalExperience;
}
std::string Creature::getName() {
	return name;
}
double Creature::getSpeed() {
	return speed;
}
int Creature::getDirection() {
	return direction;
}
int Creature::getWalkingCounter() {
	return walkingCounter;
}
int Creature::getwalkingCounterDirection() {
	return walkingCounterDirection;
}
int Creature::getAI_ID() {
	return aID;
}

void Creature::setCurrentLocation(int l) {
	this->currentLocation = l;
}
int Creature::getCurrentLocation() {
	return currentLocation;
}
void Creature::setCurrentPosition(Vector2f p) {
	this->currentPosition = p;
}
Vector2f& Creature::getCurrentPosition() {
	return currentPosition;
}
bool Creature::checkForIntersect(std::vector<RectangleShape> &obs, RectangleShape &rect) {

	//iterate through obstacles in current location and check for intersect 
	int counter = 0;
	for (std::vector<RectangleShape>::iterator obsIter = obs.begin(); obsIter != obs.end(); ++obsIter){
		if (rect.getGlobalBounds().intersects(obs[counter].getGlobalBounds())) {
			return true;
		}
		counter++;
	}
	return false;

}
void Creature::setAllWalk(bool val) {
	this->setCanWalkUp(val);
	this->setCanWalkDown(val);
	this->setCanWalkLeft(val);
	this->setCanWalkRight(val);
}

void Creature::updateAnimationCounter() {

	//increment walking counter for animation 
	this->setWalkingCounter(this->getWalkingCounter() + this->getwalkingCounterDirection());

	//used to display the proper image of the spritesheet
	if ((this->getWalkingCounter() == 0) || (this->getWalkingCounter() == 2)) {
		setwalkingCounterDirection(this->getwalkingCounterDirection() * -1);
	}
}
std::vector<Projectile*>  Creature::getBullets() {
	return bullets;
}
void Creature::addToBullets(Projectile *bullet) {
	this->bullets.push_back(bullet);
}

bool Creature::canShoot() {
	bulletTime = bulletClock.getElapsedTime();
	if((bullets.size() < 3) && (bulletTime.asSeconds() > .3)){
		bulletClock.restart();
		return true;
	}
	return false;
}

void Creature::removeBullets() {
	/*Using a "Remove-Erase Idiom  https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom
	  Used http://stackoverflow.com/questions/22729906/stdremove-if-not-working-properly for help writing a lambda function

	  Lambda funtion same as 
	  bool isInactive(Projectile *p) {return !p->isActive()}
	*/
	bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Projectile *p) { return !p->isActive(); }), bullets.end());
}

void Creature::onEnemyIntersect(){

}

void Creature::onNPCIntersect(){

}

void Creature::onEnemyBulletIntersect(){

}

void Creature::onPlayerBulletIntersect(){

}

void Creature::onPlayerIntersect(){

}

//AI Selector
void Creature::selectMovementAI(int AI_ID) {
	switch (AI_ID) {
	case 1:
		//Stand Still.
		ai1();
		break;
	case 2:
		//Move random direction.
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
		ai6();
		break;
	case 7:
		//Move in a U shape. "[_]" ish
		ai7();
		break;
	default:
		//defaults to standing still.

		break;
	};//end of switch case
}//end of selectAI()

void Creature::ai1() {
	//Stants still.
	//iLmao.
}//end of ai1()

void Creature::ai2() {
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
	}
	else if (getDirection() == 2) {
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
	}
	else if (getDirection() == 3) {
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
	}
	else if (getDirection() == 4) {
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

	this->updateAnimationCounter();
}//end of ai2()

void Creature::ai3() {
	//Move in a 3 x 3 loop.
	genericTime = genericClock.getElapsedTime();
	int timeToWalk = 1;//how many seconds you want the ai to move.

	if (this->wayToMove == 1) {
		setDirection(1);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));//this changes png left
			animationClock.restart();
		}
		this->rect.move(-this->getSpeed(), 0);//going left

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(1, 0);
		}
	}
	if (this->wayToMove == 2) {
		setDirection(2);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 96, 32, 32));//changing png up
			animationClock.restart();
		}
		this->rect.move(0, -this->getSpeed());//going up
		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(0, 1);
		}
	}
	if (this->wayToMove == 3) {
		setDirection(3);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32 * 2, 32, 32));//changing png right
			animationClock.restart();
		}
		this->rect.move(this->getSpeed(), 0);//going right

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(-1, 0);
		}
	}
	if (this->wayToMove == 4) {
		setDirection(4);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 0, 32, 32));//changing png down
			animationClock.restart();
		}
		this->rect.move(0, this->getSpeed());//going down

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(0, -1);
		}
	}
	//resetting the clock
	if (genericTime.asSeconds() > timeToWalk) {
		genericClock.restart();
		this->wayToMove++;
		if (this->wayToMove == 5) {
			this->wayToMove = 1;
		}
	}
	this->updateAnimationCounter();
}//end of ai3()

void Creature::ai4() {
	//Move in a horizontal line back and forth for an ammount of time.
	genericTime = genericClock.getElapsedTime();
	int timeToWalk = 1;//how many seconds you want the ai to move.
	if (this->wayToMove == 1) {
		setDirection(1);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));//this changes png left
			animationClock.restart();
		}
		this->rect.move(-this->getSpeed(), 0);//going left

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(this->getSpeed(), 0);
		}
	}
	if(this->wayToMove == 2 ){
		setDirection(2);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32 * 2, 32, 32));//changing png right
			animationClock.restart();
		}
		this->rect.move(this->getSpeed(), 0);//going right

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(-this->getSpeed(), 0);
		}
	}
	if (genericTime.asSeconds() > timeToWalk) {
		genericClock.restart();
		this->wayToMove++;
		if (this->wayToMove == 3) {
			this->wayToMove = 1;
		}
	}
	this->updateAnimationCounter();

}//end of ai4()

void Creature::ai5() {
	//Move in a vertical line back and forth 3 spaces.
	genericTime = genericClock.getElapsedTime();
	int timeToWalk = 1;//how many seconds you want the ai to move.
	if (this->wayToMove == 1) {
		setDirection(3);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 96, 32, 32));//this changes png up
			animationClock.restart();
		}
		this->rect.move(0, -this->getSpeed());//going up

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(0, this->getSpeed());
		}
	}
	else if(this->wayToMove == 2) {
		setDirection(4);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 0, 32, 32));//changing png down
			animationClock.restart();
		}
		this->rect.move(0, this->getSpeed());//going down

		while (this->checkForIntersect(currentObstacles, this->rect)) {
			this->rect.move(0, -this->getSpeed());
		}
	}
	if (genericTime.asSeconds() > timeToWalk) {
		genericClock.restart();
		this->wayToMove++;
		if (this->wayToMove == 3) {
			this->wayToMove = 1;
		}
	}
	this->updateAnimationCounter();
}//end of ai5()

void Creature::ai6() {
	//spin
	genericTime = genericClock.getElapsedTime();
	float timeToWalk = .08;//how many seconds you want the ai to move.
	if (this->wayToMove == 1) {
		setDirection(1);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32, 32, 32));//this changes png left
			animationClock.restart();
		}
	}
	if (this->wayToMove == 2) {
		setDirection(2);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 96, 32, 32));//changing png up
			animationClock.restart();
		}
	}
	if (this->wayToMove == 3) {
		setDirection(3);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 32 * 2, 32, 32));//changing png right
			animationClock.restart();
		}
	}
	if (this->wayToMove == 4) {
		setDirection(4);
		animationTime = animationClock.getElapsedTime();
		if (animationTime.asSeconds() > animationCounter) {
			this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 32, 0, 32, 32));//changing png down
			animationClock.restart();
		}
	}
	//resetting the clock
	if (genericTime.asSeconds() > timeToWalk) {
		genericClock.restart();
		this->wayToMove++;
		if (this->wayToMove == 5) {
			this->wayToMove = 1;
		}
	}
	this->updateAnimationCounter();
}//end of ai6()

void Creature::ai7() {
	//Moves in a [_} shape.
	genericTime = genericClock.getElapsedTime();
	animationTime = animationClock.getElapsedTime();
	int timeToWalk = 1;//how many seconds you want the ai to move.

	if (animationTime.asSeconds() > animationCounter) {
		this->sprite.setTextureRect(IntRect(this->getWalkingCounter() * 80, 0, 80, 80));//changing png right
		animationClock.restart();
	}

	switch (this->getDirection()) {
		case 1:
			//left
			this->rect.move(-1,0);
			while (this->checkForIntersect(currentObstacles, this->rect)) {
				this->rect.move(this->getSpeed(), 0);
			}
			break;
		case 2:
			//right
			this->rect.move(1, 0);
			while (this->checkForIntersect(currentObstacles, this->rect)) {
				this->rect.move(-this->getSpeed(), 0);
			}
			break;
		case 3:
			//up
			this->rect.move(0, -1);
			while (this->checkForIntersect(currentObstacles, this->rect)) {
				this->rect.move(0, this->getSpeed());
			}
			break;
		case 4:
			//down
			this->rect.move(0, 1);
			while (this->checkForIntersect(currentObstacles, this->rect)) {
				this->rect.move(0, -this->getSpeed());
			}
			break;
	};
	
	//resetting the clock
	if (genericTime.asSeconds() > timeToWalk) {
		genericClock.restart();
		switch (this->wayToMove) {
			case 1:
				//down
				this->setDirection(4);
				this->wayToMove++;
				break;
			case 2:
				//right
				this->setDirection(2);
				this->wayToMove++;
				break;
			case 3:
				//up
				this->setDirection(3);
				this->wayToMove++;
				break;
			case 4:
				//down
				this->setDirection(4);
				this->wayToMove++;
				break;
			case 5:
				//left
				this->setDirection(1);
				this->wayToMove++;
				break;
			case 6:
				//up
				this->setDirection(3);
				this->wayToMove = 1;
				break;
			};
	}

	this->updateAnimationCounter();
}//end of ai7()

void Creature::setRandomDirection() {
	genericTime = genericClock.getElapsedTime();
	if (genericTime.asSeconds() > .5)
	{
		setDirection(rand() % 4 + 1);
		genericClock.restart();
	}

}