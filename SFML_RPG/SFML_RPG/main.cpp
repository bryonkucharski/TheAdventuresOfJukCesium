#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "World.h"
#include "Player.h"
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

	while (window.isOpen())
	{
		//close window if X is pressed in top right
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		world.drawWorld(window,world.getLocation(mainPlayer.getCurrentLocation()));
		mainPlayer.updatePlayer(window);
		
		
		//window.draw(home.getSprite());
		window.display();
	}

	return 0;
}