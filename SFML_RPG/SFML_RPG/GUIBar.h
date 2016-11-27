#ifndef GUIBar_H
#define GUIBar_H

#include "Entity.h"
#include "Player.h"

class GUIBar : public Entity
{
	public:
		GUIBar(RenderWindow &window, std::string textureFile, std::string fontFile);
		~GUIBar() {};
		void drawAll(RenderWindow &window, Player &player, World &world);

	private:
		Font font;
		int fontSize;

		Text GUILocationText;
		Text GUIPositionText;
		Text GUIHealthText;
		Text GUIPlayerNameText;
		Text GUIDamageText;
		Text GUILevelText;
		Text GUIXpText;

		RectangleShape GUILocationRect;
		RectangleShape GUIPositionRect;
		RectangleShape GUIHealthRect;
		RectangleShape GUINameRect;
		RectangleShape GUIDamageRect;
		RectangleShape GUILevelRect;
		RectangleShape GUIXpRect;

		void setUpText(Text &input, std::string words, Vector2f pos);
		void createRect(RectangleShape &rectangle, Vector2f size, Vector2f pos);
		void setUpAllRect();

		/*USED pass by reference because pass by value caused major performance issues*/
		void drawHealth(RenderWindow &window, Player &player);
		void drawLevel(RenderWindow &window, Player &player);
		void drawXP(RenderWindow &window, Player &player);
		void drawDamage(RenderWindow &window, Player &player);
		void drawLocation(RenderWindow &window, Player &player, World &world);
		void drawPosition(RenderWindow &window, Player &player);
		void drawPlayerName(RenderWindow &window, Player &player);
};
#endif // !GUIBar_H
