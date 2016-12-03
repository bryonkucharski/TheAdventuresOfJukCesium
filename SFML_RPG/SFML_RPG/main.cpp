#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <fstream>

#include "World.h"
#include "Player.h"
#include "Enemy.h"
#include "GUIBar.h"
#include "globals.h"


using namespace std;
void saveGame();
void loadGame();

#define PIXEL_SIZE 32
#define WIDTH      30*PIXEL_SIZE
#define HEIGHT     22*PIXEL_SIZE 

/*
https://www.youtube.com/watch?v=axIgxBQVBg0

time stamp 7:40 is important
you may need to copy some .dll files from one place to another inside where your git project is located.
so watching the video from 7:40 on is good to clear some stuff up.

also up top there is a drop down window with x64 x86 and configuration manager left to the compile and run button.
make sure the drop down window says x86

*/
using namespace sf;

int main()
{
	
	//create main game window
	RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML works!");

	//set frame rate
	window.setFramerateLimit(60);

	World world(window);
	Player mainPlayer("Main Player", "res/Creatures/main.png",world);
	std::vector<Enemy*> currentEnemies;
	std::vector<Projectile*> currentPlayerBullets;

	theMainPlayer = &mainPlayer;
	GUIBar guibar(window, "res/System/GUIbar.png","res/Fonts/Vecna.otf");
	Sprite gameOverSprite;
	Texture gameOverTexture;
	gameOverTexture.loadFromFile("res/System/GameOver.png");
	gameOverSprite.setTexture(gameOverTexture);
	bool gameOver = false;
	int temp = 0;
	while (window.isOpen())
	{
		//close window if X is pressed in top right
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//check for a game over
		if (mainPlayer.getCurrentHealth() <= 0) {
			window.clear();
			gameOver = true;
		}
		//------------------------------- ALL THE VECTOR COPIES------------------------
		//vector1.swap(vector2) is more efficient than vector1 = vector2

		//get all enemies in current location
		currentEnemies.swap(world.getLocation(mainPlayer.getCurrentLocation()).getEnemies());
		//all bullets in player's vector
		currentPlayerBullets.swap(mainPlayer.getBullets());

		//----------------------------------END VECTOR COPIES----------------------------

	
		//------------------------------- ALL THE VECTOR REMOVES------------------------
		
		mainPlayer.removeBullets();
		world.getLocation(mainPlayer.getCurrentLocation()).removeEnemies();

		//-------------------------------END VECTOR REMOVALS ----------------------------


		//--------------------------------ALL THE INTERSECSTIONS------------------------
		//checking for player intersection with enemy
		int intersectionCounter = 0;
		for (std::vector<Enemy*>::iterator enemyIntersectIter = currentEnemies.begin(); enemyIntersectIter != currentEnemies.end(); ++enemyIntersectIter) {
			if (mainPlayer.getRect().getGlobalBounds().intersects(currentEnemies[intersectionCounter]->getRect().getGlobalBounds())) {
				Enemy *e = currentEnemies[intersectionCounter];
				mainPlayer.onPlayerIntersect<Enemy>(*e);
				mainPlayer.setCurrentHealth(mainPlayer.getCurrentHealth() - 1);
				currentEnemies[intersectionCounter]->setCurrentHealth(currentEnemies[intersectionCounter]->getCurrentHealth() - 50);
			}
			intersectionCounter++;
		}
		//--------------------------------END INTERSECTIONS-------------------------

		//--------------------------------ALL THE UPDATING------------------------


		//update player
		mainPlayer.updatePlayer(window);

		//update enemies in current location
		int enemyUpdateCounter = 0;
		for (std::vector<Enemy*>::iterator enemyUpdateIter = currentEnemies.begin(); enemyUpdateIter != currentEnemies.end(); ++enemyUpdateIter) {
			//update enemy
			currentEnemies[enemyUpdateCounter]->updateEnemy(window);
			enemyUpdateCounter++;
		}

		//update player Projectiles
		int playerBulletUpdate = 0;
		for (std::vector<Projectile *>::iterator playerBulletsUpdateIter = currentPlayerBullets.begin(); playerBulletsUpdateIter != currentPlayerBullets.end(); ++playerBulletsUpdateIter) {
			currentPlayerBullets[playerBulletUpdate]->update();
			playerBulletUpdate++;
		}
	
		//---------------------------------END UPDATING---------------------------


		//--------------------------------ALL THE DRAWING------------------------
		//draw to screen
		if (!gameOver) {
			//draw world and location
			world.drawWorld(window, world.getLocation(mainPlayer.getCurrentLocation()));

			//graph graphic bar
			guibar.drawAll(window, mainPlayer, world);

			//draw main player
			window.draw(mainPlayer.getSprite());

			//draw enemies
			int enemyDrawCounter = 0;
			for (std::vector<Enemy*>::iterator enemyDrawIter = currentEnemies.begin(); enemyDrawIter != currentEnemies.end(); ++enemyDrawIter) {
				window.draw(currentEnemies[enemyDrawCounter]->getSprite());
				window.draw(currentEnemies[enemyDrawCounter]->getText());
				enemyDrawCounter++;
			}

			//draw player Projectiles
			int playerBulletCounter = 0;
			for (std::vector<Projectile *>::iterator playerBulletsIter = currentPlayerBullets.begin(); playerBulletsIter != currentPlayerBullets.end(); ++playerBulletsIter) {
				window.draw(currentPlayerBullets[playerBulletCounter]->getSprite());
				playerBulletCounter++;
			}
		}
		else {
			window.clear();
			window.draw(gameOverSprite);
		}
		//-------------------------------------END DRAWING----------------------------

		window.display();
		//--------------------------------------SAVE STATE--------------------------------

		if (temp == 0)
		{
			if (Keyboard::isKeyPressed(Keyboard::RAlt) || Keyboard::isKeyPressed(Keyboard::LAlt))
			{
				if (Keyboard::isKeyPressed(Keyboard::F2))
				{
					temp = 20;
					saveGame();
				}

				if (Keyboard::isKeyPressed(Keyboard::F3))
				{
					temp = 20;
					loadGame();
				}
			}
		}
		if (temp > 0)
		temp--;
		//cout << temp << "\n";
	}

	//-----------------------------------------END SAVE-----------------------------------
	return 0;
}
void saveGame()
{
	//save the file
	ofstream theFile;
	theFile.open("saveFile.txt", ios::out);
	//write stuff
	/*
	position
	location
	total experience
	level
	damage
	current health
	max health
	*/
	if (theFile.is_open())
	{
		theFile << theMainPlayer->getCurrentPosition().x << "\n" <<
			theMainPlayer->getCurrentPosition().y << "\n" <<
			theMainPlayer->getCurrentLocation() << "\n" <<
			theMainPlayer->getTotalExperience() << "\n" <<
			theMainPlayer->getLevel() << "\n" <<
			theMainPlayer->getDamage() << "\n" <<
			theMainPlayer->getCurrentHealth() << "\n" <<
			theMainPlayer->getMaxHealth();
	}
	theFile.close();
	cout << "save command pressed\n";
}


void loadGame()
{
	cout << "load command pressed\n";
	ifstream theFile;
	string line;
	theFile.open("saveFile.txt", ios::in);
	float positionx = 0;//0
	float positiony = 0;//1
	int location = 0;//2
	int xp = 2003;//3
	int level = 0;//4
	int damage = 0;//5
	int currentHealth = 0;//6
	int maxHealth = 0;//7
	int counter = 0;
	if (theFile.is_open())
	{
		while (getline(theFile, line))
		{
			//cout << line << '\n';
			switch (counter)
			{
			case 0:
				positionx = stof(line);
				break;
			case 1:
				positiony = stof(line);
				break;
			case 2:
				location = stoi(line);
				break;
			case 3:
				xp = stoi(line);
				break;
			case 4:
				level = stoi(line);
				break;
			case 5:
				damage = stoi(line);
				break;
			case 6:
				currentHealth = stoi(line);
				break;
			case 7:
				maxHealth = stoi(line);
				break;
			}
			counter++;
		}
		theFile.close();
		//write values to player
		theMainPlayer->setCurrentPosition(Vector2f(positionx, positiony));
		theMainPlayer->getRect().setPosition(Vector2f(positionx, positiony));
		theMainPlayer->setCurrentLocation(location);
		theMainPlayer->setTotalExperience(xp);
		theMainPlayer->setLevel(level);
		theMainPlayer->setDamage(damage);
		theMainPlayer->setCurrentHealth(currentHealth);
		theMainPlayer->setMaxHealth(maxHealth);
	}
}