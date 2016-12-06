#include "Enemy.h"

Enemy::Enemy(std::string file, std::string name,int location, int AI_ID, int aiShoot, int health, int level,Vector2f startingPosition, std::vector<RectangleShape> &obstacles) : Creature(name, file) {

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
	this->setShootAI(aiShoot);

	this->setMaxHealth(health);
	this->setCurrentHealth(health);
	this->setLevel(level);
	this->setDamage(level * 2);

	font.loadFromFile("res/Fonts/Vecna.otf");
	text.setFont(font);
	text.setCharacterSize(10);
	text.setFillColor(Color::White);
}

Enemy::Enemy(std::string file, std::string name, int location, int AI_ID, int aiShoot, int health, int level, Vector2f startingPosition, std::vector<RectangleShape> &obstacles, Vector2f pixelSize) : Creature(name, file) {

	this->sprite.setTextureRect(IntRect(0, 0, 80, 80));
	this->rect.setSize(pixelSize);

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
	this->setShootAI(aiShoot);

	this->setMaxHealth(health);
	this->setCurrentHealth(health);
	this->setLevel(level);
	this->setDamage(level * 2);

	font.loadFromFile("res/Fonts/Vecna.otf");
	text.setFont(font);
	text.setCharacterSize(10);
	text.setFillColor(Color::White);
	this->clockCheck = true;
	this->bossTemp = 0;
}

Enemy::~Enemy() {

}
void Enemy::updateEnemy(Vector2f playerPos){
	//killing enemies
	if (this->getCurrentHealth() <= 0) {
		this->setAlive(false);
		return;//so you dont update his position.
	}

	this->sprite.setPosition(Vector2f(this->rect.getPosition().x + 10, this->rect.getPosition().y + 10));

	//update text above enemy
	text.setString("Level " + std::to_string(this->getLevel()) + "\n" + this->getName() + "  " + std::to_string(this->getCurrentHealth()) + " / " + std::to_string(this->getMaxHealth()));
	text.setPosition(this->rect.getPosition().x, this->rect.getPosition().y - text.getCharacterSize());

	this->selectMovementAI(this->getAI_ID());
	this->selectShootAI(this->getShootAI(), playerPos);
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

void Enemy::setShootAI(int aiShoot) {
	this->shootAI = aiShoot;
}
int Enemy::getShootAI() {
	return this->shootAI;
}

void Enemy::selectShootAI(int aiShoot, Vector2f playerPos) {
	switch (aiShoot) {
		case 1: this->shootAI1(playerPos);
			break;
		case 2: this->shootAI2(playerPos);
			break;
		case 3: this->shootAI3(playerPos);
			break;
		case 4: this->shootAI4(playerPos);
			break;
		case 5: this->shootAI5(playerPos);
			break;
		default:
			//no ai
			break;
	};
 
}

void Enemy::shootAI1(Vector2f playerPos) {
	if (canShoot()) {
		float distX = this->getRect().getPosition().x - playerPos.x;
		float distY = this->getRect().getPosition().y - playerPos.y;
		distX = distX*distX;
		distY = distY*distY;
		float distance = sqrt(distX + distY);
		if (distance < 100) {
			float offX;
			float offY;
			switch (this->getDirection()) {
				case 1:
					offX = -1;
					offY = 0;
					break;
				case 2:
					offX = 1;
					offY = 0;
					break;
				case 3:
					offX = 0;
					offY = -1;
					break;
				case 4:
					offX = 0;
					offY = 1;
					break;
			}

			//create new projectile
			Projectile * newProjectile = new Projectile("res/Projectiles/enemyProjectile.png", Vector2f(18, 18),
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				,offX,offY, this->getDirection(), 5);
			this->addToBullets(newProjectile);
		}
	}
}//end of shootAI1

void Enemy::shootAI2(Vector2f playerPos) {
	//shoots at the player, speed of bullet is porportional to distance
	if (canShoot()) {
		float pi = 3.14159;
		float theta;
		float playerX = playerPos.x;
		float playerY = playerPos.y;
		float enemyX = this->getRect().getPosition().x;
		float enemyY = this->getRect().getPosition().y;
		float distX = playerX - enemyX;
		float distY = playerY - enemyY;
		float trackX = distX;
		float trackY = distY;
		distX = distX*distX;
		distY = distY*distY;
		float distance = sqrt(distX + distY);

		float offX = trackX / 256;
		float offY = trackY / 256;

		if (distance < 150) {
			//create new projectile
			Projectile * newProjectile = new Projectile("res/Projectiles/enemyProjectile.png", Vector2f(18, 18),
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				,offX,offY, this->getDirection(), 5);

			this->addToBullets(newProjectile);
		}
	}
}//end of shootAI2

void Enemy::shootAI3(Vector2f playerPos) {
	//shoots at the player, speed of bullet is constant
	if (canShoot()) {
		float distanceX = (playerPos.x) - (this->rect.getPosition().x);
		float distanceY = (playerPos.y) - (this->rect.getPosition().y);
		float distX = distanceX*distanceX;
		float distY = distanceY*distanceY;
		float distance = sqrt(distX + distY);
		if (distance < 150) {
			float pi = 3.1415926;
			float theta = atan2f(distanceY, distanceX)*(180 / pi);
			float thetaRad = (theta*(pi / 180));
			float shootX = cosf(thetaRad);
			float shootY = sinf(thetaRad);
			Projectile * newProjectile = new Projectile("res/Projectiles/enemyProjectile.png", Vector2f(18, 18),
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				,shootX,shootY, this->getDirection(), 5);
			this->addToBullets(newProjectile);
			//this->addToBullets(newProjectile);
		}
	}
}//end of shootAI3

void Enemy::shootAI4(Vector2f playerPos) {
	//the boss AI
	if (canShoot()) {
		float distanceX = (playerPos.x) - (this->rect.getPosition().x);
		float distanceY = (playerPos.y) - (this->rect.getPosition().y);
		float distX = distanceX*distanceX;
		float distY = distanceY*distanceY;
		float distance = sqrt(distX + distY);
		if (distance < 150) {
			Projectile * newProjectile1 = new Projectile("res/Projectiles/enemyProjectile.png", Vector2f(18, 18),
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				, 0, -1, this->getDirection(), 5);
			Projectile * newProjectile2 = new Projectile("res/Projectiles/enemyProjectile.png", Vector2f(18, 18),
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				, 0.53, -0.53, this->getDirection(), 5);
			Projectile * newProjectile3 = new Projectile("res/Projectiles/enemyProjectile.png", Vector2f(18, 18),
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				, 1, 0, this->getDirection(), 5);
			Projectile * newProjectile4 = new Projectile("res/Projectiles/enemyProjectile.png", Vector2f(18, 18),
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				, 0.53, 0.53, this->getDirection(), 5);
			Projectile * newProjectile5 = new Projectile("res/Projectiles/enemyProjectile.png", Vector2f(18, 18),
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				, 0, 1, this->getDirection(), 5);
			Projectile * newProjectile6 = new Projectile("res/Projectiles/enemyProjectile.png", Vector2f(18, 18),
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				, -0.53, 0.53, this->getDirection(), 5);
			Projectile * newProjectile7 = new Projectile("res/Projectiles/enemyProjectile.png", Vector2f(18, 18),
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				, -1, 0, this->getDirection(), 5);
			Projectile * newProjectile8 = new Projectile("res/Projectiles/enemyProjectile.png", Vector2f(18, 18),
				Vector2f(this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2), this->rect.getPosition().y + (this->rect.getGlobalBounds().height / 2))
				, -0.53, -0.53, this->getDirection(), 5);
			this->addToBullets(newProjectile1);
			this->addToBullets(newProjectile2);
			this->addToBullets(newProjectile3);
			this->addToBullets(newProjectile4);
			this->addToBullets(newProjectile5);
			this->addToBullets(newProjectile6);
			this->addToBullets(newProjectile7);
			this->addToBullets(newProjectile8);
		}
	}
}//end of shootAI4

void Enemy::shootAI5(Vector2f playerPos) {
	if (this->clockCheck)
	{
		std::cout << "starting timer\n";
		bossClock.restart();
		this->clockCheck = false;
	}
	this->bossTime = bossClock.getElapsedTime();
	std::cout << "time is " << bossTime.asSeconds() << "\n";
	if (this->bossTime.asSeconds() > 3) {
		bossTemp++;
		bossClock.restart();
		int i = bossTemp % 2;
		if (i == 0)
		{
			//ai 4
			std::cout << "starting ai 4\n";
			this->shootAI4(playerPos);
		}
		else
		{
			//ai 2
			std::cout << "starting ai 2\n";
			this->shootAI2(playerPos);
		}
	}

}//end of shootAI5