#include "World.h"

#define PIXEL_SIZE 32
World::World() {
};
World::World(RenderWindow &window) {
	

	home = *new Location("Home Neighborhood", "res/Locations/home.png", 1, 2, 3, 4, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	town1 = *new Location("Mill Creek", "res/Locations/Town1.png", 2, 4, 3, 1, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	bigHouseInterior = *new Location("Home Sweet Home", "res/Locations/BigHouseInterior.png", 3, 1, 1, 1, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));forest = *new Location("Hollow Forest", "res/Locations/Forest1.png", 4, 1, 2, 1, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	forest = *new Location("Hollow Forest", "res/Locations/Forest1.png", 4, 1, 2, 1, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));

	this->setupHome(window);
	this->setupBigHouse();
	this->setupForest();
	this->setupTown();
}
Location & World::getLocation(int requested) {
	switch (requested) {
		case 1:
			return home;
		case 2:
			return town1;
		case 3:
			return bigHouseInterior;
		case 4:
			return forest;
		default:
			return home;

	};
}
string World::getLocationString(int requested) {
	switch (requested) {
	case 1:
		return home.getName();
	case 2:
		return town1.getName();
	case 3:
		return bigHouseInterior.getName();
	case 4:
		return forest.getName();
	default:
		return home.getName();

	};
}

void World::drawWorld(RenderWindow &window, Location &toDraw) {
	window.clear();
	window.draw(toDraw.getSprite());

	//draw all obstacles
	int counter = 0;
	for (std::vector<RectangleShape>::iterator obsIter = toDraw.getObstacles().begin(); obsIter != toDraw.getObstacles().end(); ++obsIter)
	{
		window.draw(toDraw.getObstacles()[counter]);
		counter++;
	}

	//draw all location changes
	int counter2 = 0;
	for (std::vector<RectangleShape>::iterator locIter = toDraw.getLocationChanges().begin(); locIter != toDraw.getLocationChanges().end(); ++locIter)
	{
		window.draw(toDraw.getLocationChanges()[counter2]);
		counter2++;
	}

}

void World::setupHome(RenderWindow &window) {

	/*Add ALL obstacles for HOME*/

	RectangleShape house(Vector2f(6 * PIXEL_SIZE, 4 * PIXEL_SIZE));
	house.setPosition(Vector2f(32, 0));
	house.setFillColor(Color::Transparent);

	RectangleShape trees(Vector2f(10 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	trees.setPosition(Vector2f(PIXEL_SIZE * 19, 0));
	trees.setFillColor(Color::Transparent);

	//Building the big house MH
	RectangleShape bigHouse1(Vector2f(5 * PIXEL_SIZE, 9 * PIXEL_SIZE));
	bigHouse1.setPosition(Vector2f(PIXEL_SIZE * 11, PIXEL_SIZE * 9));
	bigHouse1.setFillColor(Color::Transparent);
	RectangleShape bigHouse2(Vector2f(1 * PIXEL_SIZE, 7 * PIXEL_SIZE));
	bigHouse2.setPosition(Vector2f(PIXEL_SIZE * 16, PIXEL_SIZE * 9));
	bigHouse2.setFillColor(Color::Transparent);
	RectangleShape bigHouse3(Vector2f(1 * PIXEL_SIZE, 6 * PIXEL_SIZE));
	bigHouse3.setPosition(Vector2f(PIXEL_SIZE * 17, PIXEL_SIZE * 9));
	bigHouse3.setFillColor(Color::Transparent);
	RectangleShape bigHouse4(Vector2f(1 * PIXEL_SIZE, 7 * PIXEL_SIZE));
	bigHouse4.setPosition(Vector2f(PIXEL_SIZE * 18, PIXEL_SIZE * 9));
	bigHouse4.setFillColor(Color::Transparent);
	RectangleShape bigHouse5(Vector2f(5 * PIXEL_SIZE, 9 * PIXEL_SIZE));
	bigHouse5.setPosition(Vector2f(PIXEL_SIZE * 19, PIXEL_SIZE * 9));
	bigHouse5.setFillColor(Color::Transparent);


	//Add the shape to the obstacle list
	home.addToObstacles(house);
	home.addToObstacles(trees);
	home.addToObstacles(bigHouse1);
	home.addToObstacles(bigHouse2);
	home.addToObstacles(bigHouse3);
	home.addToObstacles(bigHouse4);
	home.addToObstacles(bigHouse5);

	/*Add ALL location changes for HOME*/
	RectangleShape next1(Vector2f(PIXEL_SIZE * 1, PIXEL_SIZE * 4));
	next1.setPosition(Vector2f(0, PIXEL_SIZE * 8));
	next1.setFillColor(Color::Blue);

	RectangleShape next2(Vector2f(PIXEL_SIZE * 1, PIXEL_SIZE * 1));
	next2.setPosition(Vector2f(PIXEL_SIZE * 17, PIXEL_SIZE * 15));
	next2.setFillColor(Color::Red);

	RectangleShape next3(Vector2f(PIXEL_SIZE * 1, PIXEL_SIZE * 4));
	next3.setPosition(Vector2f(PIXEL_SIZE * 29, PIXEL_SIZE * 8));
	next3.setFillColor(Color::Yellow);

	home.addToLocationChanges(next1);
	home.addToLocationChanges(next2);
	home.addToLocationChanges(next3);


}
void World::setupBigHouse() {

	//Add ALL location changes for HOMEzzzz
	RectangleShape next1(Vector2f(PIXEL_SIZE * 2, PIXEL_SIZE * 1));
	next1.setPosition(Vector2f(PIXEL_SIZE * 14, PIXEL_SIZE * 14));
	next1.setFillColor(Color::Blue);

	bigHouseInterior.addToLocationChanges(next1);
}
void World::setupForest() {
	RectangleShape next1(Vector2f(PIXEL_SIZE * 3, PIXEL_SIZE * 1));
	next1.setPosition(Vector2f(PIXEL_SIZE * 17, PIXEL_SIZE * 0));
	next1.setFillColor(Color::Blue);

	RectangleShape next2(Vector2f(PIXEL_SIZE * 1, PIXEL_SIZE * 3));
	next2.setPosition(Vector2f(PIXEL_SIZE * 29, PIXEL_SIZE * 11));
	next2.setFillColor(Color::Red);

	forest.addToLocationChanges(next1);
	forest.addToLocationChanges(next2);
}
void World::setupTown() {
	RectangleShape next1(Vector2f(PIXEL_SIZE * 1, PIXEL_SIZE * 2));
	next1.setPosition(Vector2f(0, PIXEL_SIZE * 12));
	next1.setFillColor(Color::Blue);

	RectangleShape next2(Vector2f(PIXEL_SIZE * 2, PIXEL_SIZE * 1));
	next2.setPosition(Vector2f(PIXEL_SIZE * 12, PIXEL_SIZE * 19));
	next2.setFillColor(Color::Red);

	RectangleShape next3(Vector2f(PIXEL_SIZE * 1, PIXEL_SIZE * 2));
	next3.setPosition(Vector2f(PIXEL_SIZE * 29, PIXEL_SIZE * 12));
	next3.setFillColor(Color::Yellow);

	town1.addToLocationChanges(next1);
	town1.addToLocationChanges(next2);
	town1.addToLocationChanges(next3);

}
void World::createRectangle(RectangleShape &rectangle, Vector2f rectSize, Vector2f rectPosition, Color rectColor) {
	rectangle.setSize(rectSize);
	rectangle.setPosition(rectPosition);
	rectangle.setFillColor(rectColor);
	

}