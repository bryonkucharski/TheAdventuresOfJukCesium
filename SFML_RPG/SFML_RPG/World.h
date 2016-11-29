#ifndef WORLD_H
#define WORLD_H

#include <vector>
using namespace std;

#include "Location.h"

class World
{
	public:
		World();
		World(RenderWindow &window);
		void drawWorld(RenderWindow &window,Location &toDraw);

		//sets up all rectangles so you can move to a new locations and obstacles.
		void setupHome(RenderWindow &window);
		void setupBigHouse();
		void setupForest();
		void setupTown();
		void setupForest2();
		void setupBeach();
		void setupWaterfall();
		void setupWFbossRoom();
		void setupTownAroundCastle();
		void setupPub();
		void setupCastle();
		void setupMarket();
		void setupGraveyard();
		void setupGhostShed();
		void setupWFcorridor();

		Location &getLocation(int requested);
		string getLocationString(int requested);

	private:
		//used to draw obstacles/location changers
		void createObstacleRectangle(RectangleShape &rectangle, Vector2f rectSize, Vector2f rectPosition, Color rectColor, Location &loc);
		void createLocationRectangle(RectangleShape &rectangle, Vector2f rectSize, Vector2f rectPosition, Color rectColor, Location &loc);
		void createObstacleRectangle(Vector2f rectSize, Vector2f rectPosition, Color rectColor, Location &loc);
		void createLocationRectangle(Vector2f rectSize, Vector2f rectPosition, Color rectColor, Location &loc);
		
		//Keep this in alphabetical order. It helps me with reading the maps and verifying if a map is there or not.
		//Location className; //Description of Location.
		Location beach;// below forest2
		Location bigHouseInterior;//in home
		//Location brokenShackHouse; //in home
		Location castle;// in townAroundCastle
		//Location dungeon;//not used atm.
		//Location farm;// right of market
		Location forest;//left of home
		Location forest2;//left of forest
		Location ghostShed;//in graveyard
		Location graveyard;//below market
		//Location grotto;// right of town
		//Location hermitHouse;//inside grotto
		Location home;// origin position of the map, right of forest, left of town
		//Location inn;//in townAroundCastle
		//Location insideMarketTent;//in market
		Location market;//below town1, above graveyard, left of farm
		//Location port;//left of beach
		//Location portShop;//inside port
		Location pub;// Win townAroundCastle
		//Location smallHouse;// In home
		//Location town1; // right of home, left of grotto, above market
		Location townAroundCastle;// above forest
		//Location townRedHouse;//in town
		//Location townShack;//in town
		Location waterfall; // in beach, WF = waterfall. 
		Location WFbossRoom;// in WFcorridor
		Location WFcorridor;// in waterFall, corridor will also change location to a different part to waterfall.png


};

#endif // !WORLD_H
