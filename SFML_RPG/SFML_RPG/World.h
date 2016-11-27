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

		Location &getLocation(int requested);
		string getLocationString(int requested);

	private:
		//used to draw obstacles/location changers
		void createRectangle(RectangleShape &rectangle, Vector2f rectSize, Vector2f rectPosition, Color rectColor);

		Location home;
		Location town1;
		Location bigHouseInterior;
		Location forest;
		Location graveyard;
		Location dungeon;

};

#endif // !WORLD_H
