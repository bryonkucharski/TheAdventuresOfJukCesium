#include "World.h"

#define COLOR Color::Red

#define PIXEL_SIZE 32
World::World() {
};
World::World(RenderWindow &window) {
	


	//town1 = *new Location("Mill Creek", "res/Locations/Town1.png", 2, 4, 3, 1, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	beach = *new Location("Home Neighborhood", "res/Locations/beach.png", 5, 4, 6, 0, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	bigHouseInterior = *new Location("Home Sweet Home", "res/Locations/BigHouseInterior.png", 2, 1, 0, 0, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	castle = *new Location("Home Neighborhood", "res/Locations/castle.png", 10, 8, 0, 0, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	forest = *new Location("Hollow Forest", "res/Locations/Forest1.png", 3, 4, 8, 1, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	forest2 = *new Location("Hollow Forest", "res/Locations/forest2.png", 4, 5, 3, 0, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	ghostShed = *new Location("Hollow Forest", "res/Locations/ghostShed.png", 13, 12, 0, 0, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	graveyard = *new Location("Hollow Forest", "res/Locations/Graveyard.png", 12, 11, 13, 0, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	home = *new Location("Home Neighborhood", "res/Locations/home.png", 1, 3, 11, 2, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	market = *new Location("Hollow Forest", "res/Locations/market.png", 11, 1, 12, 0, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	pub = *new Location("Hollow Forest", "res/Locations/pub.png", 9, 8, 0, 0, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	townAroundCastle = *new Location("Hollow Forest", "res/Locations/townAroundCastle.png", 8, 3, 9, 10, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	waterfall = *new Location("Hollow Forest", "res/Locations/waterfall.png", 6, 5, 14, 14, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	WFbossRoom = *new Location("Hollow Forest", "res/Locations/WFbossRoom.png", 7, 14, 0, 0, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
	WFcorridor = *new Location("Hollow Forest", "res/Locations/WFcorridor.png", 14, 6, 6, 7, 0, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));


	this->setupHome(window);
	this->setupBigHouse();
	this->setupForest();
	this->setupForest2();
	//this->setupTown();
	this->setupBeach();
	this->setupWaterfall();
	this->setupWFbossRoom();
	this->setupTownAroundCastle();
	this->setupPub();
	this->setupCastle();
	this->setupGraveyard();
	this->setupGhostShed();
	this->setupWFcorridor();
}
Location & World::getLocation(int requested) {
	switch (requested) {
		case 1:
			return home;
		case 2:
			return bigHouseInterior;
		case 3:
			return forest;
		case 4:
			return forest2;
		case 5:
			return beach;
		case 6:
			return waterfall;
		case 7:
			return WFbossRoom;
		case 8:
			return townAroundCastle;
		case 9:
			return pub;
		case 10:
			return castle;
		case 11:
			return market;
		case 12:
			return graveyard;
		case 13:
			return ghostShed;
		case 14:
			return WFcorridor;
		default:
			return home;

	};
}
string World::getLocationString(int requested) {
	switch (requested) {
	case 1:
		return home.getName();
	case 2:
		return bigHouseInterior.getName();
	case 3:
		return forest.getName();
	case 4:
		return forest2.getName();
	case 5:
		return beach.getName();
	case 6:
		return waterfall.getName();
	case 7:
		return WFbossRoom.getName();
	case 8:
		return townAroundCastle.getName();
	case 9:
		return pub.getName();
	case 10:
		return castle.getName();
	case 11:
		return market.getName();
	case 12:
		return graveyard.getName();
	case 13:
		return ghostShed.getName();
	case 14:
		return WFcorridor.getName();
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
	//making the small house
	RectangleShape house1(Vector2f(4 * PIXEL_SIZE, 4 * PIXEL_SIZE));
	house1.setPosition(Vector2f(1 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	house1.setFillColor(Color::Transparent);
	RectangleShape house2(Vector2f(2 * PIXEL_SIZE, 3 * PIXEL_SIZE));
	house2.setPosition(Vector2f(5 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	house2.setFillColor(Color::Transparent);
	RectangleShape house3(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	house3.setPosition(Vector2f(6 * PIXEL_SIZE, 3 * PIXEL_SIZE));
	house3.setFillColor(Color::Transparent);


	//making trees
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

	//water well fence area
	RectangleShape well1(Vector2f(5 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	well1.setPosition(Vector2f(8 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	well1.setFillColor(Color::Transparent);
	RectangleShape well2(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	well2.setPosition(Vector2f(8 * PIXEL_SIZE, 3 * PIXEL_SIZE));
	well2.setFillColor(Color::Transparent);
	RectangleShape well3(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	well3.setPosition(Vector2f(8 * PIXEL_SIZE, 2 * PIXEL_SIZE));
	well3.setFillColor(Color::Transparent);

	//house sign
	RectangleShape sign(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	sign.setPosition(Vector2f(6 * PIXEL_SIZE, 4 * PIXEL_SIZE));
	sign.setFillColor(Color::Transparent);

	//momument
	RectangleShape monument(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE));
	monument.setPosition(Vector2f(11 * PIXEL_SIZE, 4 * PIXEL_SIZE));
	monument.setFillColor(Color::Transparent);

	//big house fence
	RectangleShape fence1(Vector2f(1 * PIXEL_SIZE, 8 * PIXEL_SIZE));
	fence1.setPosition(Vector2f(9 * PIXEL_SIZE, 8 * PIXEL_SIZE));
	fence1.setFillColor(Color::Transparent);
	RectangleShape fence2(Vector2f(15 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	fence2.setPosition(Vector2f(10 * PIXEL_SIZE, 8 * PIXEL_SIZE));
	fence2.setFillColor(Color::Transparent);
	RectangleShape fence3(Vector2f(1 * PIXEL_SIZE, 10 * PIXEL_SIZE));
	fence3.setPosition(Vector2f(25 * PIXEL_SIZE, 8 * PIXEL_SIZE));
	fence3.setFillColor(Color::Transparent);

	//Add the shape to the obstacle list
	home.addToObstacles(house1);
	home.addToObstacles(house2);
	home.addToObstacles(house3);
	home.addToObstacles(trees);
	home.addToObstacles(bigHouse1);
	home.addToObstacles(bigHouse2);
	home.addToObstacles(bigHouse3);
	home.addToObstacles(bigHouse4);
	home.addToObstacles(bigHouse5);
	home.addToObstacles(well1);
	home.addToObstacles(well2);
	home.addToObstacles(well3);
	home.addToObstacles(sign);
	home.addToObstacles(monument);
	home.addToObstacles(fence1);
	home.addToObstacles(fence2);
	home.addToObstacles(fence3);


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

	RectangleShape next4(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	next4.setPosition(Vector2f(5 * PIXEL_SIZE, 3 * PIXEL_SIZE));
	next4.setFillColor(Color::Yellow);

	//change location submisison area
	home.addToLocationChanges(next1);
	home.addToLocationChanges(next2);
	home.addToLocationChanges(next3);
	home.addToLocationChanges(next4);//This is not initialized. So so dont go into the yellow square.

}
void World::setupBigHouse() {
	//make obstacles
	//topWall
	RectangleShape topWall(Vector2f(26 * PIXEL_SIZE, 3 * PIXEL_SIZE));
	topWall.setPosition(Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE));
	topWall.setFillColor(Color::Transparent);
	//bc = Book case
	RectangleShape bc(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	bc.setPosition(Vector2f(10 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	bc.setFillColor(Color::Transparent);
	//item1 spears and cabinet
	RectangleShape item1(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	item1.setPosition(Vector2f(16 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	item1.setFillColor(Color::Transparent);
	//i2 = single lower cabinet
	RectangleShape i2(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i2.setPosition(Vector2f(19 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	i2.setFillColor(Color::Transparent);
	//i3 = storage crates
	RectangleShape i3(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i3.setPosition(Vector2f(22 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	i3.setFillColor(Color::Transparent);
	//i4 = solo storage crate
	RectangleShape i4(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i4.setPosition(Vector2f(26 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	i4.setFillColor(Color::Transparent);
	//i5 = left kitchen table
	RectangleShape i5(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i5.setPosition(Vector2f(3 * PIXEL_SIZE, 6 * PIXEL_SIZE));
	i5.setFillColor(Color::Transparent);
	//i6 = white table near pink cusions
	RectangleShape i6(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i6.setPosition(Vector2f(11 * PIXEL_SIZE, 8 * PIXEL_SIZE));
	i6.setFillColor(Color::Transparent);
	//i7 = table with white plates
	RectangleShape i7(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i7.setPosition(Vector2f(17 * PIXEL_SIZE, 8 * PIXEL_SIZE));
	i7.setFillColor(Color::Transparent);
	//i8 = table with vase and lower part of big red chair
	RectangleShape i8(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i8.setPosition(Vector2f(23 * PIXEL_SIZE, 9 * PIXEL_SIZE));
	i8.setFillColor(Color::Transparent);
	//i9 = top of big red chair
	RectangleShape i9(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i9.setPosition(Vector2f(24 * PIXEL_SIZE, 8 * PIXEL_SIZE));
	i9.setFillColor(Color::Transparent);
	//i10 = bed side table and top of bed and some of the wall
	RectangleShape i10(Vector2f(6 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i10.setPosition(Vector2f(8 * PIXEL_SIZE, 12 * PIXEL_SIZE));
	i10.setFillColor(Color::Transparent);
	//i11 = entrance wall right
	RectangleShape i11(Vector2f(4 * PIXEL_SIZE, 3 * PIXEL_SIZE));
	i11.setPosition(Vector2f(16 * PIXEL_SIZE, 12 * PIXEL_SIZE));
	i11.setFillColor(Color::Transparent);
	//i12 = interior wall
	RectangleShape i12(Vector2f(1 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	i12.setPosition(Vector2f(8 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	i12.setFillColor(Color::Transparent);
	//i13 = interior wall2
	RectangleShape i13(Vector2f(2 * PIXEL_SIZE, 3 * PIXEL_SIZE));
	i13.setPosition(Vector2f(6 * PIXEL_SIZE, 7 * PIXEL_SIZE));
	i13.setFillColor(Color::Transparent);
	//i14 = right dinner table below red chair
	RectangleShape i14(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i14.setPosition(Vector2f(23 * PIXEL_SIZE, 12 * PIXEL_SIZE));
	i14.setFillColor(Color::Transparent);
	//i15 = right dinner table below red chair
	RectangleShape i15(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i15.setPosition(Vector2f(24 * PIXEL_SIZE, 13 * PIXEL_SIZE));
	i15.setFillColor(Color::Transparent);
	//i16 = money boxes
	RectangleShape i16(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE));
	i16.setPosition(Vector2f(20 * PIXEL_SIZE, 13 * PIXEL_SIZE));
	i16.setFillColor(Color::Transparent);
	//i17 = right bottom wall
	RectangleShape i17(Vector2f(9 * PIXEL_SIZE, 3 * PIXEL_SIZE));
	i17.setPosition(Vector2f(19 * PIXEL_SIZE, 15 * PIXEL_SIZE));
	i17.setFillColor(Color::Transparent);
	//i18 = gold ingots
	RectangleShape i18(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i18.setPosition(Vector2f(26 * PIXEL_SIZE, 14 * PIXEL_SIZE));
	i18.setFillColor(Color::Transparent);
	//i19 = lower bed
	RectangleShape i19(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i19.setPosition(Vector2f(9 * PIXEL_SIZE, 13 * PIXEL_SIZE));
	i19.setFillColor(Color::Transparent);
	//i20 = left entrance wall
	RectangleShape i20(Vector2f(4 * PIXEL_SIZE, 2 * PIXEL_SIZE));
	i20.setPosition(Vector2f(10 * PIXEL_SIZE, 13 * PIXEL_SIZE));
	i20.setFillColor(Color::Transparent);
	//i21 = Right house wall
	RectangleShape i21(Vector2f(1 * PIXEL_SIZE, 10 * PIXEL_SIZE));
	i21.setPosition(Vector2f(27 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	i21.setFillColor(Color::Transparent);
	//i22 = left house wall
	RectangleShape i22(Vector2f(1 * PIXEL_SIZE, 10 * PIXEL_SIZE));
	i22.setPosition(Vector2f(2 * PIXEL_SIZE, 5 * PIXEL_SIZE));
	i22.setFillColor(Color::Transparent);
	//i23 = left down house wall
	RectangleShape i23(Vector2f(9 * PIXEL_SIZE, 3 * PIXEL_SIZE));
	i23.setPosition(Vector2f(2 * PIXEL_SIZE, 15 * PIXEL_SIZE));
	i23.setFillColor(Color::Transparent);
	//i24 = left table below kitchen left of small bed
	RectangleShape i24(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE));
	i24.setPosition(Vector2f(6 * PIXEL_SIZE, 14 * PIXEL_SIZE));
	i24.setFillColor(Color::Transparent);
	
	//makes a rectangle, size of rectangle, location of rectangle, color, and location.
	//createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Blue, bigHouseInterior);

	//add obstacles to list
	bigHouseInterior.addToObstacles(topWall);
	bigHouseInterior.addToObstacles(bc);
	bigHouseInterior.addToObstacles(item1);
	bigHouseInterior.addToObstacles(i2);
	bigHouseInterior.addToObstacles(i3);
	bigHouseInterior.addToObstacles(i4);
	bigHouseInterior.addToObstacles(i5);
	bigHouseInterior.addToObstacles(i6);
	bigHouseInterior.addToObstacles(i7);
	bigHouseInterior.addToObstacles(i8);
	bigHouseInterior.addToObstacles(i9);
	bigHouseInterior.addToObstacles(i10);
	bigHouseInterior.addToObstacles(i11);
	bigHouseInterior.addToObstacles(i12);
	bigHouseInterior.addToObstacles(i13);
	bigHouseInterior.addToObstacles(i14);
	bigHouseInterior.addToObstacles(i15);
	bigHouseInterior.addToObstacles(i16);
	bigHouseInterior.addToObstacles(i17);
	bigHouseInterior.addToObstacles(i18);
	bigHouseInterior.addToObstacles(i19);
	bigHouseInterior.addToObstacles(i20);
	bigHouseInterior.addToObstacles(i21);
	bigHouseInterior.addToObstacles(i22);
	bigHouseInterior.addToObstacles(i23);
	bigHouseInterior.addToObstacles(i24);
	//bigHouseInterior.addToObstacles(i25);

	//Add ALL location changes for bigHouseInterior
	RectangleShape next1(Vector2f(PIXEL_SIZE * 2, PIXEL_SIZE * 1));
	next1.setPosition(Vector2f(PIXEL_SIZE * 14, PIXEL_SIZE * 14));
	next1.setFillColor(Color::Blue);

	//Add change locations to the list.
	bigHouseInterior.addToLocationChanges(next1);
}


void World::setupForest() {
	//Rectangles to add to the map
	//rectnangle, size, location, color, location name.
	createObstacleRectangle(RectangleShape(), Vector2f(3 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(4 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 6 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(9 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(7 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(3 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 7 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 6 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(15 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(23 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(11 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE - 16, 1 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE + 16, 6 * PIXEL_SIZE), Color::Transparent, forest);//unique top of the tent's roof
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(3 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(2 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 19 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, forest);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, forest);
	
	//location change rectangles
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Yellow, forest);
	createLocationRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Yellow, forest);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Yellow, forest);

}
void World::setupTown() {
	/*
	// rectangle, size, location, color, name
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE - 31, 3 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE - 31), Vector2f(12 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(3 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(3 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE - 16, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 2* PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(23 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Blue, town1);
	createObstacleRectangle(RectangleShape(), Vector2f(4 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Blue, town1);


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
	*/
}

void World::setupForest2() {
	//creating obstacles
	//createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 8 * PIXEL_SIZE + 1), Color::Blue, forest2);


	//creating locations changes
	createLocationRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 19 * PIXEL_SIZE), Color::Red, forest2);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Red, forest2);
}
void World::setupBeach() {





}
void World::setupWaterfall() {






}
void World::setupWFbossRoom() {






}
void World::setupTownAroundCastle() {






}
void World::setupPub() {






}
void World::setupCastle() {






}
void World::setupMarket() {






}
void World::setupGraveyard() {






}
void World::setupGhostShed() {






}
void World::setupWFcorridor(){






}


void World::createObstacleRectangle(RectangleShape &rectangle, Vector2f rectSize, Vector2f rectPosition, Color rectColor, Location &loc) {
	rectangle.setSize(rectSize);
	rectangle.setPosition(rectPosition);
	rectangle.setFillColor(rectColor);
	//we should also add this rectangle to the add to obstacles list too.
	loc.addToObstacles(rectangle);

}

void World::createLocationRectangle(RectangleShape &rectangle, Vector2f rectSize, Vector2f rectPosition, Color rectColor, Location &loc) {
	rectangle.setSize(rectSize);
	rectangle.setPosition(rectPosition);
	rectangle.setFillColor(rectColor);
	//we should also add this rectangle to the add to obstacles list too.
	loc.addToLocationChanges(rectangle);
}

void World::createLocationRectangle(Vector2f rectSize, Vector2f rectPosition, Color rectColor, Location &loc) {
	//uses this one
	RectangleShape rectangle;
	rectangle.setSize(rectSize);
	rectangle.setPosition(rectPosition);
	rectangle.setFillColor(rectColor);
	//we should also add this rectangle to the add to obstacles list too.
	loc.addToLocationChanges(rectangle);
}

void World::createObstacleRectangle(Vector2f rectSize, Vector2f rectPosition, Color rectColor, Location &loc) {
	//use this one
	RectangleShape rectangle;
	rectangle.setSize(rectSize);
	rectangle.setPosition(rectPosition);
	rectangle.setFillColor(rectColor);
	//we should also add this rectangle to the add to obstacles list too.
	loc.addToObstacles(rectangle);
}
