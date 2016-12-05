#include "menu.h"

Menu::Menu() {
	//nothing is here
}

Menu::Menu(std::string file, std::string title, std::string music, std::string menuString[MAX_ITEMS], int textSize,Vector2f titlePosition, Vector2f startingPosition) {
	texture.loadFromFile(file);
	sprite.setTexture(texture);
	font.loadFromFile("res/Fonts/Vecna.otf");
		
	setUpMenuTitle(title,titlePosition, music, textSize * 2);

	
	setUpMenuText(menuText[0], menuString[0], Color::Yellow, textSize ,startingPosition);
	setUpArrayText(menuString);
	setUpMenuText(menuText[1], menuString[1], Color::Yellow, textSize ,Vector2f(startingPosition.x, startingPosition.y + menuText[0].getCharacterSize() ));
	setUpMenuText(menuText[2], menuString[2], Color::Yellow, textSize ,Vector2f(startingPosition.x, startingPosition.y + (2*menuText[0].getCharacterSize()) ));
	setUpMenuText(menuText[3], menuString[3], Color::Yellow, textSize ,Vector2f(startingPosition.x, startingPosition.y + (3 * menuText[0].getCharacterSize())));
	
	menuIndex = 0;

	setColor();

}//end of menu class

Menu::~Menu() {
}


void Menu::drawMenu(RenderWindow &window) {

	window.draw(this->sprite);
	window.draw(menuTitle);
	for (int i = 0; i < MAX_ITEMS; i++) {
		window.draw(menuText[i]);
	}
}//end of drawMenu()

void Menu::setUpMenuTitle(std::string title, Vector2f titlePosition, std::string music, int size) {
	//setting the title
	menuTitle.setFont(this->font);
	menuTitle.setCharacterSize(size);
	menuTitle.setFillColor(sf::Color::Black);
	menuTitle.setString(title);
	menuTitle.setPosition(titlePosition);
}

void Menu::setUpMenuText(Text &mText, std::string menuStringIndex, Color color, int size,Vector2f pos) {
	mText.setFont(this->font);
	mText.setCharacterSize(size);
	mText.setFillColor(color);
	mText.setString(menuStringIndex);
	mText.setPosition(pos);
}

void Menu::menuStart() {
	if (menuIndex == 0) {
		menuText[menuIndex].setFillColor(sf::Color::Red);
		menuText[menuIndex].setString("[" + menuArray[menuIndex] + "]");

	}
}//end of menuStart()

void Menu::menuUP() {
	if (menuIndex != 0) {
		menuIndex--;
		setColor();
	}
}//end of menuUP()

void Menu::menuDN() {
	if (menuIndex != MAX_ITEMS - 1) {
		//minus 1 becaues the array slots of MAX_ITEMS is 4, and the index only reaches 3
		menuIndex++;
		setColor();
	}

}


//This will change the color of the menu items
void Menu::setColor() {
	for (int i = 0; i < MAX_ITEMS; i++) {
		if (i == menuIndex) {
			//if you are selecting the spot, aka index, make it red.
			menuText[menuIndex].setFillColor(sf::Color::Red);
			menuText[menuIndex].setString("[" + menuArray[menuIndex] + "]");
		}
		else {
			//if you are not selecting something, make it yellow
			menuText[i].setFillColor(sf::Color::Yellow);
			menuText[i].setString( menuArray[i] );
		}
	}

}//end of setColor()


void Menu::menuMusicStop() {
	//menuMusic.stop();
}//end of menuMusicStop

void Menu::menuMusicStart() {
	//menuMusic.play();
	//menuMusic.setPitch(.55);
	//cool pitch {.3, .5, .8}
	//A pitch of 1 is standard speed, pitch more than 1 is sped up. less than 1 && greater than 0 is slowed down.
	//menuMusic.setLoop(true);
}//end of menuMusicStart
int Menu::selectOption() {
	
	selectionTime = selectionClock.getElapsedTime();
	
	if ( (Keyboard::isKeyPressed(Keyboard::Up)) && (selectionTime.asSeconds() > .18) || (Keyboard::isKeyPressed(Keyboard::W)) && (selectionTime.asSeconds() > .18) ) {
		menuUP();
		selectionClock.restart();
	}
	else if ((Keyboard::isKeyPressed(Keyboard::Down)) && (selectionTime.asSeconds() > .18) || (Keyboard::isKeyPressed(Keyboard::S)) && (selectionTime.asSeconds() > .18)) {
		menuDN();
		selectionClock.restart();
	}
	else if ((Keyboard::isKeyPressed(Keyboard::Return)) && (selectionTime.asSeconds() > .18) || (Keyboard::isKeyPressed(Keyboard::LShift)) && (selectionTime.asSeconds() > .18)) {
		return menuIndex;
	}
	return -1;
}

void Menu::setUpArrayText(std::string givenText[MAX_ITEMS]) {
	for (int i = 0; i < MAX_ITEMS; i++) {
		this->menuArray[i] = givenText[i];
	}
}


