#ifndef WORLD_H
#define WORLD_H

#include <vector>

#include "Location.h"
class World
{
	public:
		World(RenderWindow &window);
		void drawWorld(RenderWindow &window);

		void setupHome(RenderWindow &window);
		void setHome(Location& h);
		Location& getHome();

	private:
		Location home;
		
};

#endif // !WORLD_H
