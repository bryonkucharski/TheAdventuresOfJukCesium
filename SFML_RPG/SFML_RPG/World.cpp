#include "World.h"

#define PIXEL_SIZE 32

World::World(RenderWindow &window) {
	home.setFileName("res/Locations/home.png");
	home.setName("Home Sweet Home");

	this->setupHome(window);
	
}

void World::drawWorld(RenderWindow &window) {

	window.draw(home.getSprite());

	//draw all obstacles
	int counter = 0;
	for (std::vector<RectangleShape>::iterator obsIter = home.getObstacles().begin(); obsIter != home.getObstacles().end(); ++obsIter)
	{
		window.draw(home.getObstacles()[counter]);
		counter++;
	}
	
}
void World::setHome(Location& h) {
	this->home = h;
}
Location& World::getHome() {
	return home;
}
void World::setupHome(RenderWindow &window) {
	home.setup();

	RectangleShape house(Vector2f(6 * PIXEL_SIZE, 4 * PIXEL_SIZE));
	house.setPosition(Vector2f(32, 0));
	house.setFillColor(Color::Transparent);

	RectangleShape trees(Vector2f(10 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	trees.setPosition(Vector2f(PIXEL_SIZE * 19, 0));
	trees.setFillColor(Color::Transparent);

	RectangleShape bigHouse(Vector2f(10 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	trees.setPosition(Vector2f(PIXEL_SIZE * 19, 0));
	trees.setFillColor(Color::Transparent);

	home.addToObstacles(house);
	home.addToObstacles(trees);
}