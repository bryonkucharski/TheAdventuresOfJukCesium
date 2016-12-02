#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "World.h"
#include "Player.h"
#include "Enemy.h"
#include "GUIBar.h"
#include "globals.h"

using namespace std;

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

	theMainPlayer = &mainPlayer;
	GUIBar guibar(window, "res/System/GUIbar.png","res/Fonts/Vecna.otf");
	Sprite gameOverSprite;
	Texture gameOverTexture;
	gameOverTexture.loadFromFile("res/System/GameOver.png");
	gameOverSprite.setTexture(gameOverTexture);
	bool gameOver = false;

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

		//get all enemies in current location
		currentEnemies = world.getLocation(mainPlayer.getCurrentLocation()).getEnemies();

		//--------------------------------ALL THE INTERSECTIONS------------------------
		//checking for player intersection with enemy
		int intersectionCounter = 0;
		for (std::vector<Enemy*>::iterator enemyIntersectIter = currentEnemies.begin(); enemyIntersectIter != currentEnemies.end(); ++enemyIntersectIter){
			if (mainPlayer.getRect().getGlobalBounds().intersects(currentEnemies[intersectionCounter]->getRect().getGlobalBounds())) {
				mainPlayer.setCurrentHealth(mainPlayer.getCurrentHealth() - 1);
			}
			intersectionCounter++;
		}
		//--------------------------------END INTERSECTIONS-------------------------

		//--------------------------------ALL THE UPDATING------------------------
		
		//update player
		mainPlayer.updatePlayer(window);

		//update enemies in current location
		int enemyUpdateCounter = 0;
		for (std::vector<Enemy*>::iterator enemyUpdateIter = currentEnemies.begin(); enemyUpdateIter != currentEnemies.end(); ++enemyUpdateIter)
		{
			if (currentEnemies[enemyUpdateCounter]->isAlive())
			{
				//draw and update enemy
				currentEnemies[enemyUpdateCounter]->updateEnemy(window);
			}
			else {
				currentEnemies.erase(enemyUpdateIter);
				//need this break statement so the game doesnt break
				break;
			}
			enemyUpdateCounter++;
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
			mainPlayer.drawCreature(window);

			//draw enemies
			int enemyDrawCounter = 0;
			for (std::vector<Enemy*>::iterator enemyDrawIter = currentEnemies.begin(); enemyDrawIter != currentEnemies.end(); ++enemyDrawIter) {
				currentEnemies[enemyDrawCounter]->drawCreature(window);
				currentEnemies[enemyDrawCounter]->drawText(window);
				enemyDrawCounter++;
			}
		}
		else {
			//kill all enemies
			window.clear();
			window.draw(gameOverSprite);
		}
		//------------------------------------------------------------------------------


		window.display();
		
	}
	return 0;
}