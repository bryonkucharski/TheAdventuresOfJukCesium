#ifndef WORLD_H
#define WORLD_H

#include <vector>
using namespace std;

#include "Location.h"

class World
{
	public:
		World(RenderWindow &window);
		void drawWorld(RenderWindow &window,Location &toDraw);

		void setupHome(RenderWindow &window);


		void setHome(Location& h);
		Location& getHome();

		Location &getLocation(int requested);

	private:
		Location home = *new Location("Home Sweet Home", "res/Locations/home.png", 0, 1, 1, 1);
		//Location graveyard = *new Location("Graveyard", "res/Locations/Graveyard.png");
		//Location forest = *new Location("Forest1", "res/Locations/Forest1.png");
		Location town1 = *new Location("Town1", "res/Locations/Town1.png", 1, 0, 0, 0);
		//Location bigHouseInterior = *new Location("BigHouseInterior", "res/Locations/BigHouseInterior.png");
		//Location dungeon1 = *new Location("Dungeon1", "res/Locations/Dungeon1.png");
		//homePointer = &home;
};

#endif // !WORLD_H
