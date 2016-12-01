#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace sf;

class Entity {

	public:
		RectangleShape&  getRect();
		Sprite& getSprite();
		Text& getText();
		Texture& getTexture();
		Font& getFont();

	protected:
		RectangleShape rect;
		Sprite sprite;
		Font font;
		Text text;
		Texture texture;
	
};

#endif // !ENTITY_H
