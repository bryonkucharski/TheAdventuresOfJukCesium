
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>
#include "Entity.h"

#define cout std::cout
using namespace sf;

#define MAX_ITEMS 4

class Menu : public Entity {
private:
	int menuIndex;
	Text menuText[MAX_ITEMS];
	Text menuTitle;
	//Music menuMusic;
	//Music screen1Mus;
	std::string menuArray[4];
	Text test;

	Time selectionTime;
	Clock selectionClock;

	void setUpMenuTitle(std::string title, Vector2f titlePosition, std::string music, int size);
	void setUpMenuText(Text &menuText, std::string menuStringIndex, Color color, int size, Vector2f pos);
	void setUpArrayText(std::string givenText[MAX_ITEMS]);

	void menuUP();
	void menuDN();
	void menuStart();
	void setColor();
	void menuMusicStart();
	void menuMusicStop();


public:
	Menu(std::string file, std::string title, std::string music, std::string menuString[MAX_ITEMS], int textSize, Vector2f titlePosition, Vector2f startingPosition);
	~Menu();
	Menu();

	int selectOption();
	void drawMenu(RenderWindow &window);


	

};//end of class menu