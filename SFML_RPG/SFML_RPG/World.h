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

		void setupHome(RenderWindow &window);
		void setupBigHouse();
		void setupForest();
		void setupTown();


		void setHome(Location& h);
		Location& getHome();

		Location &getLocation(int requested);
		string getLocationString(int requested);

	private:
		//used to draw obstacles/location changers
		RectangleShape &createRectangle(Vector2f rectSize, Vector2f rectPosition, Color rectColor);

		Location home = *new Location("Home Neighborhood", "res/Locations/home.png", 1, 2, 3, 4,Vector2f(0,0), Vector2f(0, 0), Vector2f(0, 0));
		Location town1 = *new Location("Mill Creek", "res/Locations/Town1.png", 2, 4, 3, 1, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
		Location bigHouseInterior = *new Location("Home Sweet Home", "res/Locations/BigHouseInterior.png", 3, 1, 1, 1, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));
		Location forest = *new Location("Hollow Forest", "res/Locations/Forest1.png", 4, 1, 2, 1, Vector2f(0, 0), Vector2f(0, 0), Vector2f(0, 0));

		//Location graveyard = *new Location("Graveyard", "res/Locations/Graveyard.png");
		//Location dungeon1 = *new Location("Dungeon1", "res/Locations/Dungeon1.png");

};

#endif // !WORLD_H
