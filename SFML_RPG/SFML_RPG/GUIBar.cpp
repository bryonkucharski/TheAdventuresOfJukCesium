#include "GUIBar.h"
#include <sstream>
#include <iomanip>

/*
	Loads texture and font for the GUI bar. Sets the Font size and position of GUI bar
*/
GUIBar::GUIBar(RenderWindow &window, std::string textureFile, std::string fontFile) {
	this->texture.loadFromFile(textureFile);
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(Vector2f(0, 32*20));
	this->font.loadFromFile(fontFile);
	this->fontSize = 14;

	this->setUpAllRect();
}
/*
	sets the font, size, color, position, and string to the given input text;
*/
void GUIBar::setUpText(Text &input, std::string words, Vector2f pos) {
	input.setFont(font);
	input.setCharacterSize(fontSize);
	input.setFillColor(Color::White);
	input.setPosition(pos);
	input.setString(words);
}
/*
	sets the size, position, and color of given rectangle
*/
void GUIBar::createRect(RectangleShape &rectangle,Vector2f size, Vector2f pos) {
	rectangle.setSize(size);
	rectangle.setPosition(pos);
	rectangle.setFillColor(Color::Transparent);
}
/*
	creates all rectangles and positions according to the GUI Bar
*/
void GUIBar::setUpAllRect() {
	Vector2f size((5 * 32) + 8, 1 * 22);
	//creating all rectangle locations  manually
	createRect(GUILocationRect, size, Vector2f(12, (32*20) + 10));
	createRect(GUINameRect, size, Vector2f(12, (32 * 20) + 32));

	createRect(GUIPositionRect, Vector2f(5 * 32 + 8, 44), Vector2f((7*32)-20, 32*20 + 10));
	
	createRect(GUIHealthRect, size, Vector2f(12 + (12*32),(32*20) + 10));
	createRect(GUIDamageRect, size, Vector2f(12 + (12*32),(32*20) + 32));

	createRect(GUILevelRect, Vector2f((3 * 32) + 8, 1 * 22), Vector2f(12 + (18 * 32), (32 * 20) + 10));
	createRect(GUIXpRect,    Vector2f((3 * 32) + 8, 1 * 22), Vector2f(12 + (18 * 32), (32 * 20) + 32));

}
/*
	Draws everything needed for GUI bar
*/
void GUIBar::drawAll(RenderWindow &window,Player &player, World &world) {
	//draws the GUI bar background
	window.draw(this->sprite);

	//draws the rectangles for the text locations
	window.draw(this->GUILocationRect);
	window.draw(this->GUINameRect);
	window.draw(this->GUIPositionRect);
	window.draw(this->GUIHealthRect);
	window.draw(this->GUIDamageRect);
	window.draw(this->GUILevelRect);
	window.draw(this->GUIXpRect);

	//draws all the text for player/game information
	this->drawLocation(window, player,world);
	this->drawPosition(window, player);
	this->drawHealth(window, player);
	this->drawPlayerName(window, player);
	this->drawDamage(window, player);
	this->drawLevel(window, player);
	this->drawXP(window, player);
}
/*
	draws main player's name text at rectangle's position
*/
void GUIBar::drawPlayerName(RenderWindow &window, Player &player) {
	setUpText(GUIPlayerNameText, "Player: " + player.getName(), this->GUINameRect.getPosition());
	window.draw(GUIPlayerNameText);
}
/*
	draws main player's location text at rectangle's position
*/
void GUIBar::drawLocation(RenderWindow &window, Player &player, World &world) {
	setUpText(GUILocationText,"Location: " + world.getLocationString(player.getCurrentLocation()), this->GUILocationRect.getPosition());
	window.draw(GUILocationText);
}
/*
	draws main player's position text at rectangle's position
*/
void GUIBar::drawPosition(RenderWindow &window, Player &player) {
	/*converts float to string for players x and y position*/
	std::ostringstream outX, outY;
	outX << std::setprecision(3) << player.getCurrentPosition().x;
	outY << std::setprecision(3) << player.getCurrentPosition().y;

	setUpText(GUIPositionText,"Position X: " + outX.str() + "\nPosition Y: " + outY.str(), this->GUIPositionRect.getPosition());
	
	window.draw(GUIPositionText);
}
/*
	draws main player's health text at rectangle's position
*/
void GUIBar::drawHealth(RenderWindow &window, Player &player) {
	setUpText(GUIHealthText, "Health: " + std::to_string(player.getCurrentHealth()) + " / " + std::to_string(player.getMaxHealth()), this->GUIHealthRect.getPosition());
	window.draw(GUIHealthText);
}
/*
	draws main player's damage text at rectangle's position
*/
void GUIBar::drawDamage(RenderWindow &window, Player &player) {
	setUpText(GUIDamageText, "Damage: " + std::to_string(player.getDamage()), this->GUIDamageRect.getPosition());
	window.draw(GUIDamageText);
}
/*
	draws main player's level text at rectangle's position
*/
void GUIBar::drawLevel(RenderWindow &window, Player &player) {
	setUpText(GUILevelText, "Level: " + std::to_string(player.getLevel()), this->GUILevelRect.getPosition());
	window.draw(GUILevelText);
}
/*
	draws main player's damage text at rectangle's position
*/
void GUIBar::drawXP(RenderWindow &window, Player &player) {
	setUpText(GUIXpText, "Experience: " + std::to_string(player.getTotalExperience()), this->GUIXpRect.getPosition());
	window.draw(GUIXpText);
}
