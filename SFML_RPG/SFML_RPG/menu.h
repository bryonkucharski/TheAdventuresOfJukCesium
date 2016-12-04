#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#define cout std::cout
using namespace sf;

#define MAX_ITEMS 4

class Menu {
private:
	int menuIndex = 0;
	Font font;
	Text menuText[MAX_ITEMS];
	Text menuTitle;

public:
	Menu(double width, double height);
	~Menu();
	Menu();


	Music menuMusic;
	Music screen1Mus;
	String menuArray[4] = { "Play", "Load", "Options", "Exit" };
	void drawMenu(RenderWindow &window);
	void menuUP();
	void menuDN();
	void menuStart();
	void setColor();
	void menuMusicStop();
	void screen1Music();
	void displayMenu();

};//end of class menu