#include "menu.h"
#include <string>
menu::menu() {
	//nothing is here
}

menu::menu(double width, double height) {
	cout << "Object menu has been created." << std::endl;
	if (!font.loadFromFile("res/IMMORTAL.ttf")) {
		//exit
	}
	else {
		cout << "Font loaded" << std::endl;
	}
	//setting the title
	menuTitle.setFont(font);
	menuTitle.setFillColor(sf::Color::Black);
	menuTitle.setCharacterSize(50);
	menuTitle.setString("The Guild of the Silver Falcon");
	menuTitle.setPosition(Vector2f(110, height / 3));

	//Setting the music
	if (!menuMusic.openFromFile("res/Town6.ogg")) {
		cout << "Music did not load" << std::endl;
	}
	else {
		cout << "Music loaded" << std::endl;
	}
	menuMusic.play();
	menuMusic.setPitch(.55);
	//cool pitch {.3, .5, .8}
	//A pitch of 1 is standard speed, pitch more than 1 is sped up. less than 1 && greater than 0 is slowed down.
	menuMusic.setLoop(true);



	//Setting the menu Selections
	int xPos = 180;
	int yPos = 20;
	menuText[0].setFont(font);
	menuText[0].setFillColor(sf::Color::Yellow);
	menuText[0].setString("Play");
	menuText[0].setPosition(Vector2f(xPos, height / ((MAX_ITEMS) * 4)));

	menuText[1].setFont(font);
	menuText[1].setFillColor(sf::Color::Yellow);
	menuText[1].setString("Load");
	menuText[1].setPosition(Vector2f(xPos, height / ((MAX_ITEMS) * 2)));

	menuText[2].setFont(font);
	menuText[2].setFillColor(sf::Color::Yellow);
	menuText[2].setString("Option");
	menuText[2].setPosition(Vector2f(xPos, 120/*height / ((MAX_ITEMS) * 1)*/)); // This blows because 640 / 3 will be a decimal. got to do 1920x1080

	menuText[3].setFont(font);
	menuText[3].setFillColor(sf::Color::Yellow);
	menuText[3].setString("Exit");
	menuText[3].setPosition(Vector2f(xPos, height / ((MAX_ITEMS) * 1)));

	setColor();

}//end of menu class

menu::~menu() {
	cout << "Object menu has been destroyed." << std::endl;
}


void menu::drawMenu(RenderWindow &window) {
	for (int i = 0; i < MAX_ITEMS; i++) {
		window.draw(menuText[i]);
		window.draw(menuTitle);
	}
}//end of drawMenu()

void menu::menuStart() {
	if (menuIndex == 0) {
		menuText[menuIndex].setFillColor(sf::Color::Red);
		menuText[menuIndex].setString("[" + menuArray[menuIndex] + "]");
		
	}
}//end of menuStart()

void menu::menuUP() {
	if (menuIndex != 0 ){
		menuIndex--;
		setColor();
	}
}//end of menuUP()

void menu::menuDN() {
	if (menuIndex != MAX_ITEMS -1 ) {
		//minus 1 becaues the array slots of MAX_ITEMS is 4, and the index only reaches 3
		menuIndex++;
		setColor();
	}

}


//This will change the color of the menu items
void menu::setColor() {
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (i == menuIndex) {
			//if you are selecting the spot, aka index, make it red.
			menuText[menuIndex].setFillColor(sf::Color::Red);
			menuText[menuIndex].setString("[" + menuArray[menuIndex] + "]");
		}
		else {
			//if you are not selecting something, make it yellow
			menuText[i].setFillColor(sf::Color::Yellow);
			menuText[i].setString(menuArray[i]);
		}
	}

}//end of setColor()


void menu::menuMusicStop() {
	menuMusic.stop();
}//end of menuMusicStop

void menu::screen1Music() {
	//Loading new music for screen 1.
	if (!screen1Mus.openFromFile("res/Town3.ogg")) {
		cout << "screen1Music did not open" << std::endl;
	}

	screen1Mus.play();
	screen1Mus.setPitch(.75);
	screen1Mus.setLoop(true);
}