#include "World.h"

#define COLOR Color::Red

#define PIXEL_SIZE 32
World::World() {}
World::~World() {}

World::World(RenderWindow &window) {
	beach = *new Location("Beach", "res/Locations/beach.png", 5, 4, 6, 15, 0, Vector2f(11 * PIXEL_SIZE, 18 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 6 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	bigHouseInterior = *new Location("Home Sweet Home", "res/Locations/BigHouseInterior.png", 2, 1, 0, 0, 0, Vector2f(17 * PIXEL_SIZE, 17 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	castle = *new Location("Royal Palace", "res/Locations/castle.png", 10, 8, 0, 0, 0, Vector2f(14 * PIXEL_SIZE, 11 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	forest = *new Location("Hollow Forest", "res/Locations/Forest1.png", 3, 4, 8, 1, 0, Vector2f(28 * PIXEL_SIZE, 8 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 18 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 9 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	forest2 = *new Location("Klowers Grove", "res/Locations/forest2.png", 4, 5, 3, 0, 0, Vector2f(14 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 7 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	ghostShed = *new Location("Abandoned Shed", "res/Locations/ghostShed.png", 13, 12, 0, 0, 0, Vector2f(27 * PIXEL_SIZE, 11 * PIXEL_SIZE+6), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	graveyard = *new Location("Graveyard", "res/Locations/Graveyard.png", 12, 11, 13, 0, 0, Vector2f(12 * PIXEL_SIZE, 18 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 17 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	home = *new Location("Home Neighborhood", "res/Locations/home.png", 1, 3, 2, 11, 0, Vector2f(28 * PIXEL_SIZE, 11 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 13 * PIXEL_SIZE), Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	market = *new Location("Centeral Square", "res/Locations/market.png", 11, 1, 12, 0, 0, Vector2f(17 * PIXEL_SIZE, 18 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	pub = *new Location("Hunter's Pub", "res/Locations/pub.png", 9, 8, 0, 0, 0, Vector2f(3 * PIXEL_SIZE, 10 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	townAroundCastle = *new Location("Warthford", "res/Locations/townAroundCastle.png", 8, 3, 9, 10, 0, Vector2f(18 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 17 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 16 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	waterfall = *new Location("Mine Falls", "res/Locations/waterfall.png", 6, 5, 14, 14, 0, Vector2f(6 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 15 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 9 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	WFbossRoom = *new Location("Shadow's Lair", "res/Locations/WFbossRoom.png", 7, 14, 0, 0, 0, Vector2f(19 * PIXEL_SIZE, 18 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	WFcorridor = *new Location("Shadow's Corfidor", "res/Locations/WFcorridor.png", 14, 6, 6, 7, 0, Vector2f(4 * PIXEL_SIZE, 14 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));
	port = *new Location("Port Sarim", "res/Locations/port.png", 15, 5, 0, 0, 0, Vector2f(24 * PIXEL_SIZE, 8 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE));

	this->setupHome();
	this->setupBigHouse();
	this->setupForest();
	this->setupForest2();
	this->setupBeach();
	this->setupWaterfall();
	this->setupWFbossRoom();
	this->setupTownAroundCastle();
	this->setupMarket();
	this->setupPub();
	this->setupCastle();
	this->setupGraveyard();
	this->setupGhostShed();
	this->setupWFcorridor();
	this->setupPort();
}//end of world constructor

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
		case 15:
			return port;
		default:
			return home;
	};
}//end of getLocation()

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
	case 15:
		return port.getName();
	default:
		return home.getName();

	};
}//end of getLocationString()

void World::drawWorld(RenderWindow &window, Location &toDraw) {
	window.clear();
	window.draw(toDraw.getSprite());

	//draw all obstacles
	int counter = 0;
	for (std::vector<RectangleShape>::iterator obsIter = toDraw.getObstacles().begin(); obsIter != toDraw.getObstacles().end(); ++obsIter){
		window.draw(toDraw.getObstacles()[counter]);
		counter++;
	}

	//draw all location changes
	int counter2 = 0;
	for (std::vector<RectangleShape>::iterator locIter = toDraw.getLocationChanges().begin(); locIter != toDraw.getLocationChanges().end(); ++locIter){
		window.draw(toDraw.getLocationChanges()[counter2]);
		counter2++;
	}
}//end of drawWorld

void World::setupHome() {	
	//obstacles
	this->createBorder(home);

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

	createLocationRectangle(Vector2f(1*PIXEL_SIZE, 4* PIXEL_SIZE), Vector2f(0*PIXEL_SIZE,8*PIXEL_SIZE), Color::Transparent, home);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, home);
	createLocationRectangle(Vector2f(4 * PIXEL_SIZE, 16), Vector2f(15 * PIXEL_SIZE, (19 * PIXEL_SIZE) + 16), Color::Transparent, home);
	
	//Enemies
	//createTestEnemies();

	//Create Boss
	// int AI_ID, int aiShoot, int health, int level,
	//this->createBoss("res/Creatures/bigRedMonster.png", "A Femenist", /*AI_ID*/ 7, /*aiShoot*/ 3, /*Health*/ 360, /*Level*/ 5, /*Location*/ Vector2f(24 * PIXEL_SIZE, 11 * PIXEL_SIZE), home, /*PixelSize*/ Vector2f(80,80));

	//NPC's
	this->createNPC("res/Creatures/oldMan.png", "Old Man Jensen", "Kill The Monsters!", /*AI_ID*/2, Vector2f(17 * PIXEL_SIZE, 5 * PIXEL_SIZE), home);

}//end of home

void World::setupBigHouse() {
	//make obstacles
	this->createBorder(bigHouseInterior);
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
	
	//Location Change
	RectangleShape next1(Vector2f(PIXEL_SIZE * 2, PIXEL_SIZE * 1));
	next1.setPosition(Vector2f(PIXEL_SIZE * 14, PIXEL_SIZE * 14));
	next1.setFillColor(Color::Transparent);
	bigHouseInterior.addToLocationChanges(next1);

	//Enemies

	//NPCs

}//end of big house interior



void World::setupForest() {
	//obstacles
	this->createBorder(forest);
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
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, forest);
	createLocationRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, forest);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, forest);

	//Enemies
	this->createEnemy("res/Creatures/flower.png", "flower", /*AI_ID*/ 1, 1, 125, 3, Vector2f(22 * PIXEL_SIZE, 8 * PIXEL_SIZE), forest);
	this->createEnemy("res/Creatures/flower.png", "flower", /*AI_ID*/ 1, 1, 100, 2, Vector2f(6 * PIXEL_SIZE, 12 * PIXEL_SIZE), forest);
	this->createEnemy("res/Creatures/flower.png", "flower", /*AI_ID*/ 1, 1, 175, 3, Vector2f(8 * PIXEL_SIZE, 6 * PIXEL_SIZE), forest);
	this->createEnemy("res/Creatures/flower.png", "flower", /*AI_ID*/ 1, 1, 200, 4, Vector2f(3 * PIXEL_SIZE, 18 * PIXEL_SIZE), forest);
	this->createEnemy("res/Creatures/bat.png", "bat", /*AI_ID*/ 5, 1, 50, 1, Vector2f(10 * PIXEL_SIZE, 4 * PIXEL_SIZE), forest);
	this->createEnemy("res/Creatures/bat.png", "Infected Bat", /*AI_ID*/ 3, 1, 80, 3, Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), forest);
	this->createEnemy("res/Creatures/bat.png", "bat", /*AI_ID*/ 2, 1, 50, 1, Vector2f(26 * PIXEL_SIZE, 16 * PIXEL_SIZE), forest);
	this->createEnemy("res/Creatures/sheep.png", "Rabid Sheep", /*AI_ID*/ 3, 1, 360, 5, Vector2f(24 * PIXEL_SIZE, 11 * PIXEL_SIZE), forest);

	//NPCs

}//end of forest

void World::setupForest2() {
	//creating obstacles
	this->createBorder(forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(6 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(12 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 9 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(6 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(11 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(11 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, forest2);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(15 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, forest2);
	
	//Locations changes
	createLocationRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 19 * PIXEL_SIZE), Color::Transparent, forest2);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, forest2);

	//Enemies
	this->createEnemy("res/Creatures/flower.png", "Killer Flower", 1, 1, 175, 3, Vector2f(21 * PIXEL_SIZE, 8 * PIXEL_SIZE), forest2);
	this->createEnemy("res/Creatures/flower.png", "Killer Flower", 1, 1, 175, 3, Vector2f(10 * PIXEL_SIZE, 13 * PIXEL_SIZE), forest2);
	this->createEnemy("res/Creatures/flower.png", "Poison Flower", 1, 1, 200, 4, Vector2f(7 * PIXEL_SIZE, 5 * PIXEL_SIZE), forest2);

	//NPCs

}//end of forest2

void World::setupBeach() {
	//Create obstacles
	this->createBorder(beach);
	//createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Blue, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE - 16, 1 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE + 16, 1 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 2* PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(22 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(15 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(23 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(11 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 19 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(22 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, beach);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, beach);

	//creating location changes
	createLocationRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 0 * PIXEL_SIZE ), Color::Transparent, beach);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 1 * PIXEL_SIZE ), Color::Transparent, beach);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, beach);

	//Enemies
	this->createEnemy("res/Creatures/jellyfish.png", "Jellyfish", 2, 1, 100, 2, Vector2f(18 * PIXEL_SIZE, 17 * PIXEL_SIZE), beach);
	this->createEnemy("res/Creatures/jellyfish.png", "Jellyfish", 3, 1, 100, 2, Vector2f(20 * PIXEL_SIZE, 17 * PIXEL_SIZE), beach);
	this->createEnemy("res/Creatures/jellyfish.png", "Jellyfish", 4, 1, 100, 2, Vector2f(29 * PIXEL_SIZE, 8 * PIXEL_SIZE), beach);
	this->createEnemy("res/Creatures/jellyfish.png", "Jellyfish", 2, 1, 100, 2, Vector2f(25 * PIXEL_SIZE, 12 * PIXEL_SIZE), beach);
	this->createEnemy("res/Creatures/mudkip.png", "Mudkip", 2, 1, 100, 2, Vector2f(6 * PIXEL_SIZE, 16 * PIXEL_SIZE), beach);
	this->createEnemy("res/Creatures/mudkip.png", "Mudkip", 4, 1, 100, 2, Vector2f(2 * PIXEL_SIZE, 7 * PIXEL_SIZE), beach);
	this->createEnemy("res/Creatures/mudkip.png", "Mudkip", 6, 1, 100, 2, Vector2f(19 * PIXEL_SIZE, 1 * PIXEL_SIZE), beach);
	this->createEnemy("res/Creatures/mudkip.png", "Mudkip", 2, 1, 100, 2, Vector2f(7 * PIXEL_SIZE, 2 * PIXEL_SIZE), beach);
	this->createEnemy("res/Creatures/scorpion.png", "Scorpion", 2, 1, 100, 2, Vector2f(28 * PIXEL_SIZE, 1 * PIXEL_SIZE), beach);
	this->createEnemy("res/Creatures/scorpion.png", "Scorpion", 4, 1, 100, 2, Vector2f(22 * PIXEL_SIZE, 6 * PIXEL_SIZE), beach);
	this->createEnemy("res/Creatures/scorpion.png", "Scorpion", 3, 1, 100, 2, Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), beach);

	//NPCs

}//end of beach


void World::setupWaterfall() {
	//creating obstacles
	this->createBorder(waterfall);
	//createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Blue, waterfall);
	createObstacleRectangle(Vector2f(26 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(23 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 11 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(14 * PIXEL_SIZE, 10 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(27 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 6 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(11 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 15 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, waterfall);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, waterfall);

	//creating Locaiton Changes
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, waterfall);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(2 * PIXEL_SIZE + 1, 14 * PIXEL_SIZE), Color::Transparent, waterfall);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 3 * PIXEL_SIZE + 1), Color::Transparent, waterfall);

	//creating enemies
	this->createEnemy("res/Creatures/scorpion.png", "Scorpion", 4, 1, 200, 2, Vector2f(11 * PIXEL_SIZE, 5 * PIXEL_SIZE), waterfall);
	this->createEnemy("res/Creatures/scorpion.png", "Scorpion", 2, 1, 200, 2, Vector2f(4 * PIXEL_SIZE, 7 * PIXEL_SIZE), waterfall);
	this->createEnemy("res/Creatures/bat.png", "Bat", 2, 1, 200, 2, Vector2f(12 * PIXEL_SIZE, 14 * PIXEL_SIZE), waterfall);
	this->createEnemy("res/Creatures/mudkip.png", "Mudkip", 3, 1, 200, 2, Vector2f(5 * PIXEL_SIZE, 14 * PIXEL_SIZE), waterfall);

	//NPCs

}//end of waterfall
void World::setupWFbossRoom() {
	//obstacles
	this->createBorder(WFbossRoom);
	//createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Blue, WFbossRoom);
	createObstacleRectangle(Vector2f(11 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(9 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 11 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(2 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(8 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(6 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(15 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(9 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(15 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(15 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, WFbossRoom);

	//creating locaiton changes
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, WFbossRoom);
	
	//Enemies
	this->createBoss("res/Creatures/bigRedMonster.png", "A Femenist", /*AI_ID*/ 7, /*aiShoot*/ 5, /*Health*/ 360, /*Level*/ 5, /*Location*/ Vector2f(12 * PIXEL_SIZE, 12 * PIXEL_SIZE), WFbossRoom, /*PixelSize*/ Vector2f(80, 80));

	//NPCs

}//end of WFbossRoom

void World::setupTownAroundCastle() {
	//obstacles
	this->createBorder(townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, townAroundCastle);	
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(6 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(7 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 12 * PIXEL_SIZE), Vector2f(22 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(23 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 7 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createObstacleRectangle(Vector2f(12 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	
	//location change
	createLocationRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 19 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, townAroundCastle);
	createLocationRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, townAroundCastle);

	//NPCs
	this->createNPC("res/Creatures/dwarfKnight.png", "Knight of the Palace", "All Hail King Carpenter", /*AI_ID*/1, Vector2f(17 * PIXEL_SIZE, 15 * PIXEL_SIZE), townAroundCastle);
	this->createNPC("res/Creatures/dwarfKnight.png", "Knight of the Palace", "All Hail King Carpenter", /*AI_ID*/1, Vector2f(12 * PIXEL_SIZE, 15 * PIXEL_SIZE), townAroundCastle);
}// end of townAroundCastle

void World::setupPub() {
	//obstacles
	this->createBorder(pub);
	createObstacleRectangle(Vector2f(8 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 6 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 7 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(13 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(15 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(26 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(22 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 6 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(11 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(10 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, pub);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, pub);

	//location change
	createLocationRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, pub);

	//creating NPCs
	this->createNPC("res/Creatures/greenHairGirl.png", "Velma", "I eat pasta for breakfast.", 1, Vector2f(7 * PIXEL_SIZE, 7 * PIXEL_SIZE), pub);
	this->createNPC("res/Creatures/blueHairCloakMan.png", "Rick Sanchez", "*Burp* M..Mm.. Morty, we got, we gotta get to the ship Morty.", 1, Vector2f(9 * PIXEL_SIZE, 7 * PIXEL_SIZE), pub);
	this->createNPC("res/Creatures/merchant.png", "Morty", "Ohh, I don't know Rick...", 1, Vector2f(10* PIXEL_SIZE, 7 * PIXEL_SIZE), pub);
	this->createNPC("res/Creatures/aipronLady.png", "Deborah", "I serve beer and whiskey.", 4, Vector2f(10 * PIXEL_SIZE, 4 * PIXEL_SIZE), pub);
	this->createNPC("res/Creatures/oldMan.png", "Old Man Eugine", "I had to walk 5000 miles to school every day.", 1, Vector2f(5 * PIXEL_SIZE, 10 * PIXEL_SIZE), pub);
	this->createNPC("res/Creatures/blondeGirl.png", "Flower Dancer", "Dance with me!", 3, Vector2f(19 * PIXEL_SIZE, 10 * PIXEL_SIZE), pub);
	this->createNPC("res/Creatures/whiteHairKid.png", "Drunk Doug", "I'm going to hurl!!!", 6, Vector2f(26 * PIXEL_SIZE, 6 * PIXEL_SIZE), pub);
	this->createNPC("res/Creatures/gothGirl.png", "Grape", "I pick grapes.", 5, Vector2f(23 * PIXEL_SIZE, 9 * PIXEL_SIZE), pub);
	this->createNPC("res/Creatures/greenHairGirl.png", "Velma", "", 1, Vector2f(14 * PIXEL_SIZE, 11 * PIXEL_SIZE), pub);
}//end of pub

void World::setupCastle() {
	//obstacles
	this->createBorder(castle);
	createObstacleRectangle(Vector2f(11 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(2 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 13 * PIXEL_SIZE), Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(9 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(11 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(7 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(9 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 11 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 6 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, castle);
	createObstacleRectangle(Vector2f(11 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, castle);
	
	//location change
	createLocationRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, castle);

	//NPCs
	for (int i = 0; i < 6; i++) {
		this->createNPC("res/Creatures/darkKnight.png", "Knight of the Palace", "All Hail King Carpenter", /*AI_ID*/1, Vector2f(12 * PIXEL_SIZE, (14 - i) * PIXEL_SIZE), castle);
	}
	for (int i = 0; i < 6; i++) {
		this->createNPC("res/Creatures/darkKnight.png", "Knight of the Palace", "All Hail King Carpenter", /*AI_ID*/1, Vector2f(17 * PIXEL_SIZE, (14 - i) * PIXEL_SIZE), castle);
	}
	this->createNPC("res/Creatures/king.png", "King Carpenter", "You get an A.", 1, Vector2f(13 * PIXEL_SIZE, 6 * PIXEL_SIZE - 10), castle);
	this->createNPC("res/Creatures/queen.png", "Queenie", "I like to cook eggs.", 1, Vector2f(16 * PIXEL_SIZE, 6 * PIXEL_SIZE - 10), castle);
	this->createNPC("res/Creatures/aipronLady.png", "Cookie", "The guests will be here soon!", 1, Vector2f(8 * PIXEL_SIZE, 6 * PIXEL_SIZE), castle);
	this->createNPC("res/Creatures/merchant.png", "Nervious Wreck", "I am nervious.", 3, Vector2f(8 * PIXEL_SIZE, 4 * PIXEL_SIZE), castle);
	this->createNPC("res/Creatures/greenHairGirl.png", "Sally", "I am setting the table.", 5, Vector2f(22 * PIXEL_SIZE, 8 * PIXEL_SIZE), castle);
}//end of castle

void World::setupMarket() {
	//obstacles
	this->createBorder(market);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 20 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(11 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 19 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(15 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(21 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 16 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(15 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(15 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(6 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(11 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 19 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(22 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, market);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, market);

	//location change
	createLocationRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(2 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, market);
	createLocationRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 19 * PIXEL_SIZE), Color::Transparent, market);

	//NPCs
	this->createNPC("res/Creatures/darkKnight.png", "Sir Eden", "Buy some swords, lad", /*AI_ID*/1, Vector2f(11 * PIXEL_SIZE, 4 * PIXEL_SIZE), market);
	this->createNPC("res/Creatures/darkKnight.png", "Sir Eden II", "Buy some armour, lad", /*AI_ID*/1, Vector2f(13 * PIXEL_SIZE, 4 * PIXEL_SIZE), market);
	this->createNPC("res/Creatures/gothGirl.png", "Mary the Witch", "Double Double Toil and Trouble!", /*AI_ID*/1, Vector2f(17 * PIXEL_SIZE, 4 * PIXEL_SIZE), market);
	this->createNPC("res/Creatures/blondeGirl.png", "Jenny the Jeweler", "I'm So Pretty!", /*AI_ID*/1, Vector2f(22 * PIXEL_SIZE, 4 * PIXEL_SIZE), market);
	this->createNPC("res/Creatures/redHairMan.png", "Lord Farquaad", "Another Day Another Dollar", /*AI_ID*/1, Vector2f(9 * PIXEL_SIZE, 10 * PIXEL_SIZE), market);
	this->createNPC("res/Creatures/whiteHairMan.png", "Thor", "Hammer Hammer", /*AI_ID*/1, Vector2f(16 * PIXEL_SIZE, 10 * PIXEL_SIZE), market);
	this->createNPC("res/Creatures/merchant.png", "Money Bags", "$$$$$$$", /*AI_ID*/1, Vector2f(8 * PIXEL_SIZE, 16 * PIXEL_SIZE), market);
	this->createNPC("res/Creatures/merchant.png", "Jerry Thomson", "Hey How Are You?!", /*AI_ID*/5, Vector2f(2 * PIXEL_SIZE, 8 * PIXEL_SIZE), market);
	this->createNPC("res/Creatures/fireHairGirl.png", "Jenny Thomson", "Watch Out For My Hair, Kid", /*AI_ID*/3, Vector2f(5 * PIXEL_SIZE, 17 * PIXEL_SIZE), market);
	this->createNPC("res/Creatures/aipronLady.png", "Helga the Baker", "Dinner is Served", /*AI_ID*/4, Vector2f(23 * PIXEL_SIZE, 13 * PIXEL_SIZE), market);
	this->createNPC("res/Creatures/greenHairSoldier.png", "Dough Roundface", "This Market Serves No Purpose!", /*AI_ID*/1, Vector2f(25* PIXEL_SIZE, 4 * PIXEL_SIZE), market);
	for (int i = 0; i < 5; i++) {
		this->createNPC("res/Creatures/Sheep.png", "Sheepy", "BAAAAAAAAAA", /*AI_ID*/2, Vector2f(27 * PIXEL_SIZE, (15 + i) * PIXEL_SIZE), market);
	}

}//end of market

void World::setupGraveyard() {
	//obstacles
	this->createBorder(graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 7 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(12 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f((5 * PIXEL_SIZE)-10, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f((6 * PIXEL_SIZE)-10, 1 * PIXEL_SIZE), Vector2f((7 * PIXEL_SIZE)+10, 4 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(22 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(11 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(22 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(8 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 9 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 8 * PIXEL_SIZE), Vector2f(22 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(15 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 13 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(11 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, graveyard);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, graveyard);
	
	//adding enemies
	this->createEnemy("res/Creatures/nun.png", "Crazy Nun", 2, 1, 300, 4, Vector2f(25 * PIXEL_SIZE, 11 * PIXEL_SIZE), graveyard);
	this->createEnemy("res/Creatures/skeleton.png", "Skeleton", 4, 21, 00, 2, Vector2f(26 * PIXEL_SIZE, 2 * PIXEL_SIZE), graveyard);
	this->createEnemy("res/Creatures/skeleton.png", "Withered Skeleton", 4, 1, 400, 6, Vector2f(17 * PIXEL_SIZE, 15 * PIXEL_SIZE), graveyard);
	this->createEnemy("res/Creatures/skeleton.png", "Skeleton", 5, 1, 200, 5, Vector2f(7 * PIXEL_SIZE, 11 * PIXEL_SIZE), graveyard);
	this->createEnemy("res/Creatures/gargoyle.png", "Gargoyle", 3, 1, 200, 4, Vector2f(9 * PIXEL_SIZE, 3 * PIXEL_SIZE), graveyard);
	this->createEnemy("res/Creatures/bat.png", "Decaying Bat", 2, 1, 75, 2, Vector2f(4 * PIXEL_SIZE, 2 * PIXEL_SIZE), graveyard);
	this->createEnemy("res/Creatures/bat.png", "Bat", 2, 1, 50, 2, Vector2f(15 * PIXEL_SIZE, 7 * PIXEL_SIZE), graveyard);
	this->createEnemy("res/Creatures/bat.png", "Vampire Bat", 2, 1, 200, 2, Vector2f(9 * PIXEL_SIZE, 17 * PIXEL_SIZE), graveyard);
	
	//location change
	createLocationRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, graveyard);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 10 * PIXEL_SIZE + 5), Color::Transparent, graveyard);

	//adding NPCs
	
}//end of graveyard

void World::setupGhostShed() {
	//obstacles
	this->createBorder(ghostShed);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 20 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, ghostShed);
	createObstacleRectangle(Vector2f(21 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, ghostShed);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, ghostShed);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, ghostShed);
	createObstacleRectangle(Vector2f(13 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, ghostShed);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, ghostShed);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 14 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, ghostShed);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 7 * PIXEL_SIZE), Vector2f(23 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, ghostShed);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, ghostShed);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(22 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, ghostShed);
	
	//location changes
	createLocationRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, ghostShed);

	//creating enemies
	this->createEnemy("res/Creatures/gargoyle.png", "Gargoyle", 5, 1, 100, 3, Vector2f(8 * PIXEL_SIZE, 9 * PIXEL_SIZE), ghostShed);
	this->createEnemy("res/Creatures/gargoyle.png", "Gargoyle", 3, 1, 100, 3, Vector2f(18 * PIXEL_SIZE, 12 * PIXEL_SIZE), ghostShed);
	this->createEnemy("res/Creatures/gargoyle.png", "Gargoyle", 4, 1, 100, 3, Vector2f(21 * PIXEL_SIZE, 4 * PIXEL_SIZE), ghostShed);
}//end of ghostShed

void World::setupWFcorridor(){
	//obstacles
	this->createBorder(WFcorridor);
	//createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Blue, WFcorridor);
	createObstacleRectangle(Vector2f(9 * PIXEL_SIZE, 5 * PIXEL_SIZE), Vector2f(10 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createObstacleRectangle(Vector2f(13 * PIXEL_SIZE, 9 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createObstacleRectangle(Vector2f(9 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(2 * PIXEL_SIZE, 17 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 17 * PIXEL_SIZE), Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 16 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createObstacleRectangle(Vector2f(26 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 14 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 10 * PIXEL_SIZE), Vector2f(28 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(27 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, WFcorridor);

	//setting up location changes
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, WFcorridor);
	createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 19 * PIXEL_SIZE), Color::Transparent, WFcorridor);

	//making enemies
	this->createEnemy("res/Creatures/bat.png", "Bat", 2, 1, 50, 2, Vector2f(3 * PIXEL_SIZE, 12 * PIXEL_SIZE), WFcorridor);
	this->createEnemy("res/Creatures/bat.png", "Bat", 2, 1, 50, 2, Vector2f(12 * PIXEL_SIZE, 4 * PIXEL_SIZE), WFcorridor);
	this->createEnemy("res/Creatures/bat.png", "Bat", 2, 1, 50, 2, Vector2f(20 * PIXEL_SIZE, 4 * PIXEL_SIZE), WFcorridor);

	//adding NPC
	this->createNPC("res/Creatures/oldMan.png", "Old Man", "There is a big monster down there.", /*AI*/4, Vector2f(19 * PIXEL_SIZE, 4 * PIXEL_SIZE), WFcorridor);
}//end of WFcorridor

void World::setupPort() {
	//Obstacles
	//	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Blue, port);
	this->createBorder(port);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(2 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(3 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(4 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 3 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 8 * PIXEL_SIZE), Vector2f(5 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(6 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 7 * PIXEL_SIZE), Vector2f(7 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(9 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 10 * PIXEL_SIZE), Vector2f(11 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 5 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(16 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 7 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(20 * PIXEL_SIZE, 8 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 9 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(22 * PIXEL_SIZE, 10 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(3 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 11 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(18 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(10 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 14 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 4 * PIXEL_SIZE), Vector2f(25 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(24 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(7 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(17 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(4 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(19 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(21 * PIXEL_SIZE, 4 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(14 * PIXEL_SIZE, 1 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(0 * PIXEL_SIZE, 2 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(1 * PIXEL_SIZE, 0 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 2 * PIXEL_SIZE), Vector2f(29 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 18 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(26 * PIXEL_SIZE, 19 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(5 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(12 * PIXEL_SIZE, 15 * PIXEL_SIZE), Color::Transparent, port);
	createObstacleRectangle(Vector2f(2 * PIXEL_SIZE, 3 * PIXEL_SIZE), Vector2f(13 * PIXEL_SIZE, 12 * PIXEL_SIZE), Color::Transparent, port);

	//location change
	this->createLocationRectangle(Vector2f(1 * PIXEL_SIZE, 1 * PIXEL_SIZE), Vector2f(8 * PIXEL_SIZE, 6 * PIXEL_SIZE), Color::Transparent, port);
	
	//enemies
	for(int i = 0; i < 35; i++){
		this->createEnemy("res/Creatures/sheep.png", "Escaping Sheep", 2, 1, 50, 2, Vector2f(18 * PIXEL_SIZE, 4 * PIXEL_SIZE), port);	
	}
	for (int i = 0; i < 35; i++) {
		this->createEnemy("res/Creatures/sheep.png", "Escaping Sheep", 2, 1, 50, 2, Vector2f(7 * PIXEL_SIZE, 2 * PIXEL_SIZE), port);
	}

	//npcs
	this->createNPC("res/Creatures/oldMan.png", "Really Bad Animal Merchant", "Please slaughter any sheep that tries to escape.", /*AI*/1, Vector2f(9 * PIXEL_SIZE, 7 * PIXEL_SIZE), port);
}//end of port

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

void World::createBorder(Location &loc) {
	//left
	createObstacleRectangle(Vector2f(1, 20 * PIXEL_SIZE), Vector2f(-1, -1), Color::Transparent, loc);
	//right
	createObstacleRectangle(Vector2f(1, 20 * PIXEL_SIZE), Vector2f(30*PIXEL_SIZE, -1), Color::Transparent, loc);
	//up
	createObstacleRectangle(Vector2f(30*PIXEL_SIZE, 1), Vector2f(-1, -1), Color::Transparent, loc);
	//down
	createObstacleRectangle(Vector2f(30 * PIXEL_SIZE, 1 ), Vector2f(-1, 20*PIXEL_SIZE), Color::Transparent, loc);
}

void World::createEnemy(std::string file, std::string name, int AI_ID, int aiShoot, int health, int level, Vector2f startingPosition, Location &loc) {
	Enemy * enemy = new Enemy(file, name, loc.getLocationID(), AI_ID, aiShoot, health, level, startingPosition, loc.getObstacles());
	loc.addToEnemies(enemy);
}

void World::createTestEnemies() {
	for (int i = 0; i < 2; i++) {
		this->createEnemy("res/Creatures/gargoyle.png", "Test", /*AI_ID*/ 1, /*aiShootID*/ 1,/*HP*/10 * i, /*Level*/10000, Vector2f((5 + 3 * i) * PIXEL_SIZE, 2 * PIXEL_SIZE), home);
	}
}

void World::createNPC(std::string file, std::string name, std::string intersectionText, int AI_ID, Vector2f startingPosition, Location &loc) {
	NPC *npc1 = new NPC(file, name, intersectionText, loc.getLocationID(), AI_ID, startingPosition, loc.getObstacles());
	loc.addToNPCs(npc1);
}

void World::createBoss(std::string file, std::string name, int AI_ID, int aiShoot, int health, int level, Vector2f startingPosition, Location &loc, Vector2f pixelSize) {
	Enemy * enemy = new Enemy(file, name, loc.getLocationID(), AI_ID, aiShoot, health, level, startingPosition, loc.getObstacles(), pixelSize);
	loc.addToEnemies(enemy);
}